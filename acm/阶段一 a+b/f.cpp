#include<iostream>

using namespace std;

int main()
{
	int num,i;
	while(cin>>num)
	{
		int sum=0;
		while(num--)
		{
			cin>>i;
			sum+=i;
		}
		cout<<sum<<endl;
	}
	return 0;
}
