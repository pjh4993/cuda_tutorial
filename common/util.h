#ifndef UTIL_HDR
#define UTIL_HDR
#include "cuda_runtime.h"

#define HANDLE_ERROR (handle_error_v1)

void handle_error_v1(cudaError_t ce);

#endif