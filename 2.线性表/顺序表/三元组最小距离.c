#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
// #define min(a,b,c) (a<=b && a<=c) ? 1 : 0; 避免使用宏定义
#define INT_MAX 0x7fffffff

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
// 绝对值
int abs(int a)
{
    if(a<0) return -a;
    return a;
}
bool min(int a,int b,int c)
{
    if(a<=b && a<=c) return true;
    return false;
}
// 三元组 最小距离
int FindMinofTrip(int A[],int n,int B[],int m,int C[],int p)
{
    int i=0,j=0,k=0,D_min=INT_MAX,D;
    while(i<n && j<m && k<p && D_min>0)
    {
        D=abs(A[i]-B[j])+abs(B[j]-C[k])+abs(C[k]-A[i]);
        if(D<D_min) D_min=D;    
        if(min(A[i],B[j],C[k])) i++;    // 避免在函数中使用宏定义
        else if (min(B[j],C[k],A[i])) j++;
        else k++;
    }
    return D_min;
}// 时间复杂度：O(n) 空间复杂度：O(1)

int main()
{
    int A[] = {-1,2,9};
    int B[] = {-25,-10,10,11};
    int C[] = {2,9,17,30,41};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int p = sizeof(C) / sizeof(C[0]);
    printf("三元组最小距离为%d\n", FindMinofTrip(A, n, B, m, C, p));

    return 0;
}