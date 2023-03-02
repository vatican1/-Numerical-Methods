#include <math.h>
#include <iostream>

float length(const float* x, int n){
    float max_ = x[0];
    float sq_sum = 1; 
    for (int i = 1; i < n; ++i)
    {
        if(abs(x[i]) > max_)
        {
            float prev_max = max_;
            max_ = abs(x[i]);
            float correction = prev_max / max_ * prev_max / max_;
            sq_sum *= correction;
            sq_sum += 1;
        }
        else
        {
            sq_sum += x[i] / max_ * x[i] / max_  ;
        }
    }
    return std::sqrt(sq_sum) * max_;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    float x[n];
    std::cout << "sqrt(";
    for(int i = 0; i < n; ++i)
    {
        x[i] = atof(argv[i + 2]);
        std::cout << x[i] << "^2";
        if(i != n-1) std::cout << " + ";
    }
    std::cout << ") = ";
    std::cout << length(x, n) << std::endl;
}