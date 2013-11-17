#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int iax,iay,ibx,iby,x1,x2,x3,y1,y2,y3;
    int ax[1000];
    int ay[1000];
    bool ok;
    double arccos;
    while (scanf("%d",&n))
    {
        ok=true;
        if (n==0)
        {
            break;
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&ax[i],&ay[i]);
        }
        if (n<3)
        {
            printf("concave\n");
            continue;
        }
        if (n==3)
        {
            printf("convex\n");
            continue;
        }
        for (int i=0;i<n-2;i++)
        {
            iax=ax[i]-ax[i+1];
            iay=ay[i]-ay[i+1];
            ibx=ax[i+2]-ax[i+1];
            iby=ay[i+2]-ay[i+1];
            arccos=(iax*ibx+iay*iby);
            if (arccos>0)
            {
                ok=false;
                break;
            }
        }
        if (ok==true)
        {
            printf("convex\n");
        }
        else
        {
            printf("concave\n");
        }
    }
    return 0;
}
