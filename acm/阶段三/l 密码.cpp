#include<iostream>
#include<string>
using namespace std;

int main()
{
	int m,i,k,l;
	cin>>m;
	while(m--)
	{
		int flag[4]={0};
		string a;
		cin>>a;
		i=a.length();
		if(i>=8&&i<=16)
		{
			for(k=0;k<i;k++)
			{
				if(a[k]>='A'&&a[k]<='Z')
				{
					flag[0]=1;
				}
				else if(a[k]>='a'&&a[k]<='z')
				{
					flag[1]=1;
				}
				else if(a[k]>='0'&&a[k]<='9')
				{
					flag[2]=1;
				}
				else
				{
					flag[3]=1;
				}
			}
			if((flag[0]+flag[1]+flag[2]+flag[3])>=3)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
