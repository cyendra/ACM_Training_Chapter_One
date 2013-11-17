#include <iostream>
#include <algorithm>
using namespace std;

struct co{
    double v;
    int d;
}a[111];

bool cmp(co a,co b)
{
    return a.v<b.v;
}
bool cmp2(co a,co b)
{
    return a.d<b.d;
}

double abs(double x)
{
    if (x<0) return -x;
    else return x;
}

int main()
{
    int n;
    while (cin>>n)
    {
        if (n==0) break;
        double sum=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].v;
            a[i].d=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=2;i<=n-1;i++)
        {
            sum+=a[i].v;
        }
        sort(a+1,a+n+1,cmp2);
        sum/=(n-2);
        int ans=1;
        for (int i=2;i<=n;i++)
        {
            if ( abs(a[i].v-sum)<abs(a[ans].v-sum) )
            {
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
