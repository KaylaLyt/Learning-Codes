#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int vis[3][50], P[15];//三个方向 ↖↑↗在此三个方向都不能有皇后
int n, sum;

void  DFS(int row);

int main()
{
    for(n = 1; n <= 10; n++)//先打表不然会超时的
    {
        memset(vis,0,sizeof(vis));
        sum = 0;
        DFS(1);
        P[n] = sum;
    }
    while(scanf("%d",&n), n)
    {
        printf("%d\n",P[n]);
    }
    return 0;
}

void  DFS(int row)
{
    int i;
    if(row == n + 1)//已经够n行了
    {
        sum ++;
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(vis[0][row-i+n] == 0 && vis[1][i] == 0 && vis[2][row+i] == 0)
        {//不会回溯的同学要好好看看学习学习
            vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 1;//变值
            DFS(row + 1);//深搜
            vis[0][row-i+n] = vis[1][i] = vis[2][row+i] = 0;//回溯
        }
    }
}
