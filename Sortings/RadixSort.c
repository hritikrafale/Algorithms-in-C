#include<stdio.h>

int max(int arr[],int size);
void countingSort(int arr[],int size,int exp);
void radixSort(int arr[],int size);

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66,179},size=9,i; 

    radixSort(arr,size); 

    printf("\nSorted array is : ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

int max(int arr[],int size)
{
    int i,max=arr[0];

    for(i=1;i<size;i++)
    {
        max=(arr[i]>max)?arr[i]:max;
    }

    return max;
}

void countingSort(int arr[],int size,int exp)
{
    int memory[10]={0},i,memory_size=10,output[size];

    for(i=0;i<size;i++)
    {
        memory[(arr[i]/exp)%10]++;
    }

    for(i=1;i<memory_size;i++)
    {
        memory[i]=memory[i]+memory[i-1];
    }

    for(i=size-1;i>-1;i--)
    {
        output[memory[(arr[i]/exp)%10]-1]=arr[i];
        memory[(arr[i]/exp)%10]--;
    }

     for (i = 0; i < size; i++) 
        arr[i] = output[i]; 

}

void radixSort(int arr[],int size)
{
    int i,m;

    m=max(arr,size);

    for(i=1;m/i>0;i*=10)
    {
        countingSort(arr,size,i);
    }
}