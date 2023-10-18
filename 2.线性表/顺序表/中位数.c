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

// 两个等长序列的中位数
// 时间复杂度：O(n) 空间复杂度：O(1)
int Median(int A[],int B[],int n)
{
    int s1=0,s2=0,d1=n-1,d2=n-1,m1,m2;
    while(s1!=d1||s2!=d2)
    {
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if(A[m1]==B[m2])    return A[m1];
        if(A[m1]<B[m2])
        {
            if((s1+d1)%2==0)
            {
                s1=m1;
                d2=m2;
            }else{
                s1=m1+1;
                d2=m2;
            }
        }else{
            if((s2+d2)%2==0)
            {
                d1=m1;
                s2=m2;
            }else{
                d1=m1;
                s2=m2+1;
            }    
        }        
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}

int main()
{
    int A[] = {3,4,5,6,7,8,77,88,99};
    int B[] = {1,2,3,4,5,6,7,8,9};
    printf("两个数组的中位数：%d",Median(A,B,9));
    return 0;
}