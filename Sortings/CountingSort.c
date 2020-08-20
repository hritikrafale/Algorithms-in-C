#include<stdio.h>

void countingSort(int size,int arr[],int sorted_arr[]);

int main()
{
    int arr[]={6,0,2,0,1,3,4,6,1,3,2},size=11,i,sorted_arr[11];

    countingSort(size,arr,sorted_arr);

    printf("\nSorted array is:");
    for(i=0;i<size;i++)
    {
        printf("%d ",sorted_arr[i]);
    }

    return 0;
}

void countingSort(int size,int arr[],int sorted_arr[])
{
    int memory[7]={0},i,memory_size=7;

    for(i=0;i<size;i++)
    {
        memory[arr[i]]++;
    }

    for(i=1;i<memory_size;i++)
    {
        memory[i]=memory[i]+memory[i-1];
    }

    for(i=size-1;i>-1;i--)
    {
        sorted_arr[memory[arr[i]]]=arr[i];
        memory[arr[i]]--;
    }
}