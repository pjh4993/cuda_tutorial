void add(int *a, int *b, int *c, int N){
    int tid = 0;
    while(tid < N){
        c[tid] = a[tid] + b[tid];
        tid += 1;
    }
}