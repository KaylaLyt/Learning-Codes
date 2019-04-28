#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	double m,n,total;
	while(cin>>n>>m)
	{
		total=0;
		for(int i=0;i<m;i++)
		{
			total+=n;
			n=sqrt(n);
		}
		cout<<fixed<<setprecision(2)<<total<<endl;
	} 
	return 0;
}
