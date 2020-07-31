#include<stdio.h>
#include<stdlib.h>

int linearSearch(int N,int arr[],int key);

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

    result=linearSearch(N,arr,key);

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

int linearSearch(int N,int arr[],int key)
{
    int i;

    for(i=0;i<N;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

