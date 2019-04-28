#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[50005];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)//枚举左端点
    {
        int l,r;
        l=INF;
        r=-INF;
        for(int j=i; j<n; j++)//枚举右端点
        {
            l=min(l,a[j]);//更新最大最小数
            r=max(r,a[j]);
            if(r-l==j-i)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
