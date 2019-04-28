#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<memory.h>

int nDime=2;
const int MAXN=256;
int index=0;

void MultiplyMatrix(int a[],int b[][2],int *text)
{
    int i,j,t;
    for(i=0;i<nDime;i++)
    {
        t=0;
        for(j=0;j<nDime;j++)
        {
            t+=b[j][i]*a[j];
        }
        text[index++]=t%26;
    }
}

void ShellPassword(int *OText,int TextLen,int matrix[][2],int *text)
{
    int i,j,n,a[2]={0};
    n=TextLen/nDime;
    if(TextLen%nDime==1)
        n++;
    for(i=0;i<n;i++)
    {
        for(j=0;j<nDime;j++)
        {
            a[j]=OText[i*nDime+j];
        }
        MultiplyMatrix(a,matrix,text);
    }
    printf("\n");
}

int main()
{
    int i,row,column;
    int K[2][2]={0},OText[MAXN],Password[MAXN];
    char text[MAXN],miwen[MAXN];
    printf("请输入原文：");
    memset(text,0,sizeof(text));
    memset(Password,0,sizeof(Password)/sizeof(int));
    memset(OText,0,sizeof(OText)/sizeof(int));
    memset(miwen,'\0',sizeof(text));
    scanf("%s",text);
    printf("请输入二维矩阵：\n");
    for(row=0;row<2;row++)
    {
        for(column=0;column<2;column++)
        {
            scanf("%d",&K[row][column]);
        }
    }
    printf("输出二维矩阵:\n");
    for(row=0;row<2;row++)
    {
        for(column=0;column<2;column++)
        {
            printf("%d",&K[row][column]);
        }
        printf("\n");
    }
    for(i=0;i<strlen(text);i++)
    {
        OText[i]=text[i]-97;
    }
    ShellPassword(OText,strlen(text),K,Password);
    for(i=0;i<strlen(text);i++)
    {
        printf("%d",Password[i]);
    }
    printf("\n");
    printf("加密后的内容为：");
    for(i=0;i<strlen(text);i++)
    {
        miwen[i]=Password[i]+'a';
    }
    printf("%s",miwen);
    return 0;
}
