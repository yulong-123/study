#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 交换数组元素
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;*a = *b;*b = temp;
}

// 数组逆置
void ReverseArray(int A[], int n){
    int i;
    for(i = 0; i < n / 2; i++)  Swap(&A[i], &A[n - i - 1]);
}

// 打印输出
void PrintArray(int A[], int n){
    int i;
    for (i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

// 自定义 起止 数组逆置
void Reverse(int A[],int from,int to){
    int i,tmep;
    for(i=0;i<(to-from+1)/2;i++){
        Swap(&A[from+i],&A[to-i]);
    }
}

// 循环左移
// 时间复杂度：O(n) 空间复杂度：O(1)
void Converse(int A[], int n, int p)
{
    Reverse(A, 0, p - 1);
    Reverse(A, p, n - 1);
    Reverse(A, 0, n - 1);
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(A) / sizeof(A[0]);
    Converse(A, 5,6);
    PrintArray(A, n);
    return 0;
}