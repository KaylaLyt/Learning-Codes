#include<iostream>
using namespace std;

void swap(int a[],int b[],int n);

int main()
{
	int start[100],end[100];
	int n,i,j,endtime,sum;
	while(cin>>n&&n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>start[i]>>end[i];
		}
		swap(start,end,n);
		sum++;
		endtime=end[0];
		for(j=1;j<n;j++)
		{
			if(start[j]>=endtime)
			{
				sum++;
				endtime=end[j];
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 

void swap(int a[],int b[],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[i]>b[j])
			{
				k=b[i];
				b[i]=b[j];
				b[j]=k;
				
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
}
