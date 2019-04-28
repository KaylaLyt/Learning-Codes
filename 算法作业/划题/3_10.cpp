#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
#define mst(a,x) memset(a,x,sizeof(a))
using namespace std;
int a[55][55][55];
int b[55][55][55];
int ans[55];
int main()
{
#ifdef local
    freopen("in.txt","r",stdin);
#endif
    int n,m,p,res=0; scanf("%d%d%d",&n,&m,&p);
    mst(b,0);
    rep(i,n)rep(j,m)rep(k,p) scanf("%d",&a[i][j][k]);
    rep(i,n)rep(j,m)rep(k,p){
        if(j==0&&k==0) b[i][j][k]=a[i][j][k];
        else if(k==0) b[i][j][k]=b[i][j-1][k]+a[i][j][k];
        else if(j==0) b[i][j][k]=b[i][j][k-1]+a[i][j][k];
        else b[i][j][k]=b[i][j-1][k]+b[i][j][k-1]-b[i][j-1][k-1]+a[i][j][k];
    }
    rep(i,n)rep(j,m)rep(k,p){
        for(int l=k; l<p; l++){
            for(int t=0; t<n; t++){
                if(i==0&&k==0) ans[t]=b[t][j][l];
                else if(i==0) ans[t]=b[t][j][l]-b[t][j][k-1];
                else if(k==0) ans[t]=b[t][j][l]-b[t][i-1][l];
                else ans[t]=b[t][j][l]-b[t][i-1][l]-b[t][j][k-1]+b[t][i-1][k-1];
            }
            int sum=0;
            for(int t=0; t<n; t++){
                if(sum>=0){
                    sum+=ans[t];
                    if(sum>res) res=sum;
                }else sum=0;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
