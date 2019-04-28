#include<iostream>

using namespace std;

int sum(int a)
{
	int sum=0;
	for(int i=1;i<a;i++)
	{
		if(a%i==0)
		{
			sum+=i;
		}
	}
	return sum;
}
int main()
{
	int m,a,b;
	cin>>m;
	while(m--)
	{
		cin>>a>>b;
		if(sum(a)==b&&sum(b)==a)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl; 
		}
	}
	return 0;
}
