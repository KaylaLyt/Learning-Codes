#include<iostream>

using namespace std;

int main() 
{
	int n; 
	int a[30];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=1;
			for(int j=i-1;j>0;j--)
			{
				a[j]=a[j-1]+a[j];
			}
			for(int j=0;j<=i;j++)
			{
				cout<<a[j];
				if(i!=j)
				{
					cout<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
