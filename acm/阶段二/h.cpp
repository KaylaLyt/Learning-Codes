#include<iostream>

using namespace std;

int main() 
{
	int m,n,sum1,sum2;
	
	while(cin>>m>>n)
	{
		sum1=0;
		sum2=0;
		if(m>n)
		{
			int temp=m;
			m=n;
			n=temp;
		}	
		while(m<=n)
		{
			if(m%2==0)
			{
				sum1+=m*m;
			}
			else
			{
				sum2+=m*m*m;
			}
			m++;
		}
		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}
		
			
	
