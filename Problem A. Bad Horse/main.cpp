#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

map<string,int>mp;
char name1[1111],name2[1111];
int n;
int T,m;
int a[111][111];
int cl[111];
bool dfs(int u){
    for (int v=1;v<=n;v++){
        if (u!=v&&a[u][v]==1){
            if (cl[v]!=0&&cl[u]==cl[v]) return false;
            if (!cl[v]){
                cl[v]=3-cl[u];
                if (!dfs(v)) return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("A-small-2-attempt0.in","r",stdin);
    freopen("A-small-2-attempt0.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        scanf("%d",&m);
        mp.clear();
        memset(a,0,sizeof(a));
        n=0;
        for (int i=1;i<=m;i++){
            scanf("%s%s",name1,name2);
            int x,y;
            if (mp.find(name1)==mp.end()){
                mp[name1]=++n;
                x=n;
            }
            else{
                x=mp[name1];
            }
            if (mp.find(name2)==mp.end()){
                mp[name2]=++n;
                y=n;
            }
            else{
                y=mp[name2];
            }
            a[x][y]=1;
            a[y][x]=1;
        }
        memset(cl,0,sizeof(cl));
        if (dfs(1)){
            printf("Case #%d: Yes\n",cas);
        }
        else{
            printf("Case #%d: No\n",cas);
        }
    }
    return 0;
}
