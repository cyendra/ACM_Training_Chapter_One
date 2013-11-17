#include <iostream>
#include <cstring>
using namespace std;

const long long md=1000000007;

long long f[4];
long long d[4];
int n;

int main()
{
    cin>>n;
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    d[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<4;j++)
        {
            f[j]=(d[0]+d[1]+d[2]+d[2]-d[j])%md;
            //f[i&1][j]=(f[!(i&1)][(j+1)%4]+f[!(i&1)][(j+2)%4]+f[!(i&1)][(j+3)%4])%md;
            //cout<<f[j]<<" ";
        }
        d[0]=f[0];
        d[1]=f[1];
        d[2]=f[2];
        d[3]=f[3];
        //cout<<endl;
    }
    cout<<d[0]<<endl;
    return 0;
}
