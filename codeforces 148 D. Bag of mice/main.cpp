#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double f[1111][1111][2];//×ó°×£¬ÓÒºÚ
bool vis[1111][1111][2];

double dfs(int w,int b,int turn)
{
    if (vis[w][b][turn]) return f[w][b][turn];
    double ret=0;
    if (turn==0)
    {
        if (w>=1) ret+=1.0*w/(w+b);
        if (b>=1) ret+=1.0*b/(w+b)*dfs(w,b-1,1);
    }
    else if (turn==1)
    {
        if (w>=1&&b>=1) ret+=1.0*b/(w+b)*1.0*w/(w+b-1)*dfs(w-1,b-1,0);
        if (b>=2) ret+=1.0*b/(w+b)*1.0*(b-1)/(w+b-1)*dfs(w,b-2,0);
    }
    vis[w][b][turn]=true;
    f[w][b][turn]=ret;
    return ret;
}

int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    printf("%0.9lf\n",dfs(w,b,0));
    return 0;
}

/*
int main()
{
    scanf("%d%d",&w,&b);
    memset(f,0,sizeof(f));
    for (int i=0;i<=w;i++)
    {
        for (int j=0;j<=b;j++)
        {
            if (i!=0) f[i][j][0]= 1.0*i/(i+j);
            if (j!=0) f[i][j][0]+= 1.0*j/(i+j)*f[i][j-1][1];
            if (i>=1&&j>=1) f[i][j][1]= 1.0*j/(i+j)*1.0*i/(i+j-1)*f[i-1][j-1][0];
            if (j>=2) f[i][j][1]+= 1.0*j/(i+j)*1.0*(j-1)/(i+j-1)*f[i][j-2][0];
        }
    }
    printf("%0.9lf\n",f[w][b][0]);
    return 0;
}

*/
