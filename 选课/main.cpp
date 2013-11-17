#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int l[301];
int r[301];
int f[301][301];
int v[301];
int n,m,x,y,p,ans;
int dp(int i,int j);

int dp(int i,int j)
{
    int max=0;
    int tmp=0;
    //printf("%d %d",i,j);getchar();
    if (f[i][j]!=0)
    {
        return f[i][j];
    }
    if ((l[i]==0)and(r[i]!=0))
    {
        tmp=dp(r[i],j);
        f[i][j]=tmp;
        return tmp;
    }
    if ((r[i]==0)and(l[i]!=0))
    {
        tmp=dp(l[i],j-1)+v[i];
        f[i][j]=tmp;
        return tmp;
    }
    if ((l[i]==0)and(r[i]==0))
    {
        f[i][j]=v[i];
        return v[i];
    }

    if (j<=0)
    {
        return 0;
    }
    //不取该节点
    tmp=dp(r[i],j);
    if (tmp>max)
    {
        max=tmp;
    }
    //取该节点
    for (int k=0;k<=j-1;k++)
    {
        //子节点用k-1,兄弟节点用j-k+1
        tmp=dp(l[i],k)+v[i]+dp(r[i],j-k-1);
        if (tmp>max)
        {
            max=tmp;
        }
    }
    f[i][j]=max;
    return (f[i][j]);
}

int main()
{
    while (scanf("%d%d",&n,&m))
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            v[i]=y;
            if (l[x]==0)
            {
                l[x]=i;
            }
            else
            {
                p=l[x];
                while (r[p]!=0)
                {
                    p=r[p];
                }
                r[p]=i;
            }
        }
        //初始化建树完成
        //for (int i=0;i<=n;i++)
        //{
        //    printf("l[%d]=%d,r[%d]=%d,v[%d]=%d\n",i,l[i],i,r[i],i,v[i]);
        //}
        //debug
        ans=dp(0,m);
        printf("%d",ans);
    }
    return 0;
}
