#include<iostream>

using namespace std;

int main() 
{
	int n;
	double num;
	int a,b,c;
	while(cin>>n,n)
	{
		a=0,b=0,c=0;
		while(n)
		{
			cin>>num;
			if(num<0)
			{
				a++;
			}
			else if(num==0)
			{
				b++;
			}
			else if(num>0)
			{
				c++;
			}
			n--;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
	
	
