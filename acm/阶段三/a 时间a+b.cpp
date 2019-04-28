#include<iostream>

using namespace std;

int main() 
{
	int n,ah,am,as,bh,bm,bs,h,m,s;
	cin>>n;
	while(n--)
	{
		cin>>ah>>am>>as>>bh>>bm>>bs;
		s=(as+bs)%60;
		m=(am+bm+(as+bs)/60)%60;
		h=ah+bh+(am+bm+(as+bs)/60)/60;
		cout<<h<<" "<<m<<" "<<s<<endl;
	}
	return 0;
}
