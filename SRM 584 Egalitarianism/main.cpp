#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int maxn=55;

class Egalitarianism{
    private:
        bool a[maxn][maxn];
        int money[maxn];
        int n;
        int ans;
        bool vis[maxn];
        queue<int>que;

        void init()
        {
            ans=0;
            memset(a,0,sizeof(a));
            memset(vis,0,sizeof(vis));
            memset(money,0,sizeof(money));
        }

        void dfs_vis(int u)
        {
            vis[u]=true;
            for (int i=0;i<n;i++)
                if (a[u][i]&&!vis[i]) dfs_vis(i);
        }

        bool check_vis()
        {
            for (int i=0;i<n;i++)
                if (!vis[i]) return false;
            return true;
        }

        void bfs(int u)
        {
            while (!que.empty()) que.pop();
            memset(vis,0,sizeof(vis));
            que.push(u);
            vis[u]=true;
            while (!que.empty())
            {
                int t=que.front();
                que.pop();
                ans=max(ans,money[t]);
                for (int i=0;i<n;i++)
                {
                    if (!vis[i]&&a[t][i])
                    {
                        que.push(i);
                        vis[i]=true;
                        money[i]=money[t]+1;
                    }
                }
            }
        }

    public:
        int maxDifference(vector <string> isFriend, int d)
        {
            init();
            n=isFriend.size();
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    if (isFriend[i][j]=='Y')
                    {
                        a[i][j]=true;
                        a[j][i]=true;
                    }
            dfs_vis(0);
            if (!check_vis()) return -1;
            for (int i=0;i<n;i++)
            {
                memset(money,0,sizeof(money));
                bfs(i);
            }
            ans*=d;
            return ans;
        }
};

int main()
{
    vector<string>vet;
    string s;
    int d;
    Egalitarianism solver;
    int n;
    cin>>n;
    while (n--)
    {
        cin>>s;
        vet.push_back(s);
    }
    cin>>d;
    cout<<solver.maxDifference(vet,d)<<endl;
    return 0;
}
