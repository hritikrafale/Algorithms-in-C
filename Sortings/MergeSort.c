#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[],int l,int h);
void merge(int arr[],int l,int mid,int h);

int main()
{
	int *arr,n,i;

	printf("\nEnter the size of array:");
	scanf("%d",&n);

	//dynamically allocating array size

	arr=(int*)malloc(sizeof(int)*n);

	printf("\nEnter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}

	mergeSort(arr,0,n-1);

	printf("\nSorted elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(arr+i));
	}	

	return 0;
}

void mergeSort(int arr[],int l,int h)
{
	int mid;

	if(l<h)
	{
		mid=l+(h-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}
}

void merge(int arr[],int l,int mid,int h)
{	
	int i,j,k,n1=mid-l+1,n2=h-mid,arr1[n1],arr2[n2];

	for (i = 0; i < n1; i++) 
        arr1[i] = arr[l + i];

    for (j = 0; j < n2; j++) 
        arr2[j] = arr[mid+1+j]; 

    i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		if(arr1[i]<arr2[j])
			arr[k++]=arr1[i++];
		else
			arr[k++]=arr2[j++];
	}

	while(i<n1)
		arr[k++]=arr1[i++];

	while(j<n2)
		arr[k++]=arr2[j++];

}