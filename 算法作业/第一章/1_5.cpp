#include <iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    string s;
    int num;
    if(!input.eof())
    {
        getline(input,s);
        num=atoi(s.c_str());
        double n[num];
        cout<<num<<endl;
        double cha=0;
        for(int i=0;i<num;i++)
        {
            double a;
            input>>a;
            n[i]=a;
        }
        double c;
        for(int i=0;i<num-1;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                if(n[i]>n[j])
                {
                    double x=n[i];
                    n[i]=n[j];
                    n[j]=x;
                }
            }
        }
        cout<<n[0]<<" ";
        for(int i=1;i<num;i++)
        {
            cout<<n[i]<<" ";
            c=n[i]-n[i-1];
            if(c>cha)   cha=c;
        }
        output<<cha<<"\n";
    }
}
