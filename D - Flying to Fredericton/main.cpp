#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=211;
const int maxm=2111;
map<string,int>mp;
char name[111111];
int S,T;


struct EdgeNode{
    int to;
    int w;
    int next;
};
struct BellmanFord{
    EdgeNode edges[maxm];
    int head[maxn],edge,n;
    bool inq[maxn][maxn];
    queue< pair<int,int> >que;
    int dis[maxn][maxn];
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    void init(int n){
        memset(head,-1,sizeof(head));
        edge=0;
        this->n=n;
    }
    bool spfa(int s,int len){
        int u;
        memset(dis,INF,sizeof(dis));
        memset(inq,0,sizeof(inq));
        while (!que.empty()) que.pop();
        dis[0][s]=0;
        inq[0][s]=true;
        que.push( make_pair(0,s) );
        while (!que.empty()){
            int tim=que.front().first;
            u=que.front().second;
            que.pop();
            inq[tim][u]=false;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                int w=edges[i].w;
                if ( tim+1<=len&&dis[tim+1][v]>dis[tim][u]+w ){
                    dis[tim+1][v]=dis[tim][u]+w;
                    //do something

                    //nice try
                    if (!inq[tim+1][v]){
                        inq[tim+1][v]=true;
                        que.push( make_pair(tim+1,v) );
                    }
                }
            }
        }
        return true;
    }
}solver;


int n,m;
int main()
{
    int TMD;
    int cas=0;
    scanf("%d",&TMD);
    while (TMD--){
        //input()
        scanf("%d",&n);
        solver.init(n);
        for (int i=1;i<=n;i++){
            scanf("%s",name);
            mp[name]=i;
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            int x,y,c;
            scanf("%s",name);
            x=mp[name];
            scanf("%s",name);
            y=mp[name];
            scanf("%d",&c);
            solver.addedge(x,y,c);
        }
        S=mp["Calgary"];
        T=mp["Fredericton"];
        //Solve()
        int Q,qst;
        printf("Scenario #%d\n",++cas);
        scanf("%d",&qst);
        while (qst--){
            scanf("%d",&Q);
            Q++;
            if (Q>n) Q=n;
            if (Q<1) Q=1;
            solver.spfa(S,Q);
            int ans=INF;
            for(int i=0;i<=Q;i++)
                ans=min(ans,solver.dis[i][T]);
            if (ans==INF){
                printf("No satisfactory flights\n");
            }else{
                printf("Total cost of flight(s) is $%d\n",ans);
            }
        }
        if (TMD!=0) puts("");
    }
    return 0;
}
