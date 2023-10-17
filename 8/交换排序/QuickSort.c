#include<stdio.h>

int Partition(int A[],int low,int high)
{
    int pivot=A[low];
    while (low<high)
    {
        while (low<high && A[high]>=pivot) --high;
        A[low]=A[high];
        while (low<high && A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickStort(int A[],int low,int high)
{

    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickStort(A,low,pivotpos-1);
        QuickStort(A,pivotpos+1,high);
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
    int A[] = {2,5,8,1,4,3,6,7};
    int n = sizeof(A) / sizeof(A[0]);
    QuickStort(A, 0, n - 1);
    printArray(A, n);

}
