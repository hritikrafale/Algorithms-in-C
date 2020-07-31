#include<stdio.h>
#include<stdlib.h>

void insertionSort(int n,int arr[]);
int binarySearch(int arr[],int key,int low,int high);

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
    int i,j,key,loc;

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        loc=binarySearch(arr,key,0,j);
        while(j>=loc)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int binarySearch(int arr[],int key,int low,int high)
{
    if(high<=low)
        return (key>arr[low])?low+1:low;

    int mid=(low+high)/2;

    if(arr[mid]==key)
    {
        return mid+1;
    }

    if(arr[mid]>key)
        return binarySearch(arr,key,low,mid-1);
    return binarySearch(arr,key,mid+1,high);    
}