#include <iostream>

using namespace std;

int a[1111];
int n;
int p[5];
int t;
bool flag;
int cob(int *p)
{
    return p[1]*1000+p[2]*100+p[3]*10+p[4];
}
bool ok=true;

int main()
{
    cin>>n;
    a[0]=1000;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        t=a[i];
        for (int j=4; j>=1; j--)
        {
            p[j]=t%10;
            t/=10;
        }
        flag=false;
        //¼õ
        if (a[i]>a[i-1])
        for (int j=1; j<=4; j++)
        {
            if (!flag)
            {
                while (p[j]>0)
                {
                    p[j]--;
                    if (cob(p)>=a[i-1])
                    {
                        flag=true;
                    }
                    else
                    {
                        p[j]++;
                        break;
                    }
                    //cout<<"now p=="<<cob(p)<<endl;
                }
            }
        }
        a[i]=cob(p);
        //¼Ó
        if (a[i]<a[i-1])
        for (int j=4; j>=1; j--)
        {
            if (!flag)
            {
                t=a[i];
                for (int k=4; k>=1; k--)
                {
                    p[k]=t%10;
                    t/=10;
                }
                while (p[j]<9)
                {
                    p[j]++;
                    if (cob(p)>=a[i-1])
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }
        a[i]=cob(p);
        //if (!flag) ok=false;
    }
    ok=true;
    //cout<<"-------"<<endl;
    for (int i=1; i<=n; i++)
    {
        //cout<<a[i]<<endl;
        if (!(a[i]>=a[i-1]&&a[i]<=2011))
        {
            ok=false;
        }
    }
    //cout<<"------------"<<endl;
    if (ok)
    {
        for (int i=1; i<=n; i++) cout<<a[i]<<endl;
    }
    else
    {
        cout<<"No solution"<<endl;
    }
    return 0;
}
