#include "../common/util.h"
#include "cuda_runtime.h"

template<typename T>
__global__ void add( T *a, T *b, T  *c){
    int tid = blockIdx.x;a
    if (tid < N)
        c[tid] = a[tid] + b[tid]
}

template<typename T>
void add(T *a, T *b, T *c, T N){
    T *dev_a, *dev_b, *dev_c;
    //allocate the memory on the GPU
    HANDLE_ERROR( cudaMalloc( (void**)&dev_a, N * sizeof(T)) );
    HANDLE_ERROR( cudaMalloc( (void**)&dev_b, N * sizeof(T)) );
    HANDLE_ERROR( cudaMalloc( (void**)&dev_c, N * sizeof(T)) );

    HANDLE_ERROR( cudaMemcpy( dev_a, a, N * sizeof(T), cudaMemcpyHostToDevice ) );
    HANDLE_ERROR( cudaMemcpy( dev_a, a, N * sizeof(T), cudaMemcpyHostToDevice ) );
    HANDLE_ERROR( cudaMemcpy( dev_a, a, N * sizeof(T), cudaMemcpyHostToDevice ) );

    add<<<N,1>>>(dev_a, dev_b, dev_c);

    HANDLE_ERROR( cudaMemcpy( c, dev_c, N * sizeof(T), cudaMemcpyDeviceTOHost ));
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
}