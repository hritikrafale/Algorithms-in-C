/*
    This code is for finding Max Sum in a subarray

    This code is following dynamic programming approach

    Time complexity of this code is O(n^2)

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
    int i,j,k,max=-10000,sum;

    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=arr[j];

            if(sum>max)
                max=sum;
        }
    }

    return max;
}