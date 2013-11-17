#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct SO
{
    int x;
    int y;
} a[11111];

int t,n;
char s[11111];
int p;

bool cmp(SO a,SO b)
{
    return a.x<b.x;
}

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        p=0;
        for (int i=1; i<=n; i++)
        {
            cin>>a[p].x>>a[p].y;
            p++;
        }
        sort(a,a+p,cmp);
        for (int i=0; i<n; i++)
        {
            int x=a[i].x;
            int y=a[i].y;
            for (int j=1; j<=y; j++)
            {
                cout<<">+";
                for (int k=1; k<=x-2; k++)
                {
                    cout<<"-";
                }
                cout<<"+>"<<endl;
            }
            cout<<endl;
        }

    }
    return 0;
}
