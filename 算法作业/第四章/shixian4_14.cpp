#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int i,stone[999];

int stonemax(int n,int k)
{
	priority_queue<int> q;
	//生成最大优先队列
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,max=0;
	while(q.size()>2)
	//因为要求最大总费用，所以要求合并次数尽量多
	{
		sum=0;
		for(i=0;i<2;i++)
		{
			sum+=q.top();
			q.pop();
		}
		max+=sum;
		q.push(sum);
	}
	while(!q.empty())
	{
		max+=q.top();
		q.pop();
	}
	return max;
}

int stonemin(int n,int k)
{
	priority_queue<int,vector<int>,greater<int> > q;
	//生成最小优先队列
	for(i=0;i<n;i++)
	q.push(stone[i]);
	int sum=0,min=0;
	while(q.size()>k)
	//因为要求最小总费用，所以要求合并次数尽量少
	{
		sum=0;
		for(i=0;i<k;i++)
		{
			sum+=q.top();
			q.pop();
		}
		min+=sum;
		q.push(sum);
	}
	while(!q.empty())
	{
		min+=q.top();
		q.pop();
	}
	return min;
}

int main()
{
    int n,k;
	cin>>n>>k;
    for(i=0; i<n; i++)
    cin>>stone[i];
    cout<<stonemax(n,k)<<endl;
    cout<<stonemin(n,k)<<endl;
    return 0;
}
