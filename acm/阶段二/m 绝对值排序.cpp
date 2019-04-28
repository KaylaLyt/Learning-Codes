#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	while(cin>>n,n)
	{
		int a[100];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			int max=0;
			int num=i;
			int temp;
			for(int j=i;j<n;j++)
			{
				if(abs(a[j])>max)
				{
					max=abs(a[j]);
					num=j;
				}
			}
			temp=a[num];
			a[num]=a[i];
			a[i]=temp;
		}
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}
