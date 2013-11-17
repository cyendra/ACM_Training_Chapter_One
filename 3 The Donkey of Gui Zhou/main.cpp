#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
const int maxn=1111;
const int dir[4][2]={ {0,1},{1,0},{0,-1},{-1,0} }; //东南西北
int n;
struct Animal{
    int x,y,d;
    int tp;//老虎-1 驴 +1
    bool map[maxn][maxn];
    bool dead;
    Animal(){}
    void setValue(int a,int b,int c,int t){
        x=a;y=b;d=c;tp=t;
        memset(map,0,sizeof(map));
        map[x][y]=true;
        dead=false;
    }
    void turned(){
        d=(d+tp+4)%4;
    }
    bool check(int x,int y){
        if (x>=0&&x<n&&y>=0&&y<n) return true;
        return false;
    }
    void go(){
        if (dead) return;
        int dx=x+dir[d][0];
        int dy=y+dir[d][1];
        if (!check(dx,dy)||map[dx][dy]){
            turned();
            dx=x+dir[d][0];
            dy=y+dir[d][1];
        }
        if (check(dx,dy)&&!map[dx][dy]){
            x=dx;
            y=dy;
            map[x][y]=true;
        }
        else{
            dead=true;
        }
    }
    void show(){
        cerr<<"x= "<<x<<" y="<<y<<endl;
    }
}donkey,tiger;
int main()
{
    while (~scanf("%d",&n)){
        if (n==0) break;
        int r,c,d;
        scanf("%d%d%d",&r,&c,&d);
        donkey.setValue(r,c,d,1);
        scanf("%d%d%d",&r,&c,&d);
        tiger.setValue(r,c,d,-1);
        bool same=false;
        while (!donkey.dead&&!tiger.dead){
            if (donkey.x==tiger.x&&donkey.y==tiger.y){
                same=true;
                break;
            }
            donkey.go();
            tiger.go();
        }
        if (donkey.x==tiger.x&&donkey.y==tiger.y) same=true;
        if (same){
            printf("%d %d\n",tiger.x,tiger.y);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
