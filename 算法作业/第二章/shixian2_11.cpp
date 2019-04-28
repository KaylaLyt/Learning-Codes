#include<iostream>

using namespace std;

int sum=0;
void solve(int a)
{

    if(a==1)    sum++;
    for(int i=2;i<=a;i++)
    {
        if(a%i==0)  solve(a/i);
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    cout<<sum<<endl;
    return 0;
}
