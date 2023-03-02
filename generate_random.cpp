#include <cstdlib>
#include <iostream>
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    std::cout << n << " ";
    for(int i = 0; i < atoi(argv[1]); ++i){
        std::cout << (float)std::rand() / 1000000.0 << " ";
    }
    std::cout << std::endl;
    return 0;
}