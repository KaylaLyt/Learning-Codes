#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

int nDime=2;
const int MAXN=256;
int index=0;

void MultiplyMatrix(int a[],int b[][2],int *text)
{
    int i,j,temp;
    double t;
    for(i=0;i<nDime;i++)
    {
        t=0;
        for(j=0;j<nDime;j++)
        {
            t+=b[j][i]*a[j];
        }
        temp=t;
        printf("t=%f\n",t);
        text[index++]=temp%26;
    }
}

void ConverseMatrix(int m[][2],double cm[][2])
{
    double temp[2][2];
    int t,row,column;
    temp[0][0]=m[1][1];
    temp[1][1]=m[0][0];
    temp[0][1]=m[0][1]*(-1);
    temp[1][0]=m[1][0]*(-1);
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            cm[row][column]=0.0;
        }
    }
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            printf("%f\t",temp[row][column]);
        }
    }
    printf("\n");
    t=m[0][0]*m[1][1]-m[1][0]*m[0][1];
    printf("%d\n",t);
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            cm[row][column]=temp[row][column]/t;
        }
    }
}

void ShellPassword(int *OText,int TextLen,double matrix[][2],int *text)
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
    int i,temp,row,column;
    double ConMatrix[2][2];
    int matrix[2][2],OText[MAXN],Password[MAXN],OriText[MAXN];
    char text[MAXN],miwen[MAXN],mingwen[MAXN];
    for(row=0;row<2;row++)
    {
        for(column=0;column<2;column++)
        {
            matrix[row][column]=0;
        }
    }

    printf("ÇëÊäÈëÃÜÎÄ£º\n");
    memset(miwen,'0',sizeof(miwen)/sizeof(char));
    memset(ConMatrix,0,sizeof(ConMatrix)/sizeof(int));
    memset(OriText,0,sizeof(OriText)/sizeof(int));
    gets(miwen);
    for(i=0;i<strlen(miwen);i++)
    {
        Password[i]=miwen[i]-'a';
        printf("%d",Password[i]);
    }
    printf("\n");
    printf("ÇëÊäÈë¶þÎ¬¾ØÕó£º\n");
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            scanf("%d",&matrix[row][column]);
        }
    }
    printf("½âÃÜ¾ØÕó:\n");
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            printf("%d",&matrix[row][column]);
        }
        printf("\n");
    }
    ConverseMatrix(matrix,ConMatrix);
    printf("½âÃÜÄæ¾ØÕó£º\n");
    for(row=0;row<nDime;row++)
    {
        for(column=0;column<nDime;column++)
        {
            printf("%d",&ConMatrix[row][column]);
        }
        printf("\n");
    }

    ShellPassword(Password,i,ConMatrix,OriText);
    printf("½âÃÜºóµÄÄÚÈÝÎª£º");
    int j=0;
    for(j=0;j<i;j++)
    {
        mingwen[j]=OriText[j]+'a';
    }
    printf("%s",mingwen);
    return 0;
}
