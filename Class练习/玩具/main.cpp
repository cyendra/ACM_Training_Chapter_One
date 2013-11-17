#include <iostream>

using namespace std;

class toy{
    public:
        toy(double p);
        void sale(int n);
        double get_sum();
    private:
        static double sum;
        double price;
        int num;
};

double toy::sum=0;

toy::toy(double p=0)
{
    price=p;
}

void toy::sale(int n)
{
    num+=n;
    sum+=price*n;
}

double toy::get_sum()
{
    return sum;
}


int main()
{
    toy a[5]={1.3,2.6,9.5,3.55,12.33};
    for (int i=0;i<5;i++)
    {
        a[i].sale(i);
    }
    cout<<a[0].get_sum()<<endl;
    return 0;
}
