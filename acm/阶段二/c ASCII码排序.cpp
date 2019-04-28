#include<iostream>

using namespace std;

int main()
{
	char a,b,c,max,mid,min;
	while(cin>>a>>b>>c)
	{
		if(a>=b&&a>=c)
		{
			max=a;
			if(b>=c)
			{
				mid=b;
				min=c;
			}
			else
			{
				mid=c;
				min=b;
			}
		}
		else if(b>=a&&b>=c)
		{
			max=b;
			if(a>=c)
			{
				mid=a;
				min=c;
			}
			else
			{
				mid=c;
				min=a;
			}
		}
		else if(c>=a&&c>=b)
		{
			max=c;
			if(a>=b)
			{
				mid=a;
				min=b;
			}
			else
			{
				mid=b;
				min=a;
			}
		}
		cout<<min<<" "<<mid<<" "<<max<<endl;
	}
	return 0;
}
	
