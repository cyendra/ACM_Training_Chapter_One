#include <iostream>
#include <cstdio>

using namespace std;

int d[4]={1728,144,12,1};

int digit(int t)
{
    int s=0;
    for (int i=1;i<=4;i++)
    {
        int p=t%10;
        t=t/10;
        s+=p;
    }
    return s;
}

int six(int t)
{
    int ret=0;
    int tmp=0;
    for (int i=0;i<4;i++)
    {
        tmp=t%16;
        ret+=tmp;
        t=t/16;
    }
    return ret;
}

int two(int t)
{
    int ret=0;
    int tmp=0;
    for (int i=0;i<4;i++)
    {
        tmp=t%12;
        ret+=tmp;
        t=t/12;
    }
    return ret;
}

int main()
{
    int d=2992;
    for (int i=d;i<=9999;i++)
    {
        if (digit(i)==two(i)&&digit(i)==six(i))
        {
            cout<<i<<endl;
            //getchar();
        }
    }
    return 0;
}
