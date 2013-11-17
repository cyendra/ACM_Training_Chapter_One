#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int p[2222];
vector<int>a[2222];
bool v[2222];
int m;
int n;
int root;
int ansx,ansy;

void dfs(int x,int deep)
{
    int l=a[x].size();
    if (x==1)
    {
        ansx=deep;
    }
    if (x==2)
    {
        ansy=deep;
    }
    for (int i=0;i<l;i++)
    {
        dfs(a[x][i],deep+1);
    }
}

int main()
{
    while (~scanf("%d",&m))
    {
        n=0;
        memset(p,0,sizeof(p));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        for (int i=0;i<=2000;i++) a[i].clear();
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x]=1;
            v[y]=1;
            if (x>n) n=x;
            if (y>n) n=y;
            p[x]=y;
            a[y].push_back(x);
        }
        root=0;
        bool blz=false;
        ansx=0;
        ansy=0;
        for (int i=1;i<=n;i++)
        {
            if (v[i]&&p[i]==0)
            {
                root=i;
                dfs(root,1);
            }
        }
        //cerr<<ansx<<" "<<ansy<<endl;
        if (ansx<ansy)
        {
            printf("You are my younger\n");
        }
        else if (ansx>ansy)
        {
            printf("You are my elder\n");
        }
        else
        {
            printf("You are my brother\n");
        }
    }
    return 0;
}

