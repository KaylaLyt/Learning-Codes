#include<iostream>

using namespace std;

int main() {
	int a;
	cin>>a;
	int arr[a][2];
	for(int i=0;i<a;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=0;i<a;i++)
	{
		int max=0;
		int max2=0;
		int num=i;
		for(int j=i;j<a;j++)
		{
			if(arr[j][0]>max)
			{
				max=arr[j][0];
				max2=arr[j][1];
				num=j;
			}
		}
		arr[num][0]=arr[i][0];
		arr[num][1]=arr[i][1];
		arr[i][0]=max;
		arr[i][1]=max2;
	}
	cout<<endl;
	
	for(int i=0;i<a;i++)
	{
		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	}
}
