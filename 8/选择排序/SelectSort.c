#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// 交换数组元素
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectSort(int A[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        int min = i;
        for(j=i+1;j<n;j++)
            if(A[j]<A[min]) min = j;
        if(min!=i) Swap(&A[min],&A[i]);    
    }
}

// 打印输出
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
    int A[] = {5,3,2,1,4};
    int n = sizeof(A)/sizeof(A[0]);
    SelectSort(A,n);
    printArray(A,n);
    return 0;
}