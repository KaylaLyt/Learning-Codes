#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<math.h>
using namespace std;

int main()
{
    ifstream input;
    input.open( "input.txt");
    if( ! input )
    {
        cerr << "Open input file error!" << endl;
    }
    string s;
    while(getline(input,s));
    int a,b;
    stringstream ss;
    ss<<s;
    ss>>a;
    ss>>b;
    //cout<<s<<endl;
    //cout<<a<<" "<<b<<endl;
    int d=0;
    for(int i=a;i<=b;i++)
    {
        int div;
        if(i==1) div=1;
        else{
            int j=i;
            int k;
            div=2;
            for(k=2;k<sqrt(j);k++)
            {
                if(j%k==0)
                {
                    div+=2;
                }
            }
            if(sqrt(j)*sqrt(j)==j) div++;
        }
        //cout<<i<<" "<<div<<endl;
        if(div>d) d=div;
    }
    cout<<d<<endl;
    cout<<"ok"<<endl;

   ofstream output("output.txt");
	output<<d;
	input.close();
	output.close();
	cin.get();
    return 0;
}
