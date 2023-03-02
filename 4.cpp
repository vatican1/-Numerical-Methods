#include <iostream>
#include <time.h> 

float sum_accum(float* x, int n)
{
    float sum = 0;
    for(int i = 0; i < n; ++i) sum += x[i];
    return sum;
}

float pairwise_sum_simd(float* x, int n)
{
    int k = 2;
    while (k <= 2 * n)
    {
        #pragma omp simd
        for(int i = 0; i < n; i += k)
        {
            if(i + k / 2 < n) x[i] += x[i + k / 2];
        }
        k *= 2;
    }

    return x[0];
}

int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cout << "arguments: (int) n x_0 x_1 .. x_{n-1}" << std::endl
        << "calc: x_1 + x_2 + ... + x_{n-1}" << std::endl; 
        return 0;
    }
    int n = atoi(argv[1]);
    float x[n];
    for(int i = 0; i < n; ++i) x[i] = atof(argv[i + 2]);
    double sum1, sum2;
{
    clock_t begin = clock();
    float sum = sum_accum(x, n);
    clock_t delta = clock() - begin;
    std::cout << "sum_accum time = " << delta << ", sum_accum return = " << sum << std::endl;
    sum1 = sum;
}
{
    clock_t begin = clock();
    float sum = pairwise_sum_simd(x, n);
    clock_t delta = clock() - begin;
    std::cout << "pairwise_sum_simd time = " << delta << ", pairwise_sum_simd return = " << sum << std::endl;
    sum2 = sum;
}
     std::cout << "delta - " << sum2 - sum1 << std::endl << std::endl;
    return 0;
}
