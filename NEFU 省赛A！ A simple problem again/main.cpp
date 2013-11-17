#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[111111];

int dfs(double x)
{
    int ret=0;
    if (x<0) return 0;
    if (x>=0&&x<1) return 1;
    int idx=int(x*100);
    //cerr<<idx<<endl;
    if (f[idx]!=-1) return f[idx];
    if (x>=1&&x<=100)
    {
        ret=dfs(x-20.07)%10000+dfs(x-4.28)%10000+dfs(x-20.10)%10000+dfs(x-6.11)%10000;
    }
    ret=ret%10000;
    f[idx]=ret;
    return ret;
}

int main()
{
    int T;
    double x;
    scanf("%d",&T);
    while (T--)
    {
        memset(f,-1,sizeof(f));
        scanf("%lf",&x);
        int ans=dfs(x);
        printf("%d\n",ans);
    }
    return 0;
}

/*

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int dfs(double x)
{
    int ret=0;
    if (x<0) return 0;
    if (x>=0&&x<1) return 1;
    if (x>=1&&x<=100)
    {
        ret=dfs(x-20.07)%10000+dfs(x-4.28)%10000+dfs(x-20.10)%10000+dfs(x-6.11)%10000;
    }
    return ret%10000;
}

int main()
{
    int T;
    double x;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf",&x);
        //cerr<<ip<<endl;
        int ans=dfs(x);
        printf("%d\n",ans);
    }
    return 0;
}


*/
