#!/bin/bash
g++ 4.cpp -o task4 -O3 -march=native -fopenmp
g++ generate_random.cpp -o random
./task4 7 1.3 1.3 1.3 1.3 1.3 1.3 1.3
./random 10000 | xargs ./task4


