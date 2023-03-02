#include <iostream>
#include <cmath>
#include <stdio.h>

// a_0 + x(a_1 + x(a_2 + xa_3))) n=3
float polynomial (float x, const float* a, int n)
{
    float p = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        p = std::fma(x, p, a[i]);
    }
    return p;
}

int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cout << "arguments: (double)x size_t(n) a_0 a_1 ... a_n" << std::endl
        << "calc: a_0 + a_1 * x + ... a_n * x ^ (n -1)" << std::endl; 
        return 0;
    }
    float x = atof(argv[1]);
     std::cout << "x = " << x << std::endl;
    size_t n = atoi(argv[2]);
    float a[n];
    for(size_t i = 0; i < n + 1; ++i) 
    {
        a[i] = atof(argv[3 + i]);
        std::cout << a[i] << " * x^" << i;
        if(i != n) std::cout << " + ";
    }
    std::cout << std::endl;
    std::cout << polynomial(x, a, n) << std::endl;
    return 0;
}
