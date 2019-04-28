#include<iostream>

using namespace std;

int main()
{
	int num1;
	cin>>num1;
	while(num1--)
	{
		int sum=0;
		int num2;
		int i;
		cin>>num2;
		while(num2--)
		{
			cin>>i;
			sum+=i;
		}
		cout<<sum<<endl;
	}
	return 0;
}
