#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
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
    input>>s;
    int a;
    stringstream ss;
    ss<<s;
    ss>>a;
    int k[10]={0};
    for(int i=1;i<=a;i++)
    {
        int j=i;
        while(j>0)
        {
            k[j%10]++;
            j/=10;
        }
    }
    /*for(int i=0;i<10;i++)
    {
        cout<<k[i]<<endl;
    }*/
    cout<<"ok"<<endl;
    ofstream output("output.txt");
	for(int i=0;i<10;i++)
    {
        output<<k[i];
        output<<'\n';
    }
	input.close();
	output.close();
	cin.get();
    return 0;
}
