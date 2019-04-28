#include<iostream>

using namespace std;

int main()
{
	int m,n;
	int a,b,c,num;
	
	while(cin>>m>>n)
	{
		int sit=0;
		for(int i=m;i<=n;i++)
		{
			a=i%10;
			b=i/10%10;
			c=i/100;
			num=a*a*a+b*b*b+c*c*c;
			if(num==i&&sit==1)
			{
				cout<<" "<<i;
			}
			if(num==i&&sit==0)
			{
				cout<<i;
				sit=1;
			}
			
		}
		if(sit==0)
		{
			cout<<"no";
		}
		cout<<endl;
	}
	return 0;
} 
