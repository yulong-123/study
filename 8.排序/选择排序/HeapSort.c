#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 打印输出
void PrintArray(int A[], int n){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 交换数组元素
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void HeadAdjust(int A[], int k, int len)
{
    int i;
    A[0] = A[k];
    for (i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && A[i] < A[i + 1])   i++;
        if (A[0] >= A[i]) break;
        else{
            A[k] = A[i];
            k=i;
        }
    }
    A[k] = A[0];
}

// 建堆
void BuildHeap(int A[], int len)
{
    int i;
    for (i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len);
    }
}

// 堆排序
void HeapSort(int A[], int len)
{
    int i;
    BuildHeap(A, len);
    for (i = len; i > 1; i--)
    {
        Swap(&A[i],&A[1]);
        HeadAdjust(A,1,i-1);
    }
}

int main()
{
    int A[] = {32,45,78,9,17,87,65,53};
    int len = sizeof(A) / sizeof(A[0]);
    HeapSort(A, len);
    PrintArray(A, len);
    return 0;
}