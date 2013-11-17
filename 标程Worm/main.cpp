/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

FILE *f1;

int main()
{
    int n,p,m,t;
    f1=fopen("worm.in","w");
    for (int lp=0;lp<100;lp++)
    {
        n=3+rand()%20;
        p=3+rand()%n;
        t=3+rand()%n;
        m=3+abs(p-t)+rand()%20;
        if ( ((abs(p-t)&1)+(m&1))==1 )
        {
            m--;
        }
        fprintf(f1,"%d %d %d %d\n",n,p,m,t);
    }
    fclose(f1);
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    FILE *f1;
    int n,p,m,t;
    int f[200][200];
    f1=fopen("worm.out","w");
    while ( cin >> n >> p >> m >> t )
    {
        memset(f,0,sizeof(f));
        f[0][p]=1;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (j>1)
                {
                    f[i][j]+=f[i-1][j-1];
                }
                if (j<n)
                {
                    f[i][j]+=f[i-1][j+1];
                }
            }
        }
        cout << f[m][t] << endl;
        fprintf(f1,"%d\n",f[m][t]);
    }
    fclose(f1);
    return 0;
}

