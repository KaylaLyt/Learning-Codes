#include <iostream>
#include<algorithm>
using namespace std;


const int maxn = 1000;
int N, T;
struct Interval{
    int start, end;
}a[maxn];

int cmp(const Interval &a, const Interval &b)
{
    if(a.start < b.start) return 1;
    else if(a.start == b.start && a.end < b.end) return 1;
    else return 0;
}

void solve()
{
    sort(a, a+N, cmp);
    int count = 0;
    int s, e = 1;
    int index = 0;
    int ok = 1;
    while(e < T)
    {
        s = e;//更新覆盖区域
        for(int i=index; i<N; i++)
        {
            if(a[i].start <= s)
            {
                if(a[i].end >= s)
                {
                    e = a[i].end;//取符合条件的最远区间。
                }
            }
            else{
                index = i;//不符合条件则需要换区间
                break;
            }
        }
        if(s >= e)
        {
            ok = 0;
            break;
        }
        else{
            count ++;
        }
    }
    if(ok) cout<<count<<endl;
    else cout<<"-1"<<endl;
}
int main()
{

    cin>>N>>T;
    for(int i=0; i<N; i++)
    {
       // scanf("%d%d",&a[i].start, &a[i].end);
        cin>>a[i].start>>a[i].end;
    }
    solve();
    return 0;
}
