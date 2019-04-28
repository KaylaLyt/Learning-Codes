#include<iostream>

using namespace std;

int main()
{
	int a,b,m;
	while(cin>>a>>b,a!=0||b!=0)
	{
		m=a;
		for(int i=1;i<b;i++)
		{
			m*=a;
			while(m>=1000)
			{
				m=m%1000;
			}
		}
		cout<<m<<endl;
	}
	return 0;
} 
