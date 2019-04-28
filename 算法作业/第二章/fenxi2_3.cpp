/*
二分法实验
1、设a[0:n-1]是一个已排好序的数组.
请改写二分搜索算法，使得当搜索元素x不在数组中时,
返回小于x的最大元素的位置I和大于x的最大元素位置j.
当搜索元素在数组中时，I和j相同，均为x在数组中的位置.
2、设有n个不同的整数排好序后存放于t[0:n-1]中,
若存在一个下标I,0<=i<n，使得t[i]=i,
设计一个有效的算法找到这个下标.
要求算法在最坏的情况下的计算时间为O(logn).
*/
#include<iostream>
using namespace std;
/*
功能:1\二分查找改进版
输入:拍好序的a[],大小n,待查数x,返回参数i,j
返回:真:找到
*/
bool BinarySearch(int *a,int n,int x,int& i,int& j){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x==a[mid]){
            i=j=mid;
            return true;
        }
        if(x>a[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    i=right;
    j=left;
    return false;
}
/*
功能:2\高效查找
输入:数组,大小,待查值
返回:下标,若没有返回-1
*/
int SearchTag(int *a,int n,int x){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x==a[mid]) return mid;
        if(x>a[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main(){
    int n,i,j,a[1000],x;
    while(cin>>n){//输入数组大小
        for(i=0;i<n;i++)cin>>a[i];//输入数据,需要从小到大
        cin>>x;//输入待查数据
        BinarySearch(a,n,x,i,j);//超找
        cout<<"用函数1找到的i,j为: "<<'('<<i<<','<<j<<')'<<'\n';//输出对应的i,j
        cout<<"用函数2找到的下标为: "<<SearchTag(a,n,x)<<"\n\n";//输出2找到的下标
    }
    return 0;
}
