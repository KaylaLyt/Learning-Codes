#include<iostream>

using namespace std;

int main()
{
	int n,i;
	int a[55]={0};
	a[1]=1,a[2]=2,a[3]=3,a[4]=4;
	cin>>n;
	while(n!=0)
	{
		for(i=5;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-3];
		}
		cout<<a[n]<<endl;
		cin>>n;
	}
	return 0;
}
