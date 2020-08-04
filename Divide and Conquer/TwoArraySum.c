/*
    This question is for finding a pair one from each from two given unsorted array which is equal to a key that is given.
    This Solution is of time complexity O(n(logn))
*/

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int mid,int high);
void mergeSort(int arr[],int low,int high);
void sumPair(int arr1[],int size1,int arr2[],int size2,int key);

int main()
{
    int *arr1,size1,*arr2,size2,i,key;

    printf("\nEnter the size of Array 1 :");
    scanf("%d",&size1);

    arr1=(int*)malloc(sizeof(int)*size1);

    printf("\nEnter the size of Array 2 :");
    scanf("%d",&size2);

    arr2=(int*)malloc(sizeof(int)*size2);

    printf("\nEnter the elements in the array 1:");
    for(i=0;i<size1;i++)
    {
        scanf("%d",arr1+i);
    }

    printf("\nEnter the elements in the array 2:");
    for(i=0;i<size2;i++)
    {
        scanf("%d",arr2+i);
    }

    printf("\nEnter the key:");
    scanf("%d",&key);
    
    sumPair(arr1,size1,arr2,size2,key);

    return 0;
}

void merge(int arr[],int low,int mid,int high)
{
    int *arr1,*arr2,i,j,k,n1=mid-low+1,n2=high-mid;

    arr1=(int*)malloc(sizeof(int)*n1);
    arr2=(int*)malloc(sizeof(int)*n2);

    for(i=0;i<n1;i++)
        arr1[i]=arr[low+i];

    for(j=0;j<n2;j++)
        arr2[j]=arr[mid+1+j];

    i=0,k=low,j=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]>arr2[j])
        {
            arr[k]=arr2[j];
            j++;
        }
        else
        {
            arr[k]=arr1[i];
            i++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k++]=arr1[i++];
    }

    while(j<n2)
    {
        arr[k++]=arr2[j++];
    }
    
}

void mergeSort(int arr[],int low,int high)
{
    int mid;

    if(low<high)
    {
        mid=low+(high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void sumPair(int arr1[],int size1,int arr2[],int size2,int key)
{
    int low=0,high=size2-1,i;

    mergeSort(arr1,0,size1-1);
    mergeSort(arr2,0,size2-1);

    while(low!=size1 && high!=-1)
    {
        if(arr1[low]+arr2[high]==key)
        {
            printf("\narr1:%d arr2:%d sum=%d",arr1[low],arr2[high],arr1[low]+arr2[high]);
            low++;
        }
        else
        if(arr1[low]+arr2[high]>key)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}

