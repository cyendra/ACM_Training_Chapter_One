#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct{
    int w;
    int s;
    int c;
}HERO;

HERO a[15000];

typedef struct{
    int num;
    int last;
}ANS;

ANS f[15000];

bool cmp(HERO a,HERO b);

bool cmp(HERO a,HERO b)
{
    if (a.w>b.w)
    {
        return true;
    }
    else if (a.w<b.w)
    {
        return false;
    }
    else
    {
        if (a.s<b.s)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int n=0;
    int tw,ts,max,ans;
    while (cin >> tw >> ts)
    {
        //if (tw==0 && ts==0)
        //{
        //    break;
        //}
        a[n].w=tw;
        a[n].s=ts;
        a[n].c=n+1;
        n++;
    }
    sort(a,a+n,cmp);
    //ºÏ—È
    //for (int i=0;i<n;i++)
    //{
    //    cout << a[i].w << ' ' << a[i].s << endl;
    //}
    for (int i=0;i<n;i++)
    {
        max=0;
        ans=i;
        for (int k=0;k<i;k++)
        {
            if ( (a[k].s<a[i].s) && (a[k].w > a[i].w) )
            {
                if ( f[k].num>max )
                {
                    max=f[k].num;
                    ans=k;
                }
            }
        }
        f[i].num=max+1;
        f[i].last=ans;
    }
    max=0;
    ans=0;
    for (int i=0;i<n;i++)
    {
        if ( f[i].num > max )
        {
            max=f[i].num;
            ans=i;
        }
    }
    cout << max << endl;

    for (int i=0;i<max;i++)
    {
        cout << a[ans].c << endl;
        ans=f[ans].last;
    }
    return 0;
}
