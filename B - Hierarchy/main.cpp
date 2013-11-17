#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int x,y,z;
int q[1010]={0};
int emp[1010]={0};
long long int cost[1010]={0};

int main()
{
    long long int ans=0;
    int num=0;
    memset(emp,-1,sizeof(emp));
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin>>q[i];
    }
    cin >> m;
    for (int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        if (emp[ y ]==-1||cost[ y ]>z)
        {
            emp[ y ]=x;
            cost[ y ]=z;
        }
    }

    for (int i=1;i<=n;i++)
    {
        if ( emp[i]!=-1 )
        {
            num++;
            ans+=cost[i];
        }
    }

    if ( num==n-1 )
    {
        cout <<ans<<endl;

    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}
