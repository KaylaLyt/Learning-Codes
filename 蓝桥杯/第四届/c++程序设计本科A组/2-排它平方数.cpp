#include<iostream>

using namespace std;

int main()
{

    for(int i=102345;i<987654;i++)
    {
loop:   int num[10]={0};
        int temp=i;
        while(temp)
        {
            if(num[temp%10]==1)
            {
                i++;
                goto loop;
            }
            num[temp%10]=1;
            temp/=10;
        }
        long long sum=(long long)i*i;
        while(sum)
        {
            if(num[sum%10]==1)
            {
                i++;
                goto loop;
            }
            sum/=10;
        }
        if(sum==0)
        {
            cout<<i<<endl;
        }
    }
    return 0;


}
