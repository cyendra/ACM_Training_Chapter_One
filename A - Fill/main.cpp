#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn=222;
const int INF=0x3f3f3f3f;
int ans;
int jugs[3],d;
struct Data{
    int v[3];
    int stp;
    Data(){}
    Data(int x,int y,int z,int b){
        v[0]=x;
        v[1]=y;
        v[2]=z;
        stp=b;
    }
};
queue<Data>que;
bool vis[maxn][maxn][maxn];
void bfs(){
    ans=INF;
    memset(vis,0,sizeof(vis));
    while (!que.empty()) que.pop();
    que.push(Data(0,0,jugs[2],0));
    vis[0][0][jugs[2]]=true;
    while (!que.empty()){
        Data top=que.front();
        que.pop();
        for (int i=0;i<3;i++){
            if (top.v[i]==d){
                ans=min(ans,top.stp);
                break;
            }
            for (int j=0;j<3;j++)
            if (i!=j){
                Data p=top;
                if (top.v[i]&&jugs[j]-top.v[j]){
                    int m=min(top.v[i],jugs[j]-top.v[j]);
                    p.stp+=m;
                    p.v[i]-=m;
                    p.v[j]+=m;
                    if (!vis[p.v[0]][p.v[1]][p.v[2]]){
                        vis[p.v[0]][p.v[1]][p.v[2]]=true;
                        que.push(p);
                    }
                }
            }

        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d",&jugs[0],&jugs[1],&jugs[2],&d);
        bfs();
        while (ans==INF){
            d--;
            bfs();
        }
        printf("%d %d\n",ans,d);
    }
    return 0;
}
