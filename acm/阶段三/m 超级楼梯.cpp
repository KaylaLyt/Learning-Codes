#include<iostream>

using namespace std;

int main()
{
	int n,m,a,b,res;
	cin>>n;
	while(n--)
	{
		a=1;
		b=2;
		cin>>m;
		if(m==1)
		{
			res=0;
		}
		else if(m==2)
		{
			res=a;
		}
		else if(m==3)
		{
			res=b;
		} 
		else if(m>3)
		{
			for(int j=4;j<=m;j++)
			{
				res=a+b;
				a=b;
				b=res;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
