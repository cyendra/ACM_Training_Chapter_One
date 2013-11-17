#include <iostream>
#include <cstring>

using namespace std;

int f[2][16000];
int g[30],c[30];
int g1,g2;
int cn,gn;
int tmp;
const int m=7500;

int main()
{
    while (cin>>cn>>gn)
    {
        for (int i=0; i<cn; i++)
        {
            cin>>c[i];
        }
        for (int i=0; i<gn; i++)
        {
            cin>>g[i];
        }
        g1=1;
        g2=0;
        memset(f,0,sizeof(f));
        f[g2][m]=1;
        for (int j=0; j<gn; j++)
        {
            g1=!g1;
            g2=!g2;
            memset(f[g2],0,sizeof(f[g2]));
            for (int k=0; k<m+m; k++)
            {
                for (int i=0; i<cn; i++)
                {
                    tmp=k+c[i]*g[j];
                    if (tmp<0||tmp>=m+m) continue;
                    f[g2][k]+=f[g1][tmp];
                }
            }
        }

        cout<<f[g2][m]<<endl;
    }
    return 0;
}
