#include<iostream>

using namespace std;

int main()
{
	const int N=100000;
	int a[N];
	int t,n,ca=1;
	cin>>t;
	while(t)
	{
		int maxsum=-10000,sum=0,head=0,end=0,temp=1;//sum代替dp数组（因为题目简单）
		cin>>n;
        for(int i=0;i<n;++i)
        {
        	cin>>a[i];
		}
        for(int i=0;i<n;++i)
		{
            sum+=a[i];
            if(sum>maxsum)
			{
                maxsum=sum;
                head=temp;
                end=i+1;
            }
            if(sum<0)
			{
                sum=0;
                temp=i+2;
            }
        }

		cout<<"Case "<<ca<<":"<<endl;
		cout<<maxsum<<" "<<head<<" "<<end<<endl;
		t--;
		if(t)
		{
			cout<<endl;
		}
		ca++;
	}
	return 0;
}
