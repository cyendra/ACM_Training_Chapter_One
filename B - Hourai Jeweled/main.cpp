#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int maxn=1111111;

__int64 ans,key[maxn],num[maxn],cnt[maxn];
int n;
vector< pair<int,int> >tree[maxn];

void dfs(int v,int pa,int pac)
{
    __int64 lastnum=0,nownum=0,lastcnt=0,nowcnt=0;
    int lastcolor=-1;
    num[v]=key[v];
    cnt[v]=1;
    for (int i=0;i<tree[v].size();i++)
    {
        if (tree[v][i].second!=pa)
        {
            dfs(tree[v][i].second,v,tree[v][i].first);
            if (tree[v][i].first!=lastcolor)
            {
                lastnum=nownum;
                lastcnt=nowcnt;
            }
            lastcolor=tree[v][i].first;
            ans+=lastnum*cnt[tree[v][i].second];
            ans+=lastcnt*num[tree[v][i].second];
            ans+=lastcnt*cnt[tree[v][i].second]*key[v];
            nownum+=num[tree[v][i].second];
            nowcnt+=cnt[tree[v][i].second];
            if (pac!=tree[v][i].first)
            {
                cnt[v]+=cnt[tree[v][i].second];
                num[v]+=num[tree[v][i].second];
                num[v]+=cnt[tree[v][i].second]*key[v];
            }
        }
    }
    if (v!=1)
    {
        ans+=cnt[v]*key[pa];
        ans+=num[v];
    }
}

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%I64d",&key[i]);
            tree[i].clear();
        }
        for (int i=1;i<=n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            tree[a].push_back(make_pair(c,b));
            tree[b].push_back(make_pair(c,a));
        }
        for (int i=1;i<=n;i++)
        {
            sort(tree[i].begin(),tree[i].end());
        }
        ans=0;
        dfs(1,0,-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
