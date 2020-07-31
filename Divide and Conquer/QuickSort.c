#include<stdio.h>
#include<stdlib.h>

void quickSort(int arr[],int l,int h);
int partition(int arr[],int l,int h);

int main()
{
	int *arr,n,i;

	printf("\nEnter the size of array:");
	scanf("%d",&n);

	//dynamically allocating array size

	arr=(int*)malloc(sizeof(int)*(n+1));

	printf("\nEnter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}

	arr[n]=100000;

	quickSort(arr,0,n);

	printf("\nSorted elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(arr+i));
	}

	return 0;
}

void quickSort(int arr[],int l,int h)
{
	int j;

	if(l<h)
	{
		j=partition(arr,l,h);
		quickSort(arr,l,j);
		quickSort(arr,j+1,h);
	}
}

int partition(int arr[],int l,int h)
{
	int pivot=arr[l],i,j,temp;

	i=l;
	j=h;

	while(i<j)
	{
		do
		{
			i++;
		}while(arr[i]<=pivot);

		do
		{
			j--;
		}while(arr[j]>pivot);
		if(i<j)
		{
			temp=arr[j];  //replacing both numbers
			arr[j]=arr[i];
			arr[i]=temp;
		}	
	}
		temp=arr[j];  //replacing both numbers
		arr[j]=arr[l];
		arr[l]=temp;

	return j;	
}