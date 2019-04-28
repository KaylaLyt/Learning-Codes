#include <iostream>
#include <cstring>

const int max = 2000;
char arr[max];

using namespace std;

void sol(int n, int r)
{
    int total=-1;
    int temp = n;
    memset(arr, 0, sizeof(arr));
    while(temp!=0)
	{
		if(temp%r>9)
		{
			arr[++total]=temp%r+55;
		}
		else
		{
			arr[++total]=temp%r+48;
		}
        temp = temp/r;
    }
    for(int i=total; i>=0; i--)
	{
        cout<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int n, r;
    while(cin>>n>>r)
	{
        if(n>=0)
            sol(n, r);
        else
		{
            cout<<"-";
            sol(-n, r);
        }
    }
    return 0;
}
