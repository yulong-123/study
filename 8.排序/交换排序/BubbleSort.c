#include<stdio.h>
#include<stdbool.h>

// 交换数组元素
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void Bubble_sort(int A[], int n)
{
    int i,j;
    bool flag;
    for (i=0; i < n-1; i++){
        flag = false;
        for (j = n-1; j > i; j--)
            if (A[j-1] > A[j]){
                Swap(&A[j-1], &A[j]);
                flag=true;
            }
        if(flag==false)
            return;
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
    int A[] = {5,3,4,2,1};
    int n = sizeof(A) / sizeof(A[0]);
    Bubble_sort(A, n);
    printArray(A, n);
    return 0;
}