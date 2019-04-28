/*#include<iostream>
using namespace std;
int main()
{
    int t,k,n,flag;
    cin>>t;
    while(t>0&&t<100000)
    {
        cin>>k>>n;
        if(k<=55000&&k>=1&&n<=2000&&n>=1)
        {
            flag=(k-1)/n%2;
            if(flag==0)
            {
                cout<<"L\n";
            }
            else
            {
                cout<<"Z\n";
            }
            t--;
        }
    }
    return 0;
}*/
#include<stdio.h>
int main()
{
    int t,k,n,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&k,&n);
        flag=k%(n+1);
        if(flag!=0)
        {
            printf("L\n");
        }
        else
        {
            printf("Z\n");
        }
    }
    return 0;
}
