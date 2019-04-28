#include<iostream>
#include<iomanip>

using namespace std;

int runnian(int year)
{
    if(year%400==0)
    {
        return 1;
    }
    else if(year%4==0&&year%100!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num=8113;//高斯日记写的天数
    int year=1777;
    int month=4;
    int day=30;

    int months[]={31,28,31,30,31,30,31,31,30,31,30,31};

    for(int i=1;i<num;i++)
    {

        if(runnian(year))
        {
            months[1]=29;
        }
        else
        {
            months[1]=28;
        }
        if(day<months[month-1])
        {
            day++;
        }
        else
        {
            day=1;
            month++;

        }
        if(month>12)
        {
            month=1;
            day=1;
            year++;
        }


    }
    cout<<year<<"-"<<setw(2)<<setfill('0')<<month<<"-"<<setw(2)<<setfill('0')<<day;

}
