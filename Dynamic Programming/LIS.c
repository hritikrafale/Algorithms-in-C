#include<stdio.h>
#include<stdlib.h>

int lis(int arr[],int n);

int main()
{
    int n,*arr,i;

    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    printf("%d",lis(arr,n));

    return 0;
}

int lis(int arr[],int n)
{
    int memory[n],i,j,count,max=1;

    memory[0]=1;

    for(i=1;i<n;i++)
    {
        memory[i]=1;
        count=0;
        for(j=i-1;j>-1;j--)
        {
            if(arr[j]<arr[i])
            {
                if(memory[i]<memory[j]+1)
                {
                    memory[i]=memory[j]+1;
                }
            }
        }
    }

    max=memory[0];

    for(i=0;i<n;i++)
    {
        if(memory[i]>max)
            max=memory[i];
    }
    
    return max;
}
