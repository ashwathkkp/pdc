#include <stdio.h>
#include "omp.h"
#define swap(a,b,type) {type tt=a; a=b; b=tt;}

int main() {
        int n;
        scanf("%d",&n);
        int input[n];
        for(int i=0;i<n;i++)
                scanf("%d", &input[i]);
        double start,end;
        start=omp_get_wtime();
        #pragma omp parallel
        {
                for(int i=0; i<n-1; i++) {
                        #pragma omp parallel
                        {
                                for(int j=i+1; j<n; j++) {
                                        if(input[i] > input[j])
                                                swap(input[i], input[j], int);
                                }
                        }
                }
        }
        end=omp_get_wtime();
        printf("-------------------------\nTime Parallel= %f",(end-start));
        printf("\nSorted result is \n");
        for(int i=0;i<n;i++)
                printf("%d ", input[i]);
        printf("\n");
        return 0;
}