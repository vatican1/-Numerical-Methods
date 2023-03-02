#include <iostream>

float kahan_sum(const float * x, int n)
{
	float s = 0;
    float c = 0;
    float y;
    float t;
	for (int i = 0; i < n; ++i){
		  y = x[i] - c;
		  t = s + y;
		  c = (t - s) - y;
		  s = t;
	}
	return s;
}

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    float x[n];
    for(int i = 0; i < n; ++i)
    {
        float curr = atof(argv[i + 2]);
        x[i] = curr;
        std::cout << curr;
        if(i != n - 1) std::cout << " + ";
    }
    std::cout << " = " <<  kahan_sum(x, n) << std::endl;
    
}