#include<stdio.h>

int main()
{
    int num_of_testcases;

    scanf("%d",&num_of_testcases);

    while(num_of_testcases--)
    {
        int N,i,max_so_far=0,max=0;

        scanf("%d",&N);

        long int arr[N];

        for(i=0;i<N;i++)
            scanf("%ld",arr+i);

        for(i=0;i<N;i++)
        {
            if(arr[i]%2==0)
            {
                max_so_far++;
            }
            else
            {
                if(max_so_far>max)
                    max=max_so_far;
                max_so_far=0;
            }
        }
        if(max_so_far>max)
            max=max_so_far;
        printf("%d\n",max);
    }

    return 0;
}