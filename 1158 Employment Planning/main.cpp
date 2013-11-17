#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[20];
int f[20][1000];
int main()
{
    int months;
    int hiring,salary,firing;
    int maxpeople;
    int tmp;
    while (cin>>months)
    {
        if (months==0)
        {
            break;
        }
        memset(f,0,sizeof(f));
        maxpeople=0;
        cin >> hiring >> salary >> firing;
        for (int i=0;i<months;i++)
        {
            cin >> a[i];
            if (a[i]>maxpeople)
            {
                maxpeople=a[i];
            }
        }
        for (int i=a[0];i<=maxpeople;i++)
        {
            f[0][i]=i*hiring+i*salary;
        }
        for (int i=1;i<months;i++)
        {
            for (int j=a[i];j<=maxpeople;j++)
            {
                for (int k=a[i-1];k<=maxpeople;k++)
                {
                    if (j==k)
                    {
                        tmp=0;
                    }
                    else if (j>k)
                    {
                        tmp=(j-k)*hiring;
                    }
                    else if (j<k)
                    {
                        tmp=(k-j)*firing;
                    }
                    if ( f[i][j]==0 )
                    {
                        f[i][j]=f[i-1][k]+tmp+j*salary;
                    }
                    else
                    {
                        if ( f[i-1][k] + tmp+j*salary < f[i][j] )
                        {
                            f[i][j]= f[i-1][k]+tmp+j*salary;
                        }
                    }
                }
            }
        }
        tmp=9999999;
        for (int i=a[months-1];i<=maxpeople;i++)
        {
            if (f[months-1][i]<tmp)
            {
                tmp=f[months-1][i];
            }
        }
        cout << tmp << endl;
    }
    return 0;
}
