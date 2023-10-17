#include<stdio.h>

// 希尔排序
void ShellSort(int A[],int n){
    int dk,i,j;
    for(dk=n/2;dk>0;dk/=2){
        for(i=dk;i<n;i++){
            if(A[i]<A[i-dk]){   // dk增量
                A[0]=A[i];
                for (j=i-dk;j>=0&&A[j]>A[0];j-=dk)
                {
                    A[j+dk]=A[j];
                }
                A[j+dk]=A[0];
            }
        }
    }       
}

void printArray(int A[], int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    // 04 13 27 38 49 49 55 65 76 97 
    int A[] = {49,38,65,97,76,13,27,49,55,04};
    int n = sizeof(A) / sizeof(A[0]);
    ShellSort(A, n);
    printArray(A, n);
    return 0;
}
