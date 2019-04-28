#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int maxm=0;
    int maxn=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int x=1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                x++;
            }
        }
        if(x>maxn)
        {
            maxn=x;
            maxm=a[i];
        }
    }
    cout<<"众数是："<<maxm<<"  重数是："<<maxn<<endl;
    return 0;
}
