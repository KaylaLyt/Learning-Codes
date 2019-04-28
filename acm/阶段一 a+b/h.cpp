#include<iostream>

using namespace std;

int main()
{
	int num1;
	cin>>num1;
	while(num1--)
	{
		int num2,i;
		int sum=0;
		cin>>num2;
		while(num2--)
		{
			cin>>i;
			sum+=i;
		}
		cout<<sum<<endl;
		if(num1!=0)
		{
			cout<<endl;
		}
	}
	return 0;
}
