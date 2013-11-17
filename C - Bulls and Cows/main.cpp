#include <iostream>

using namespace std;

int a[11111]= {0};
bool v[11111]= {0};
int cnt=0;
char g[10];
int t,x,y;
int n;
int err=0;

bool check(int i)
{
    int a,b,c,d;
    a=i%10;
    i/=10;
    b=i%10;
    i/=10;
    c=i%10;
    i/=10;
    d=i%10;
    if (a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int bull(int t,int p)
{
    int ret=0;
    for (int i=0; i<4; i++)
    {
        if (t%10==p%10)
        {
            ret++;
        }
        t/=10;
        p/=10;
    }
    return ret;
}

int cow(int t,int p)
{
    int ret=0;
    int arr1[5];
    int arr2[5];
    for (int i=0; i<4; i++)
    {
        arr1[i]=t%10;
        t/=10;
        arr2[i]=p%10;
        p/=10;
    }
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (arr1[i]==arr2[j]&&i!=j)
            {
                ret++;
                break;
            }
        }
    }
    return ret;
}


int main()
{
    int out;
    for (int i=0; i<=9999; i++)
    {
        if (check(i))
        {
            a[cnt++]=i;
        }
    }
    int ans=cnt;
    cin>>n;
    while (n--)
    {
        cin>>t>>x>>y;
        if (!check(t))
        {
            err=1;
        }
        for (int i=0; i<cnt; i++)
        {
            if (v[i]) continue;
            if (bull(t,a[i])!=x||cow(t,a[i])!=y)
            {
                v[i]=true;
                ans--;
            }
            else
            {
                out=a[i];
            }
        }
    }
    if (err==1||ans<1)
    {
        cout<<"Incorrect data"<<endl;
    }
    else if (ans==1)
    {
        int a,b,c,d;
        a=out%10;
        out/=10;
        b=out%10;
        out/=10;
        c=out%10;
        out/=10;
        d=out%10;
        cout<<d<<c<<b<<a<<endl;
    }
    else if (ans>1)
    {
        cout<<"Need more data"<<endl;
    }
    return 0;
}
