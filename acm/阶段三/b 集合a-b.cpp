#include<iostream>

using namespace std;

int main() 
{
	int m,n,temp,flag,x;
	int a[100],b[100],c[100];
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
		{
			break;
		}
		x=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
		}
		for(int i=0;i<n;i++)
		{
			flag=1; 
			for(int j=0;j<m;j++)
			{
				if(a[i]==b[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				c[x]=a[i];
				x++;
			} 
		}
		if(x==0)
		{
			cout<<"NULL"<<endl;
		}
		else
		{
			for(int i=0;i<x-1;i++)
			{
				for(int j=0;j<x-1-i;j++)
				{
					if(c[j]>c[j+1])
					{
						temp=c[j];
						c[j]=c[j+1];
						c[j+1]=temp;
					}
				}
			}
			for(int i=0;i<x;i++)
			{
				cout<<c[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
