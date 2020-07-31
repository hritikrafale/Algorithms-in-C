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

    if(low<=high)
    {
        mid=(high+low)/2;

        if(arr[mid]==key)
            return mid;
        else
        if(arr[mid]<key)
            return binarySearch(arr,key,mid+1,high);
        else
            return binarySearch(arr,key,low,mid-1);
    }
    return -1;            
}

