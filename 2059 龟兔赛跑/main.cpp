#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int l,n,c,t,vr,vt1,vt2;
double rtime;
int p[110];
double f[110];
double think(int s);
double think(int s)
{
    double ans;
    if (s<=c)
    {
        ans=(double)s / (double)vt1;
    }
    else
    {
        ans=( (double)c / (double)vt1 ) + ( (double)(s-c) / (double)vt2 );
    }
    return ans;
}

int main()
{

    while (cin >> l)
    {
        memset(p,0,sizeof(p));
        cin >> n >> c >> t;
        cin >> vr >> vt1 >> vt2;
        for (int i=1; i<=n; i++)
        {
            cin >> p[i];
        }
        n++;
        p[n]=l;
        for (int i=0; i<=n; i++)
        {
            f[i]=0xffffff;
        }
        f[0]=0;
        for (int i=1; i<=n; i++)
        {
            for (int k=0; k<i; k++)
            {
                if (k==0)
                {
                    f[i]=min(f[i],f[k]+think(p[i]-p[k]));
                }
                else
                {
                    f[i]=min(f[i],f[k]+think(p[i]-p[k])+t);
                }

            }
        }
        rtime=(double)l / (double)vr;
        if (f[n] > rtime )
        {
            cout << "Good job,rabbit!" << endl;
        }
        else
        {
            cout << "What a pity rabbit!" << endl;
        }
    }
    return 0;
}
