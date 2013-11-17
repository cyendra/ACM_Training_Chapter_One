//#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
int n,m;
int f[211][21111];
int a[211]={0};
int ans;

int main()
{
    memset(f,0,sizeof(f));
    cin>>n>>m;
    ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]*(n-i+1);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=a[i];j<=m;j++)
        {
            f[i][j]=max( f[i-1][j] , f[i-1][j-a[i]]+1 );
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}

/*
//#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
int n,m;
int f[11111];
int a[111]={0};
int ans;

int main()
{
    memset(f,0,sizeof(f));
    cin>>n>>m;
    ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]*(n-i+1);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=m;j>=a[i];j--)
        {
            f[j]=max( f[j] , f[j-a[i]]+1 );
        }
    }
    cout<< f[m] <<endl;
    return 0;
}
*/

/*
//#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
int n,m;
int p;
int a[111]={0};
int ans;

int main()
{
    cin>>n>>m;
    ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]*(n-i+1);
    }
    sort( a+1,a+n+1 );
    for (int i=1;i<=n;i++)
    {
        if ( m-a[i]>=0 )
        {
            m=m-a[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/
