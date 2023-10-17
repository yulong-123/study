#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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

// 数组中未出现的最小正整数
int FindMissMin(int A[],int n)
{
    int i,*B;
    B = (int *)malloc(n * sizeof(int));
    memset(B, 0, n * sizeof(int)); // memset()为string.h库函数
    for(i=0;i<n;i++)
        if(A[i]>0 && A[i]<=n)   B[A[i]-1]=1;
    for(i=0;i<n;i++)
        if(B[i]==0) break;
    return i+1;
}// 时间复杂度：O(n) 空间复杂度：O(n)

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    printf("最小正整数为：%d\n", FindMissMin(A, n));
    return 0;
}