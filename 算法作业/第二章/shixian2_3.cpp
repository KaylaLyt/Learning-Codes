#include<iostream>

using namespace std;

int half(int n)
{
    int sum=1;
    if(n==1) return 1;
    else
    {
        int t=n/2;
        for(int i=1;i<=t;i++)
        {

            sum+=half(i);
        }
        return sum;
    }
}

int main()
{
    int n;
    cin>>n;
    int sum=half(n);
    cout<<sum<<endl;
    return 0;
}
