#include <iostream>

using namespace std;

typedef long long int LL;

int main()
{
    LL n;
    LL v[5]={0,2,3,5,7};
    LL p[5]={0,1,1,1,1};
    LL a[6000];
    LL t,mint,minp;
    a[1]=1;
    for (int i=2;i<=5842;i++)
    {
        for (int j=1;j<=4;j++)
        {
            t=a[p[j]]*v[j];
            if (j==1)
            {
                mint=t;
                minp=j;
            }
            else if (t<mint)
            {
                mint=t;
                minp=j;
            }
        }
        p[ minp ]++;
        if ( a[i-1]==mint )
        {
            i--;
        }
        else
        {
            a[i]=mint;
        }
    }
    /*
    for (int i=1;i<=20;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    */
    while (cin>>n)
    {
        if (n==0)
        {
            break;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
