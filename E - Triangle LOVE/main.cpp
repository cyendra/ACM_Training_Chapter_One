/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=2222;

char s[maxn][maxn];

int inq[maxn];
int n;

bool top_sort()
{
    int num=n;
    queue<int>que;
    for (int i=0;i<n;i++)
        if (!inq[i]) {que.push(i);num--;}
    while (!que.empty())
    {
        int top=que.front();
        que.pop();
        for (int i=0;i<n;i++)
        {
            if (top!=i&&s[top][i]=='1')
            {
                inq[i]--;
                if (!inq[i]) {que.push(i);num--;}
            }
        }
    }
    if (num) return true;
    else return false;

}

int main()
{
    int T,cnt=0;;
    scanf("%d",&T);
    while (T--)
    {
        memset(inq,0,sizeof(inq));
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i!=j&&s[i][j]=='1') inq[j]++;
        bool ret=top_sort();
        printf("Case #%d: ",++cnt);
        if (ret) puts("Yes");
        else puts("No");
    }
    return 0;
}
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
bool v[5555]= {0};
int n;
char s[5555][5555];
bool dfs(int i,int dad)
{
    v[i]=true;
    for (int j=1; j<=n; j++)
        if (s[i][j]-'0')
        {
            if (s[j][dad]-'0') return true;
            if (!v[j]) if (dfs(j,i)) return true;
        }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int lp=1; lp<=T; lp++)
    {
        memset(v,0,sizeof(v));
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
        {
            scanf("%s",s[i]+1);
        }
        printf("Case #%d: ",lp);
        bool flag=false;
        for (int i=1; i<=n; i++)
        {
            if (!v[i])
            {
                if (dfs(i,i)){flag=true;break;}
            }
        }
        if (!flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
