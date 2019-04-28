#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100086],s[100086];
int minn=1000000;
bool ltt(int x,int y){
return x>y;}
inline void dfs(int b,int c){
    if(c>=minn) return;//剪枝1号
    if(b>n){
        if(c<minn)
            minn=c;
        return;
    }
    for(int i=1;i<=k;i++){
        if(s[i]+a[b]<=minn){//剪枝2号
            s[i]+=a[b];
            dfs(b+1,max(c,s[i]));
            s[i]-=a[b];
        }
    }
    return;
}
int main() {
    cin>>n>>k;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,ltt);//从大到小排序可以更快接近最优解
    dfs(1,0);
    cout<<minn<<endl;
    return 0;
}
