/*
    This code is for finding Max Sum in a subarray

    This code is following divide and conquer approach

    Time complexity of this code is O(nlogn)

*/

#include<stdio.h>
#include<stdlib.h>

int maxSumSubarray(int arr[],int low,int high);
int max(int L,int C,int R);
int combineSum(int arr[],int low,int mid,int high);

int main()
{
    int *arr,n,i;

    printf("\nEnter the size of the array:");
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);

    printf("\nEnter the elements into the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("\nMax sum sub array is :%d",maxSumSubarray(arr,0,n-1));

    return 0;
}

int maxSumSubarray(int arr[],int low,int high)
{
    if(low==high)
    {
        return arr[low];
    }
    else
    {
        int L,C,R,mid;

        mid=(low+high)/2;

        L=maxSumSubarray(arr,low,mid);
        R=maxSumSubarray(arr,mid+1,high);
        C=combineSum(arr,low,mid,high);

        printf("\nlow:%d high:%d mid:%d L:%d R:%d C:%d",low,high,mid,L,R,C);

        return max(L,C,R);
    }
}

int max(int L,int C,int R)
{
    return (L>C)?((L>R)?L:R):((C>R)?C:R);
}

int combineSum(int arr[],int low,int mid,int high)
{
    int left_sum=-1000,right_sum=-10000,i,temp=0;

    for(i=mid;i>=low;i--)
    {
        temp+=arr[i];

        if(left_sum<temp)
        {
            left_sum=temp;
        }
    }

    temp=0;
    for(i=mid+1;i<=high;i++)
    {
        temp+=arr[i];

        if(right_sum<temp)
        {
            right_sum=temp;
        }
    }
    
    return left_sum+right_sum;

}