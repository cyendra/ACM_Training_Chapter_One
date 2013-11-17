#include <iostream>

using namespace std;

class cylinder{
    public:
        cylinder(double a,double b);
        void vol();
    private:
        double r;
        double h;
        double v;
};

cylinder::cylinder(double a,double b)
{
    r=a;
    h=b;
    v=(3.1415926*r*r/2)*h;
}

void cylinder::vol()
{
    cout<<v<<endl;
}

int main()
{
    cylinder cyl_1(4,9);
    cylinder cyl_2(7,3);
    cyl_1.vol();
    cyl_2.vol();
    return 0;
}
