#include<iostream>
#include<string.h>

using namespace std;

#define INF 0x3f3f3f3f

int a[10][10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool isv[10][10];
int M,N,SUM;
bool judge(int x,int y,int num)
{
    if(x<1||y<1||x>N||y>M)//越界
        return 1;
    if(isv[x][y])//访问过
        return 1;
    if(num+a[x][y]>SUM/2)//走这一步超过了和的1半   
        return 1;
    return 0;
}
int dfs(int x,int y,int num)
{
    if(num==SUM/2)
        return 1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(judge(nx,ny,num))//判断   
            continue;
        isv[nx][ny]=true;
        int temp=dfs(nx,ny,num+a[nx][ny]);
        if(temp!=0)//产生结果，直接返回   
            return  temp+1;
        isv[nx][ny]=false;
    }
    return 0;
}
int main()
{
    while(cin>>M>>N){
        SUM=0;
for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>a[i][j];
                SUM+=a[i][j];
            }
        if(SUM%2){//和是奇数一定不可以 
            cout<<0<<endl;
        }
        else{//和是偶数继续判断 
memset(isv,0,sizeof(isv));
isv[1][1]=true;
cout<<dfs(1,1,a[1][1])<<endl;
}
}
    return 0;
}
