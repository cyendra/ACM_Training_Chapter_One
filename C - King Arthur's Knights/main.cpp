#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=222;
int ans[maxn];
bool map[maxn][maxn];
    int n,m;
inline void reverse(int s,int t)
{
    int temp;
    while (s<t)
    {
        temp=ans[s];
        ans[s]=ans[t];
        ans[t]=temp;
        s++;
        t--;
    }
}

void Hamilton()
{
    int s=1,t;
    int ansi=2;
    int i,j;
    int w;
    int temp;
    bool visit[maxn]={0};
    for (i=1;i<=n;i++) if (map[s][i]) break;
    t=i;
    visit[s]=visit[t]=true;
    ans[0]=s;
    ans[1]=t;
    while (1)
    {
        while (1)
        {
            for (i=1;i<=n;i++)
            {
                if (map[t][i]&&!visit[i])
                {
                    ans[ansi++]=i;
                    visit[i]=true;
                    t=i;
                    break;
                }
            }
            if (i>n) break;
        }
        w=ansi-1;
        i=0;
        reverse(i,w);
        temp=s;
        s=t;
        t=temp;
        while (1)
        {
            for (i=1;i<=n;i++)
            {
                if (map[t][i]&&!visit[i])
                {
                    ans[ansi++]=i;
                    visit[i]=true;
                    t=i;
                    break;
                }
            }
            if (i>n) break;
        }
        if (!map[s][t])
        {
            for (i=1;i<ansi-2;i++) if (map[ans[i]][t]&&map[s][ans[i+1]]) break;
            w=ansi-1;
            i++;
            t=ans[i];
            reverse(i,w);
        }
        if (ansi==n) return;
        for (j=1;j<=n;j++)
        {
            if (visit[j]) continue;
            for (i=1;i<ansi-2;i++) if (map[ans[i]][j]) break;
            if (map[ans[i]][j]) break;
        }
        s=ans[i-1];
        t=j;
        reverse(0,i-1);
        reverse(i,ansi-1);
        ans[ansi++]=j;
        visit[j]=true;
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        memset(map,0,sizeof(map));
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=1;
            map[y][x]=1;
        }
        Hamilton();
        printf("%d",ans[0]);
        for (int i=1;i<n;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

