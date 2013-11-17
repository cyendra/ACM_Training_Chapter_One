#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int bg;
    int ed;
}DAT;

int n;
DAT a[1111];
int pt[1111];
int ans;

bool cmp(DAT a,DAT b)
{
    return a.ed<b.ed;
}

int main()
{
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].bg>>a[i].ed;
            if (a[i].bg>a[i].ed) swap(a[i].bg,a[i].ed);
        }
        sort(a+1,a+n+1,cmp);
        ans=0;
        pt[0]=-999999;
        for (int i=1;i<=n;i++)
        {
            if ( a[i].bg>pt[ans] )
            {
                ans++;
                pt[ans]=a[i].ed;
            }
        }
        cout<<ans<<endl;
        for (int i=1;i<ans;i++)
        {
            cout<<pt[i]<<" ";
        }
        cout<<pt[ans]<<endl;
    }
    return 0;
}
