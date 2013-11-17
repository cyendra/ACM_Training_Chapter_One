#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1111;
typedef unsigned int uint;
const int Size=30;
class SetOperation{
private:
    uint st[400];
    int getIdx(int num){
        return num/Size;
    }
    int getLft(int num){
        return num%Size;
    }
public:
    SetOperation(){
        init();
    }
    void init(){
        memset(st,0,sizeof(st));
    }
    void addVal(int num){
        st[getIdx(num)]|=(1<<getLft(num));
    }
    void delVal(int num){
        st[getIdx(num)]&=~(1<<getLft(num));
    }
    void chgVal(int num){
        st[getIdx(num)]^=(1<<getLft(num));
    }
    bool inSet(int num){
        return st[getIdx(num)]&(1<<getLft(num));
    }
}a[maxn];
int main()
{
    int n,m;
    while (~scanf("%d",&n)){
        for (int i=1;i<=n;i++){
            a[i].init();
            scanf("%d",&m);
            while (m--){
                int num;
                scanf("%d",&num);
                a[i].addVal(num);
            }
        }
        scanf("%d",&m);
        while(m--){
            int x,y;
            bool flag=false;
            scanf("%d%d",&x,&y);
            for (int i=1;i<=n;i++){
                if (a[i].inSet(x)&&a[i].inSet(y)){
                    flag=true;
                    break;
                }
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
