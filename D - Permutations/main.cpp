/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct DATA
{
    int v;//值
    int d;//排位
    int c;//集合
};

DATA a[111111];
int p[111111];
int n;

bool cmp1(DATA a,DATA b)
{
    if ( a.v==b.v ) return a.d<b.d;
    else return a.v<b.v;
}
bool cmp2(DATA a,DATA b)
{
    return a.d<b.d;
}

int main()
{
    bool flag=true;
    memset(p,0,sizeof(p));
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i].v;
        a[i].d=i;
        a[i].c=1;
    }
    //for (int i=0;i<n;i++) cout<<a[i].v<<endl;
    //cout<<endl;
    sort(a,a+n,cmp1);
    //for (int i=0;i<n;i++) cout<<a[i].v<<endl;
    int t=0;
    int vl=0;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        if ( a[i].v==vl+1 )
        {
            p[vl]=t;
            if ( vl>1 && p[vl]>p[vl-1] )
            {
                flag=false;
                break;
            }
            vl=a[i].v;
            t=0;
        }
        if ( a[i].v==vl )
        {
            t++;
            a[i].c=t;
            if (t>ans) ans=t;
        }
        else
        {
            flag=false;
            break;
        }
    }
    //for (int i=0;i<=vl;i++) cout<<p[i]<<" ";cout<<endl;
    sort(a,a+n,cmp2);
    if (!flag) cout<<"-1"<<endl;
    else
    {
        cout<<ans<<endl;
        cout<<a[0].c;
        for (int i=1; i<n; i++)
        {
            cout<<" "<<a[i].c;
        }
        cout<<endl;
    }

    return 0;
}
*/

#include<iostream>
using namespace std;
const int N=100005;
int n,a[100005],b[100005];
int ans=0;
int main()
{
    bool flag=true;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[ a[i] ]++;
        ans=max( ans , b[ a[i] ] );
    }
    for(int i=2; i<N; i++)if(b[i]>b[i-1]) flag=false;
    if (!flag) cout<<"-1"<<endl;
    else
    {
        cout<<ans<<endl;
        for (int i=1;i<n;i++)
        {
            cout<<b[ a[i] ]<<" ";
            b[ a[i] ]--;
        }
        cout<<b[ a[n] ]<<endl;
    }
}
