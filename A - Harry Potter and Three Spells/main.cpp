#include <iostream>

using namespace std;

double a,b,c,d,e,f,ret;

int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    ret=0;
    if (a==0&&b==0)
    {
        ret=0;
    }
    else if (a==0&&b!=0)
    {
        ret=1e19+9;
    }
    else
    {
        ret=b;
    }

    if (c==0&&d==0)
    {
        ret=0;
    }
    else if (c==0&&d!=0)
    {
        ret=1e19+9;
    }
    else
    {
        ret=ret/c*d;
    }
    if (ret>5000)
    {
        cout<<"Ron"<<endl;
        return 0;
    }
    if (ret==0)
    {
        cout<<"Hermione"<<endl;
        return 0;
    }

    if (e==0&&f==0)
    {
        ret=0;
    }
    else if (e==0&&f!=0)
    {
        ret=1e19+9;
    }
    else
    {
        ret=ret/e*f;
    }

    if (ret>a)
    {
        cout<<"Ron"<<endl;
    }
    else
    {
        cout<<"Hermione"<<endl;
    }

    return 0;
}
