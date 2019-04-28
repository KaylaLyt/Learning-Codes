#include<iostream>
#include<fstream>

using namespace std;

int n,k;
int a[100];


void init_Data()
{
    int i;
    ifstream infile("input.txt",ios::in);
    infile>>n;
    infile>>k;
    for(i = 1; i <= k + 1; i++)
        infile>>a[i];

    infile.close();
}


void out_Resualt(int resualt)
{
    ofstream outfile("output.txt",ios::out);
    outfile<<resualt;
    outfile.close();
}

int least_RefuelTime()
{
    int j = 1;
    int mileage = 0;
    int counter = 0;
    while(j != (k + 1))
    {
        while(mileage <= n)
        {
            mileage += a[j];
            j++;
        }
        counter++;
        mileage = 0;
        j -= 1;
    }
    return counter;
}

int main()
{
    int r;
    init_Data();
    r = least_RefuelTime();
    out_Resualt(r);
}
