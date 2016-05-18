#include<iostream>
using namespace std;

int is_leap_year(int year)
{
    if(year % 4 != 0 || (year % 100 ==0 && year%400 != 0)) return 0;
    return 1;
}

int main()
{
    int year=100;
    while(year>10)
    {
        cin>>year;
        cout<<is_leap_year(year)<<endl;
    }
    
    return 0;
}
