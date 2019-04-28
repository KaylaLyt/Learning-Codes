#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int stime[n],etime[n];
    for(int i=0;i<n;i++)
    {
        cin>>stime[i]>>etime[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(etime[i]>etime[j])
            {
                int t=etime[i];
                etime[i]=etime[j];
                etime[j]=t;
                t=stime[i];
                stime[i]=stime[j];
                stime[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<stime[i]<<" "<<etime[i]<<endl;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(etime[i]<stime[j])
        }
    }
    return 0;
}
