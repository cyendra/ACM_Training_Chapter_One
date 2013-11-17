#include <iostream>

using namespace std;

class Date{
    public:
        void printDate();
        void setDay(int d);
        void setMonth(int m);
        void setYear(int y);
    private:
        int day,month,year;
};

void Date::printDate()
{
    cout<<"year="<<year<<" month="<<month<<" day="<<day<<endl;
}

void Date::setDay(int d)
{
    day=d;
}

void Date::setMonth(int m)
{
    month=m;
}

void Date::setYear(int y)
{
    year=y;
}

int main()
{
    Date testDay;
    testDay.setDay(5);
    testDay.setMonth(10);
    testDay.setYear(2003);
    testDay.printDate();
    return 0;
}
