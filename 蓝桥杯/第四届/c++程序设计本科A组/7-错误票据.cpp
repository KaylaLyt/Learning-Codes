#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

const int M = 100000+5;
int ar[M];
char s[10];

int main()
{
	int x,n,m,num,sum=-1;
	memset(ar,0, sizeof(ar));
	scanf("%d\n",&x);
	for(int i=0; i<x; ++i){
		char c[205];
		gets(c);
		int idx=0;
		for(int j=0; j<strlen(c); ++j){
			if(c[j] == ' '){	//取每一个空格之间的数字
				num=atoi(s);
				idx=0;
				memset(s,0,sizeof(s));  //重新清空数组
				ar[num]++;	//标记该数字
				//printf("num= %d\n",num);
				sum=max(sum,num);	//用来记录数据里面的最大数，方便结束循环
			}
			s[idx++] = c[j];

		}
		num=atoi(s);	//最后一个空格后面的数
		idx=0;
		memset(s,0,sizeof(s));
		ar[num]++;
		sum=max(sum,num);
	}
	int i;
	for(i=0; i<=M; ++i){
		if(ar[i]!=0) break;
	}
	for(i; i<=sum; ++i ){	//此处用到了数据的最大数
		if(ar[i] == 0) m = i;
		if(ar[i] == 2) n = i;
	}
	printf("%d %d\n", m, n);
	return 0;
}
