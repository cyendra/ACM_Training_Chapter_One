#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int n;
int vb,vs;
int bus[110];
double ans;
double tmp;
int stb;
int xu,yu;
double si,bi;

int main()
{
    scanf("%d",&n);
    scanf("%d%d",&vb,&vs);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&bus[i]);
    }
    scanf("%d%d",&xu,&yu);
    ans=99999999999999.0;
    stb=0;
    tmp=0;
    for (int i=1; i<n; i++)
    {
        bi=1.0*bus[i]/vb;
        si=1.0*sqrt( 1.0*(bus[i]-xu)*(bus[i]-xu)+yu*yu )/vs;
        tmp=bi+si;
        if ( abs(tmp-ans)<0.000001 )
        {
            if ( (bus[i]-xu)*(bus[i]-xu) < (bus[stb]-xu)*(bus[stb]-xu) )
            {
                ans=tmp;
                stb=i;
            }
        }
        else if ( tmp<ans )
        {
            ans=tmp;
            stb=i;
        }

    }
    printf("%d\n",stb+1);
    return 0;
}
