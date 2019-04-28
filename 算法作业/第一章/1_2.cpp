#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;
//计算阶乘
int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    int sum=1;
    for (int i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
//统计n位中取p位的情况个数
int getnp(int p,int n)
{
    int sum=1;
    for (int i=n-p+1;i<=n;i++)
    {
        sum*=i;
    }
    return sum/factorial(p);
}
//统计在总位数一样的情况下第p位前有多少
int getp(char a,int p,int n)
{
    int sum = 0;
    for (int i = n+1;i<(a-'a'+1);i++)
    {
        sum += getnp(p-1,(26-i));
    }
    return sum;
}
int main()
{
    int sum=0;
    int size=0;
    char buffer[20];
    string s;
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");
    int a;
    if(!inputfile.eof())
    {
        getline(inputfile,s);
        /*stringstream ss;
        ss<<s;
        ss>>a;*/
        a=atoi(s.c_str());
        cout<<a<<endl;
    }
    int i=0;
    while(i<a)
    {
        inputfile.getline(buffer,20);
        sum=0;
        size = strlen(buffer);
        for (int i=1;i<size;i++)
        {
            sum += getnp(i,26);
            sum += getp(buffer[i],size-i,buffer[i-1]-'a'+1);
        }
        sum += getp(buffer[0],size,0);
        sum++;
        outputfile<<sum<<"\n";
        i++;
    }
    outputfile.close();
}
