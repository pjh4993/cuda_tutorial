#include "vector_sum.hpp"
#include <cstdio>

#define N 10

int vector_sum(void){
    int a[N], b[N], c[N];
    for (int i=0; i<N; i++){
        a[i] = -i;
        b[i] = i * i;
    }

    add<int>(a, b, c, N);

    for (int i=0; i<N; i++){
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }

    return 0;
}
