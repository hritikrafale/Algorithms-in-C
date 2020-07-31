#include<stdio.h>
#include<stdlib.h>

void insertionSort(int n,int arr[]);

int main()
{
    int N,*arr,i;

    printf("\nEnter the size of the array:");
    scanf("%d",&N);

    arr=(int*)malloc(sizeof(int)*N);

    printf("\nEnter the array elements:");
    for(i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    insertionSort(N,arr);

    printf("\nSorted array is :");
    for(i=0;i<N;i++)
    {
        printf("%d ",*(arr+i));
    }
    
    return 0;
}

void insertionSort(int n,int arr[])
{
    int i,key;

    if(n==1)
    {
        return ;
    }
    else
    {
        insertionSort(n-1,arr);
        i=n-2;
        key=arr[n-1];
        while(i>-1 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}

