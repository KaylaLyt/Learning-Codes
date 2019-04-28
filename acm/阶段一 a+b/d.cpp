#include<iostream>

using namespace std;

int main()
{
	int num,a;
	int sum;
	cin>>num;
	while(num>0)
	{
		sum=0;
		for(int i=0;i<num;i++)
		{
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
		cin>>num;
	}
	return 0;
}
