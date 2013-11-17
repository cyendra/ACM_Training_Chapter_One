#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int x;
    int a;
}DAT;

bool cmp(DAT da,DAT db)
{
    return da.x<db.x;
}

int main()
{
    int n,T;
    int ans;
    DAT arr[1010];
    double d;
    cin >> n >> T;
    for (int i=0;i<n;i++)
    {
        cin >> arr[i].x >> arr[i].a;
    }
    sort(arr,arr+n,cmp);
    ans=0;
    for (int i=0;i<n-1;i++)
    {
        d=(arr[i+1].x-arr[i+1].a*1.0/2.0)-(arr[i].x+arr[i].a*1.0/2.0);
        if (d>T)
        {
            ans=ans+2;
        }
        if (d==T)
        {
            ans=ans+1;
        }
    }
    if (n==0)
    {
        ans=0;
    }
    else
    {
        ans+=2;
    }

    cout << ans << endl;
    return 0;
}
