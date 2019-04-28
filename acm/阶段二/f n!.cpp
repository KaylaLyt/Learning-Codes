/*#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n,i,j,c,s;
	const int N=10000;
	int a[N]={0};
	while(cin>>n&&n>=0)
	{
		memset(a,0,sizeof(a));
		a[0]=1;
		for(i=2;i<=n;i++)
		{
			c=0;
			for(j=0;j<N;j++)
			{
				s=a[j]*i+c;
				a[j]=s%10;
				c=s/10;
			}
		}
		for(i=N-1;i>=0;i--)
		{
			if(a[i]!=0)
			{
				break;
			}
		}
		for(j=i;j>=0;j--)
		{
			cout<<a[j];
		}	
		cout<<endl;
	}
	return 0;
}*/ 
/*#include<iostream>
#include<iomanip>

using namespace std;
 
int main()
{
	int n,i,k,l;
	while(cin>>n)
	{ 
		int a[80000]={0};
		a[0]=1;
		l=0;
		int m,s=1;
 		for(i=1;i<=n;i++)
 		{
  			for(m=1;m<=s;m++)
 				a[m-1]*=i;
  			for(m=0;m<s;m++)
 			{ 
				if(a[m]>9999&&m==s-1) 
				{
					s++;
				}
 				while(a[m]>9999)
				{
					a[m+1]+=a[m]/10000;
					a[m]=a[m]%10000;
				}
  			}
 		}
 		for(k=s-1;k>=0;k--)
 		{
		 	if(l==0)
 			{
			 	cout<<a[k];
				 l=1;
			}
 			else
			{
				cout<<setfill('0')<<setw(4)<<a[k];
			}
		}
 		cout<<endl;
	}
 return 0;
 
}*/
#include<iostream>

using namespace std;

int main()
{
	const int MAX=10000;
    int n,a[MAX];
    int i,j,k,count,temp;
    while(cin>>n)
    {
        a[0]=1;
        count=1;
        for(i=1;i<=n;i++)
        {
            k=0;
            for(j=0;j<count;j++)
            {
                temp=a[j]*i+k;
                a[j]=temp%10;
                k=temp/10;    
            }
            while(k)  
             {
                a[count++]=k%10;
                k/=10;
            }
        }
        for(j=MAX-1;j>=0;j--)      
            if(a[j])
                break;
            for(i=count-1;i>=0;i--)
                cout<<a[i];
            cout<<endl;
    }
    return 0;
}



***************************************************



#include<iostream>
using namespace std;
int a[40000];
int main()
{
	int N,i,j,pre;
	while(cin>>N)
	{
		a[0]=1;
		a[1]=1;
		if(N==0||N==1){cout<<1<<endl;continue;}
		for(i=2;i<=N;i++)
		{
			pre=0;
			for(j=1;j<=a[0];j++)
			{
				a[j]=a[j]*i;
				a[j]+=pre;
				pre=a[j]/10;
				a[j]%=10;
			}
			while(pre)
			{
				a[j]=pre%10;
				a[0]=j;
				pre/=10;
				j++;
			}
		}
		for(i=a[0];i>=1;i--)
		{cout<<a[i];}
		cout<<endl;
	}
	return 0;
}


