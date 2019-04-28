#include<iostream>

using namespace std;

int isprime(int x); 

int main()
{
	int m,sum;
	int max=500;
	while(cin>>m&&m!=0&&max--)
	{
		sum=0;
		for(int i=2;i<m/2;i++)
		{
			if(isprime(i)&&isprime(m-i))
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
	
	
int isprime(int x)
{
	int i;
	int flag=1;
	if(x%2==0&&x!=2||x<2)
	{
		flag=0;
	}
	for(i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			flag=0;
		}
	}
	if(flag) return 1;
	else return 0;
}
