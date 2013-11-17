#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int root[55555];
int kind[55555];//kind[i]表示i与父节点之间的相对关系，0表示相同，1表示吃，2表示被吃

int n,K;

void make_set(int n)
{
    for (int i=0; i<=n; i++)
    {
        root[i]=i;//初始化为n个单独的集合
        kind[i]=0;//根节点的相对关系为0
    }
}

int find_set(int x)
{
    if (root[x]==x) return x;
    int fa=root[x];//记录当前的父节点
    root[x]=find_set(root[x]);//寻找根节点,并指向根节点,注意在这个过程中父节点的kind值发生了改变
    kind[x]=(kind[x]+kind[fa])%3;//与以前的父节点的相对关系不变
    return root[x];
}

bool union_set(int x,int y,int d)
{
    int a=find_set(x);
    int b=find_set(y);
    if (a==b)
    {
        if (d==1&&kind[x]!=kind[y]) return false;
        if (d==2&&((kind[x]-kind[y]+3)%3!=1)) return false;
        return true;
    }
    else
    {
        root[a]=b;//将集合a加入集合b，此时根为b，kind[b]为0。
        if (d==2)//根据d的值处理kind[a]，由x、y之间的kind推出a相对于b的kind
        {
            kind[a]=(kind[y]-kind[x]+1+3)%3;//k'[x]=(k[x]+k[a])%3=k[y]+1变形得k[a]=(k[y]+1-k[x])%3
        }
        else if (d==1)
        {
            kind[a]=(kind[y]-kind[x]+3)%3;//k'[x]=(k[x]+k[a])%3=k[y]变形得k[a]=(k[y]-k[x])%3
        }
        return true;
    }
}

int main()
{
    int x,y,d;
    scanf("%d%d",&n,&K);
    make_set(n);
    int ans=0;
    for (int lp=1; lp<=K; lp++)
    {
        scanf("%d%d%d",&d,&x,&y);
        if (x>n||y>n||(x==y&&d==2))
        {
            ans++;
            continue;
        }
        if (!union_set(x,y,d)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
