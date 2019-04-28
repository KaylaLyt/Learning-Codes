#include<iostream>
#include<cstring>
using namespace std;

void turn(char s[]);

int main()
{
	char a[100017],b[100017];
	while(cin>>a>>b)
	{
		turn(a);
		turn(b);
		if(strcmp(a,b))
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
}

void turn(char s[])
{
	int len=strlen(s);
	int p=0;
	int i,j;
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			p=1;
			break;
		}
	}
	if(p)
	{
		for(j=len-1;j>=0;j--)
		{
			if(s[j]=='0')
			{
				s[j]='\0';
			}
			else break;
			len--;
		}
		if(s[len-1]=='.')
		{
			s[len-1]='\0';
		}
	}
}
	/*while(s[0]=='0')
	{
		if(s[1]=='.') break;
		else
		{
			for(i=1;i<len;i++)
			{
				s[i-1]=s[i];
			}
			len--;
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LEN 100000
int main() {
    char a[LEN];
    char b[LEN];
    int lena, lenb, len, i;
    while(cin >> a >> b) {
        lena = 0;
        lenb = 0;
        len = strlen(a);
        len--;
        for(i = 0; i <= len; i++) {
            if(a[i] == '.') {
                lena = i;
                break;
            }
        }
        while(a[len] == '0' && len > lena && lena != 0) {
            a[len] = '\0';
            len--;
        }
        if(a[len] == '.') {
           a[len] = '\0';
        }

        len = strlen(b);
        len--;
        for(i = 0; i <= len; i++) {
            if(b[i] == '.') {
                lenb = i;
                break;
            }
        }
        while(b[len] == '0' && len > lenb && lenb != 0) {
            b[len] = '\0';
            len--;
        }
        if(b[len] == '.') {
            b[len] = '\0';
        }
        if(strcmp(a, b) == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}*/
