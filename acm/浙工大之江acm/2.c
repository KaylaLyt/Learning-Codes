#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,max=0,k;
    scanf("%d",&n);
    char name[1000][16];
    int flag[1000]={0};
    for(i=0;i<n;i++)
    {
        scanf("%s",&name[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[i],name[j])==0)
            {
                flag[i]++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]>max)
        {
            flag[i]=max;
            k=i;
        }
    }
    printf("%s\n",name[k]);
}
