#include<stdio.h>

// 直接插入排序
void InsertSort(int A[], int n)
 {
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if(A[i]<A[i-1]){
            A[0]=A[i];
            for (j = i-1; A[0]<A[j]; --j)
            {
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
    }
 }

// 折半插入排序
void InsertSort2(int A[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        A[0]=A[i];
        low=1;
        high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if(A[mid]>A[0])
                high=mid-1;
            else 
                low = mid+1;
        }
        for (j = i-1; j >= high+1; --j)
        {
            A[j+1]=A[j];
        }
        A[high+1]=A[0];
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


int main(){
    int a[]={49,38,65,97,76,13,27,49};
    printArray(a,8);
    // InsertSort(a,8);
    // printArray(a,8);
    InsertSort2(a,8);
    printArray(a,8);
    return 0;
}
