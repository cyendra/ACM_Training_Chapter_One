#include <iostream>

using namespace std;

int main()
{
    long long int p[21],f[21],ans;
    int c,n,m;
    p[0]=1;
    p[1]=1;
    for (int i=2;i<=20;i++)
    {
        p[i]=p[i-1]*i;
    }
    f[0]=0;
    f[1]=0;
    f[2]=1;
    for (int i=3;i<=20;i++)
    {
        f[i]=(f[i-1]+f[i-2])*(i-1);
    }
    cin >> c;
    for (int i=0;i<c;i++)
    {
        cin >> n >> m;
        ans=p[n]/(p[m]*p[n-m]);
        ans=ans*f[m];
        cout << ans << endl;
    }
    return 0;
}
