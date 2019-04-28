#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXNUM=101;

typedef struct goods {
	int value;//价值
	int size;//体积
};

goods s[MAXNUM];

bool cmp(goods a,goods b) {
	if(a.value==b.value)//排序 
		return a.size<b.size;
	else
		return a.value>b.value;
}

int main() {
	int n,v,i,j,sum;
	while(cin>>v,v) 
	{
		cin>>n;
		for(i=0; i<n; i++) 
		{
			cin>>s[i].value>>s[i].size;
		}
		sort(s,s+n,cmp);
		sum=0;
		for(i=0; i<n; i++) 
		{
			if(v-s[i].size>=0) 
			{
				v-=s[i].size;
				sum+=s[i].size*s[i].value;
			} 
			else 
			{
				sum+=v*s[i].value;
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
