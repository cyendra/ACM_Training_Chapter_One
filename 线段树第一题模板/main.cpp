#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 50005
using namespace std;
int num[N];
struct Tree
{
    int l; //左端点
    int r; //右端点
    int sum; //总数
} tree[N*4]; // 总线段的长度为N，开数组的话一般开到N 的四倍
void build(int root,int l,int r)//root 表示根节点 ，他的区间范围【l,r】
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)// 当左右端点相等时就是叶子节点
    {
        tree[root].sum=num[l]; // 赋除值
        return; // 递归出口
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid); //k<<1相等于k*2 即是他的左孩子
    build(root<<1|1,mid+1,r); //k<<1|1 相当于k*2+1,即是他的右孩子
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum; // 父亲的sum = 左孩子的sum + 右孩子的sum
}
void update(int root,int pos,int val) //root 是根节点，pos，val表示：我们要跟新在pos 点出的值更新为val
{
    if(tree[root].l==tree[root].r) // 如果是叶子节点，即是pos对应的位置
    {
        tree[root].sum=val; // 更新操作
        return; // 递归出口
    }
    int mid=(tree[root].l+ tree[root].r)/2;
    if(pos<=mid) // 如果pos 点是在 root 对应的左孩子的话，就调用 update(k<<1,pos,val);在左孩子里找
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum; // 父亲的sum = 左孩子的sum+ 右孩子的sum
}
int query(int root,int L,int R)// root 表示根节点，[L,R]表示要查询的区间
{
    if(L<=tree[root].l&&R>=tree[root].r) // [L,R]要查询的区间 包含 root 节点表示的区间直接返回root节点的sum 值
        return tree[root].sum;
    int mid=(tree[root].l+ tree[root].r)/2,ret=0;
    if(L<=mid) ret+=query(root<<1,L,R); // 查询 root 节点的左孩子
    if(R>mid) ret+=query(root<<1|1,L,R); // 查询root 节点的右孩子
    return ret; // 返回
}
int main()
{
    int ca,cas=1,n,Q,a,b;
    char str[10];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]); // 表示在i点的兵力数量
        build(1,1,N); // 构造线段树根节点 1，表示的区间范围【1，Ｎ】
        printf("Case %d:\n",cas++);
        while(scanf("%s",str),strcmp(str,"End"))
        {
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Query")==0)
            {
                if(a>b)swap(a,b); // 查询的区间 【a，b】
                printf("%d\n",query(1,a,b)); //输出查询结果
            }
            else if(strcmp(str,"Add")==0)
            {
                num[a]=num[a]+b;
                update(1,a,num[a]); // 跟新 a点值为num[a]
            }
            else if(strcmp(str,"Sub")==0)
            {
                num[a]= num[a]-b;
                update(1,a,num[a]);
            }
        }
    }
    return 0;
}

