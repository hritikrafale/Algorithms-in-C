/*
    This code is for finding Max Sum in a subarray

    This code is following dynamic programming approach

    Time complexity of this code is O(n)

*/
#include<stdio.h>
#include<stdlib.h>

int maxSumSubarray(int n,int arr[]);

int main()
{
    int *arr,n,i;

    printf("\nEnter the size of the array:");
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("\nMax sum sub array is :%d",maxSumSubarray(n,arr));

    return 0;
}

int maxSumSubarray(int n,int arr[])
{
    int i,max,max_so_far;

    max=arr[0],max_so_far=arr[0];
    for(i=1;i<n;i++)
    {
        max_so_far=(max_so_far+arr[i]>arr[i])?max_so_far+arr[i]:arr[i];
        max=(max_so_far>max)?max_so_far:max;
    }

    return max;
}