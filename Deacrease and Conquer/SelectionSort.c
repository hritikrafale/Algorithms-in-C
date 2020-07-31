#include<stdio.h>
#include<stdlib.h>

void selectionSort(int n,int arr[]);

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

    selectionSort(N,arr);

    printf("\nSorted array is :");
    for(i=0;i<N;i++)
    {
        printf("%d ",*(arr+i));
    }
    
    return 0;
}

void selectionSort(int n,int arr[])
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp ;
    }
}

