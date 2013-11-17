#include <iostream>

using namespace std;

int num[4];

bool check()
{
    if ( num[0]==9&&num[1]==9&&num[2]==9 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        for (int i=0;i<3;i++)
        {
            num[i]=n%10;
            n=n/10;
        }
        while( check() )
        {
            num[0]++;
            for (int i=0;i<3;i++)
            {
                if ( num[i]>9 )
                {
                    num[i+1]++;
                    num[i]=num[i]%10;
                }
            }
            for (int i=2;i>=0;i--)
            {
                cout<<num[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
