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
// 数组 主元素
int Majority(int A[], int n) 
{
    int i,c,count=1;
    c=A[0];
    for(i=1;i<n;i++)
        if(A[i]==c) count++;
        else if (count>0) count--;
        else 
        {
            c=A[i];
            count=1;
        }
    if(count>0)
        for(i=count=0;i<n;i++)
            if(A[i]==c) count++;
    if(count>n/2) return c;
    else return -1;
}
int main()
{
    int A[] = {1, 2, 2, 4, 2};
    int n = sizeof(A) / sizeof(A[0]);
    int majorNum = Majority(A, n);
    if(majorNum != -1)    printf("数组主元素为：%d\n", majorNum);
    else printf("数组不存在主元素\n");
    return 0;
}