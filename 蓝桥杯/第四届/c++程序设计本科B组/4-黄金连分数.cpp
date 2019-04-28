#include<cstdio>
#include<iostream>
using namespace std;
#define LL long long
LL f[55]={0};
int main()
{
	f[1]=1;
	int i;
	for(i=2;i<=51;i++) f[i]=f[i-1]+f[i-2]; //求fib，多求一点
	LL y=f[49],x=f[48];
	for(i=0;i<=100;i++) //模拟除法的过程，和手算除法的过程一样，在草稿纸上划一划就知道
	{
		int ans=x/y;
		x=(x%y)*10;
		cout<<ans; //输出除数
	}
	return 0;
}
