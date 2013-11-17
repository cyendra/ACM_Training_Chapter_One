/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[111]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,
             1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
             1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25
            };
int f[1111];
int g[1111];
int n;

int main()
{
    //freopen("sss.txt","w",stdout);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));

    f[0]=1;
    for (int i=0; i<62; i++)
    {
        for (int j=0; j<=1001; j++)
        {
            if (i<21)
            {
                if (f[j]&&j+a[i]<=1001)
                {
                    f[j+a[i]]=(f[j+a[i]]+f[j])%2011;
                }
            }
            else if (i<41)
            {
                if (f[j]&&j+a[i]*3<=1001)
                    f[j+a[i]*3]=(f[j+a[i]*3]+f[j])%2011;
            }
            else if (i<62)
            {
                if (f[j]&&j+a[i]*2<=1001)
                    f[j+a[i]*2]=(f[j+a[i]*2]+f[j])%2011;
            }

        }
    }
    //for (int i=0;i<100;i++) printf("%d ",f[i]);
    g[0]=1;
    for (int i=0; i<41; i++)
    {
        for (int j=0; j<=1001; j++)
        {
            if (i<21)
            {
                if (g[j]&&j+a[i]<=1001)
                {
                    g[j+a[i]]=(g[j+a[i]]+g[j])%2011;
                }
            }
            else if (i<41)
            {
                if (g[j]&&j+a[i]*3<=1001)
                {
                    g[j+a[i]*3]=(g[j+a[i]*3]+g[j])%2011;
                }

            }
        }
    }
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        printf("%d\n",(f[n]-g[n]+2011)%2011);
    }
    return 0;
}
*/
/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[111]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,
            3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,
            2,4,6,8,10,12,14,16,18,20,22,24,26,38,30,32,34,36,38,40,50};
int f[1111];
int g[1111];
int n;

int main()
{
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));

    f[0]=1;
    for (int i=0; i<62; i++)
    {
        for (int j=0; j<=1001-a[i]; j++)
        {
            if (f[j])
            {
                f[j+a[i]]=(f[j+a[i]]+f[j])%2011;
            }
        }
    }

    g[0]=1;
    for (int i=0; i<41; i++)
    {
        for (int j=0; j<=1001-a[i]; j++)
        {
            if (g[j])
            {
                g[j+a[i]]=(g[j+a[i]]+g[j])%2011;
            }
        }
    }

    while (~scanf("%d",&n))
    {
        if (n==0) break;
        printf("%d\n",(f[n]-g[n]+2011)%2011);
    }
    return 0;
}

*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[111]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,     //21
            3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,   //41
            2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,50};//62
int f[1111];
int g[1111];
int n;

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));

    f[0]=1;
    for (int i=0; i<62; i++)
    {
        for (int j=0; j<=1001-a[i]; j++)
        {
            if (f[j])
            {
                f[j+a[i]]=(f[j+a[i]]+f[j])%2011;
            }
        }
    }
    g[0]=1;
    for (int i=0; i<41; i++)
    {
        for (int j=0; j<=1001-a[i]; j++)
        {
            if (g[j])
            {
                g[j+a[i]]=(g[j+a[i]]+g[j])%2011;
            }
        }
    }
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        printf("%d\n",(f[n]-g[n]+2011)%2011);
    }
    return 0;
}


