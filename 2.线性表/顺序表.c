#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*  静态分配
#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int length;
}SqList;
*/

/*  动态分配
#define InitSize 100
typedef struct
{
    int *data;
    int MaxSize,length;
}SeqList;
*/

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int length;
}SqList;

// 顺序表插入
bool ListInsert(SqList L, int i, int e)
{
    int j;
    if(i<1 || i>L.length+1) return false;
    if(L.length >= MaxSize) return false;
    for(j = L.length;j>=i;j--) L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
    
}

// 顺序表删除
bool ListDelete(SqList L, int i, int e)
{
    int j;
    if(i<1 || i>L.length+1) return false;
    e=L.data[i-1];
    for(j=i;j<L.length;j++) L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

// 顺序查找
int LocateElem(SqList L, int e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e) return i+1;
    return 0;
}

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


// 插入
int insert()
{
    SqList L;
    int i,e[]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(e)/sizeof(e[0]);
    for(i=0;i<n;i++)
        ListInsert(L, i, e[i]);
    PrintArray(L.data, L.length);
}

int main()
{
    insert();
    return 0;
}