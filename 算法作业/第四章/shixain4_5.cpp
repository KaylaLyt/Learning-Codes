#include<iostream>
#include<algorithm>
using namespace std;

int Greedy(int a[],int n,int L){
	sort(a,a+n);
	int temp = 0;
	for(int i = 0;i<n;i++){//最后一个元素为下标n-1的元素
		temp = temp + a[i];
		if (temp>L) return i;
		if(i==(n-1)) return n;	//就是缺了这里搞了很久，没有想到还有存得完的情况。也可以为return i+1 保持上下统一性。
	}

}

int main(){
	int n;
	cin>>n;
	int L;
	cin>>L;
	int *a=new int[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		}
	cout<<Greedy(a,n,L);
	system("pause");
	return 0;
}
