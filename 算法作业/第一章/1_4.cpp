#include<malloc.h>
#include<iostream>
#include<fstream>
#define INF 1<<20


using namespace std;
/*将矩阵a的第col行进行行变换*/
void transfer_row(int array[],int n)
{
    int i=0;
    for(i=0; i<n; i++)
        array[i]^=1;
}


/*交换矩阵a的i和j列*/
void swap_columns(int **a,int m,int n,int i,int j)
{
    int k=0;
    while(k<m)
    {
        int tmp=a[k][i];
        a[k][i]=a[k][j];
        a[k][j]=tmp;
        k++;
    }
}
/*比较矩阵a的第col_a列和矩阵b的第col_b是否相等*/
int compare_column(int **a,int **b,int m,int n,int col_a,int col_b)
{
    int k=0;
    for(k=0; k<m; k++)
    {
        if(a[k][col_a]!=b[k][col_b])
            return 0;
    }
    return 1;
}


void copy_array(int** dest,int **src,int m,int n )
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            dest[i][j]=src[i][j];
}


/**寻找将原始矩阵a变换到目标矩阵b的最少变换次数，如果不能将a变换到b，那么返回-1*/
int find(int **a,int **b,int m,int n)
{
    /**flag记录一次变换，是否能够达到目标矩阵*/
    int flag=0;
    /**best为最少交换次数，初始值为无穷大*/
    int best=INF;
    /**count记录一次变换过程中需要进行交换的次数*/
    int count=0;
    int **tmp=(int **)malloc(sizeof(int *)*m);
    int i=0;
    for(i=0; i<m; i++)
        tmp[i]=(int *)malloc(sizeof(int)*n);
    copy_array(tmp,a,m,n);


    /**以列变换为基准，一次将初始矩阵a的每一列与第一列交换*/
    for(i=0; i<n; i++)
    {
        swap_columns(a,m,n,i,0);
        if(i!=0)
            count++;

        /**列变换后，将a的新的第一列和目标矩阵b的第一列比较，
        若a中第一列中某行元素与b中第一列相应行的元素不相等，则将a中该行进行变换
        完成此过程后，a的第一列元素和b的第一列元素完全相同，下面列变换过程中就不能再进行行变换！
        */
        for(int j=0; j<m; j++)
        {
            if(a[j][0]!=b[j][0])
            {
                transfer_row(a[j],n);
                count++;
            }
        }


        /**从a中一次寻找相应的某些列使得这些列一次和b中的第2到第n列相等，
        如果查找成功，则说明此种变换可以达到目标状态，然后将此种变换所花费的变换次数和当前最有变换次数best比较
        如果小于best，则将best更新此种变换的花费的变换次数
        */
        for(int j=1; j<n; j++)
        {
            flag=0;
            for(int k=j; k<n; k++)
            {
                if(compare_column(a,b,m,n,k,j))
                {
                    if(k!=j)
                    {
                        count++;
                        swap_columns(a,m,n,k,j);
                    }
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                break;

        }
        if(flag==1&&best>count)
            best=count;
        count=0;
        copy_array(a,tmp,m,n);

    }
    if(best<INF)
        return best;
    else return -1;
}


int main()
{
    ifstream in("input.txt");
    ofstream output("output.txt");
    int num;
    in>>num;
    for(int i=0; i<num; i++)
    {


        int m,n;
        in >>m>>n;
        int **a=(int **)malloc(sizeof(int*)*m);
        int **b=(int **)malloc(sizeof(int*)*m);
        for(int i=0; i<m; i++)
        {
            a[i]=(int *)malloc(sizeof(int)*n);
            b[i]=(int *)malloc(sizeof(int)*n);
        }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                in>>a[i][j];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                in>>b[i][j];

        int res=find(a,b,m,n);
        cout<<res<<endl;

        output<<res<<"\n";
    }
}
