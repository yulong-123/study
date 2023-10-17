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

// 打印输出
void PrintArray(int A[], int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


void Merge(int A[],int low,int mid,int high)
{
    int i,j,k;
    int B[high - low +1];
    for (k = low; k <= high; k++)   B[k] = A[k];
    for (i = low,j = mid+1,k = i; i <= mid && j <= high; k++){
        if(B[i] <= B[j])    A[k] = B[i++];
        else    A[k] = B[j++];
    }
    while(i<=mid)    A[k++] = B[i++];
    while(j<=high)    A[k++] = B[j++];
}

void MergeSort(int A[],int low,int high)
{
    // int *B = (int *)malloc((high - low +1)*sizeof(int));
    if(low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

int main()
{
    int A[] = {2,5,1,3,4,6,7,8,9};
    int n = sizeof(A) / sizeof(A[0]);
    // int* B = (int *)malloc((n+1)*sizeof(int));  /*sizeof不能在函数内部使用*/
    MergeSort(A,0,n-1);
    PrintArray(A,n);
    return 0;
}