#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;

int a[1000];
int ans;
int n;

int main()
{
		ifstream input("input.txt");
		ofstream output("output.txt");
		if(!input.is_open())
		{
			cout<<"can not open the input.txt";
			return 0;
		 }
		input>>n;

		for(int i=1;i<=n;i++)
		{
			input>>a[i];
		}

		sort(a+1,a+1+n);

		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];//第i个顾客的等待时间
			ans+=cnt;// 累加求和；
		}

		output<<setiosflags(ios::fixed)<<setprecision(2) <<(ans*1.0)/n<<endl;//输出平均数结果。保留两位小数

	return 0;
 }
