#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct{
    int d;
    int v;
}ASS;

int n;
ASS a[2000];
long int s[2000];
double ans,t;

bool cmp(ASS a,ASS b)
{
    return a.d<b.d;
}

int main()
{
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].d;
            a[i].v=i;
        }
        sort(a+1,a+n+1,cmp);
        s[0]=a[0].d=0;
        t=0;
        for (int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+a[i].d;
            t=t+s[i-1];
        }
        ans=t/n;
        for (int i=1;i<n;i++)
        {
            cout<<a[i].v<<" ";
        }
        cout<<a[n].v<<endl;
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
