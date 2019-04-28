#include<iostream>

using namespace std;

int main()
{
	int x,y,n,total,prime;
	cin>>x>>y;
	while(x!=0||y!=0)
	{
		prime=1;
		for(n=x;n<=y;n++)
		{
			total=n*n+n+41;
			for(int i=2;i<n;i++)
			{
				if(total%i==0)
				{
					prime=0;
					break;
				}
			}
			if(prime==0)
			{
				break;
			}
		}
		if(prime==0)
		{
			cout<<"Sorry"<<endl;
		}
		else
		{
			cout<<"OK"<<endl;
		}
		cin>>x>>y;
	}
	return 0;
}
