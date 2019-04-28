#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int a[201], b[201];
int n;
int dp[202][10000];//dp[i][j] 表示前i个作业中A机器花j分钟的时候 B机器所花时间
int main(int argc, char* argv[]) {
    cin >> n;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    int sum=0;
    for(int i=1; i<=n; i++) {
        sum+=a[i];
        for(int j=0; j<=sum; j++) {
            dp[i][j]=dp[i-1][j]+b[i];
            if(j>=a[i]) dp[i][j]=min(dp[i-1][j]+b[i],dp[i-1][j-a[i]]);
        }
    }
    int ans=999999;
    //max(dp[n][i],i) 表示完成前n个作业A机器花i分钟 B机器花dp[n][i]分钟情况下，最迟完工时间
    for(int i=0; i<=sum; i++)ans=min(ans,max(dp[n][i],i));
    cout<<ans<<endl;
    return 0;
}
