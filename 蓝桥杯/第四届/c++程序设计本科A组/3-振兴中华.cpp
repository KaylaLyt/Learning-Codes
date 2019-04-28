#include<iostream>

using namespace std;

int main()
{
    int a[4][5];
    for(int i=0;i<5;i++)
    {
        a[0][i]=1;
    }
    for(int j=0;j<4;j++)
    {
        a[j][0]=1;
    }
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<5;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    cout<<a[3][4]<<endl;
    return 0;
}
