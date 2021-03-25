#include <iostream>
#include <cstdio>
#include "cuda_runtime.h"

using namespace std;

void handle_error_v1(cudaError_t ce){
    printf("%s\n", cudaGetErrorName(ce));
    switch(ce){
        case cudaSuccess :
            break;
        case cudaErrorInvalidValue :
            break;
        case cudaErrorMemoryAllocation :
            break;
    }
}