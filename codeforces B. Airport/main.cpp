#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int a[1111];
int b[1111];

int findmax()
{
    int ret=-1;
    int k=0;
    for (int i=1;i<=m;i++)
    {
        if (b[i]>ret)
        {
            ret=b[i];
            k=i;
        }
    }
    return k;
}

int main()
{

    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+m+1);
    int k=n;
    int min_cost=0;
    for (int i=1;i<=m;i++)
    {
        while (a[i]>0&&k>0)
        {
            min_cost+=a[i];
            a[i]--;
            k--;
        }
    }
    int max_cost=0;
    for (int i=1;i<=n;i++)
    {
        int r=findmax();
        max_cost+=b[r];
        b[r]--;
    }
    cout<<max_cost<<" "<<min_cost<<endl;
    return 0;
}
