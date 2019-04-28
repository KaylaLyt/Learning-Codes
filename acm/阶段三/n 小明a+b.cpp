#include<iostream>

using namespace std;

int main()
{
	int t,a,b,sum;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a>99)
		{
			a=a%100;
		}
		if(b>99)
		{
			b=b%100;
		}
		sum=a+b;
		if(sum>99)
		{
			sum=sum%100;
		}
		cout<<sum<<endl;
	}
	return 0;
}
