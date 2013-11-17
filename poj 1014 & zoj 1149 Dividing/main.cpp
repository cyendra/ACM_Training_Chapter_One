#include <iostream>

using namespace std;

int a[10];
int n,k,sum,lp;
bool f[1111111];

void ZeroOnePack(int v)
{
    for (int i=sum-v;i>=0;i--)
    {
        if (f[i]) f[i+v]=true;
    }
}

int main()
{
    lp=0;
    while (true)
    {
        lp++;
        sum=0;
        for (int i=1;i<=6;i++)
        {
            cin>>a[i];
            sum+=a[i]*i;
        }
        if (sum==0) break;
        cout<<"Collection #"<<lp<<":"<<endl;
        if (sum&1)
        {
            cout<<"Can't be divided."<<endl;
            cout<<endl;
            continue;
        }
        sum/=2;
        for (int i=0;i<=sum;i++)
        {
            f[i]=false;
        }
        f[0]=true;
        for (int i=1;i<=6;i++)
        {
            k=1;
            while ( k<a[i] )
            {
                a[i]-=k;
                ZeroOnePack(k*i);
                k*=2;
            }
            ZeroOnePack(a[i]*i);
        }
        if (f[sum])
        {
            cout<<"Can be divided."<<endl;
        }
        else
        {
            cout<<"Can't be divided."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
