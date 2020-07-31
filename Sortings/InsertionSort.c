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
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while((j>-1)&&(arr[j]>key))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

