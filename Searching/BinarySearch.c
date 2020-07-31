#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int key,int low,int high);

int main()
{
    int N,*arr,i,result,key;

    printf("\nEnter the size of the array:");
    scanf("%d",&N);

    arr=(int*)malloc(sizeof(int)*N);

    printf("\nEnter the array elements:");
    for(i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }

    printf("\nEnter the key to be searched:");
    scanf("%d",&key);

    result=binarySearch(arr,key,0,N-1);

    if(result==-1)
    {
        printf("\nElement not found!!!");
    }
    else
    {
        printf("\nElement found at index %d",result);
    }
    
    return 0;
}

int binarySearch(int arr[],int key,int low,int high)
{   
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(key>arr[mid])
        {
            low=mid+1;
        }
        else
        if(key<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

