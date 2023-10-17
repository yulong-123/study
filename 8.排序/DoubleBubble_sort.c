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

// 双向冒泡排序
void DoubleBubble_sort(int A[], int n)
{
    int low=0,high=n-1,i;
    bool flag = true;
    while(low<high&&flag){
        flag = false;
        for (i = low; i < high; i++)
            if (A[i] > A[i+1]){
                Swap(&A[i], &A[i+1]);
                flag=true;
            }
            high--;
            for (i = high; i > low; i--)
                if (A[i] < A[i-1]){
                    Swap(&A[i], &A[i-1]);
                    flag=true;
                }
            low++;
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
    DoubleBubble_sort(A, n);
    printArray(A, n);
    return 0;
}