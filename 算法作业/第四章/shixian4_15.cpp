#include<iostream>

using namespace std;

int main()
{
	int n;
	int a[100];
	cin>>n;
	int x=2;
	int index=0;
	a[index++]=x;
	n-=x;
	while(n>a[index-1])
	{
		a[index]=a[index-1]+1;
		n-=a[index];
		index++;
	}
	int num=index-1;
	while(n)
	{
		a[num]++;
		num=(num-1+index)%(index);
		n--;
	}
	int result=1;
	for(int i=0;i<index;i++)
	{
		result*=a[i];
	 }
	 cout<<result<<endl;

	return 0;
 }
