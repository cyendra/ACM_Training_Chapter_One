#include <iostream>

using namespace std;

class counter{
    public:
        counter(int number);
        void increment();
        void decrement();
        int getvalue();
        int print();
    private:
        int value;
};

counter::counter(int number)
{
    value=number;
}

void counter::increment()
{
    value++;
}

void counter::decrement()
{
    value--;
}

int counter::getvalue()
{
    return value;
}

int counter::print()
{
    cout<<"value="<<value<<endl;
    return value;
}

int main()
{
    counter cnt(5);
    cnt.increment();
    cnt.increment();
    cnt.increment();
    cnt.decrement();
    int v=cnt.getvalue();
    cout<<v<<endl;
    cnt.print();
    return 0;
}

