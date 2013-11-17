#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct STU{
    char t[1111];
    int d;
    int c;
    int dick;
}a[1111];

bool v[10];
int ac[10];

int n;

bool cmp(STU a,STU b)
{
    if (a.d==b.d) return (strcmp(a.t,b.t)<0);
    return a.d>b.d;
}
bool cmp2(STU a,STU b)
{
    return a.dick<b.dick;
}

int main()
{
    while (cin>>n)
    {
        if (n<0) break;
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(ac,0,sizeof(ac));
        for (int i=0;i<n;i++)
        {
            cin>>a[i].d;
            cin>>a[i].t;
            a[i].dick=i;
            ac[a[i].d]++;
        }
        v[0]=true;
        v[5]=true;
        for (int i=1;i<=4;i++) ac[i]/=2;
        sort(a,a+n,cmp);
        for (int i=0;i<n;i++)
        {
            if (a[i].d==5) a[i].c=100;
            else if (a[i].d==4) a[i].c=90;
            else if (a[i].d==3) a[i].c=80;
            else if (a[i].d==2) a[i].c=70;
            else if (a[i].d==1) a[i].c=60;
            else if (a[i].d==0) a[i].c=50;
            if ( !v[a[i].d]&&ac[a[i].d]>0 )
            {
                ac[a[i].d]--;
                a[i].c+=5;
            }
        }
        sort(a,a+n,cmp2);
        for (int i=0;i<n;i++)
        {
            cout<<a[i].c<<endl;
        }
        cout<<endl;
    }
    return 0;
}
