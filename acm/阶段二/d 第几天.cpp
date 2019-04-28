#include<iostream>

using namespace std;

int main()
{
	int a,b,c,total;
	int mon[13]={0};
	mon[1]=31,mon[3]=31,mon[4]=30,mon[5]=31,mon[6]=30,mon[7]=31,mon[8]=31,mon[9]=30,mon[10]=31,mon[11]=30,mon[12]=31;
	char e,f;
	while(cin>>a>>e>>b>>f>>c)
	{
		total=0;
		if(a%4==0&&a%100!=0||a%400==0)
		{
			mon[2]=29;
		}
		else
		{
			mon[2]=28;
		}
		for(int i=1;i<b;i++)
		{
			total+=mon[i];
		}
		total+=c; 
		cout<<total<<endl;
	}
	return 0;
} 
