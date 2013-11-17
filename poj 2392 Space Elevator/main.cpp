#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int a;
    int h;
    int c;
}PP;

PP d[500];
bool f[111111];
int n;
int ans;

bool cmp(PP x,PP y)
{
    return x.a<y.a;
}

int main()
{
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>d[i].h>>d[i].a>>d[i].c;
        }
        sort(d+1,d+n+1,cmp);
        for (int i=0;i<=d[n].a;i++) f[i]=0;
        f[0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=d[i].c;j++)
            {
                for (int k=d[i].a-d[i].h;k>=0;k--)
                {
                    if (f[k]) f[k+d[i].h]=true;
                }
            }
        }
        for (int i=d[n].a;i>=0;i--)
        {
            if (f[i])
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
