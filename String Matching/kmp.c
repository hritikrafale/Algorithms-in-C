#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void kmp(char text[],char pattern[]);
void computeLPSArray(char pattern[],int lps[]);

int main()
{
    char text[20],pattern[20];

    printf("\nEnter the text:");
    scanf("%s",text);

    printf("\nEnter the pattern:");
    scanf("%s",pattern);

    kmp(text,pattern);

    return 0;
}

void computeLPSArray(char pattern[],int lps[])
{
    int size_of_pattern=strlen(pattern),len=0,i=1;

    lps[0]=0;

    while(i<size_of_pattern)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];

            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }

    printf("\nThe lps for %s is:",pattern);
    for(i=0;i<size_of_pattern;i++)
    {
        printf("%d ",lps[i]);
    }
}   

void kmp(char text[],char pattern[])
{   
    int *lps,size_of_pattern,size_of_text,i,j;

    size_of_text=strlen(text);
    size_of_pattern=strlen(pattern);

    lps=(int*)malloc(sizeof(int)*size_of_pattern);

    computeLPSArray(pattern,lps);

    i=0,j=0;

    while(i<size_of_text)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }

        if(j==size_of_pattern)
        {
            printf("\npattern found at index %d",i-j);
            j=lps[j-1];
        }
        else
        if( i<size_of_text && pattern[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
    }
}