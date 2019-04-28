#include<iostream>

using namespace std;

int main()
{
    int a[4];
    int arr[1000];
    int t=0;
    for(int i=1001;i<9999;i++)
    {
loop:   int n=i;
        int j=0;
        if(i%10==0)
        {
            i++;
            goto loop;
        }
        while(n)
        {
            a[j]=n%10;
            if(a[j]==3||a[j]==4||a[j]==7)
            {
                i++;
                goto loop;
            }
            if(a[j]==6)
            {
                a[j]=9;
            }
            if(a[j]==9)
            {
                a[j]=6;
            }
            n/=10;
            j++;
        }
        int x=a[0]*1000+a[1]*100+a[2]*10+a[3];
        int sub=x-i;
        if(sub<-200&&sub>-300)
        {
            cout<<i<<" "<<x<<" "<<sub<<endl;
            arr[t++]=sub;
        }
        if(sub>800&&sub<900)
        {
            cout<<i<<" "<<x<<" "<<sub<<endl;
            arr[t++]=sub;
        }
    }
    int is=0;
    for(int i=0;i<t-1;i++)
    {
        for(int j=i+1;j<t;j++)
        {
            if(a[i]+a[j]==558)
            {
                cout<<a[i]<<"   "<<a[j]<<endl;
                is=1;
            }
        }
    }
    if(is==0) cout<<"0"<<endl;
}
