/*
 * Problem: NOI2005 sequence
 * Author: Guo Jiabao
 * Time: 2009.5.30 14:19
 * State: Solved
 * Memo: 伸展树
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=2850003,MAXL=500001,INF=1001;
struct SplayTree
{
    struct SplayNode
    {
        SplayNode *c[2],*f;
        int value,size,sum,maxsum,mls,mrs;
        bool rev,same;
    }*root,*null,*lb,*rb,SS[MAXN];
    int SC;
    SplayNode * NewNode(int value,SplayNode *f)
    {
        SplayNode *e=SS+ ++SC;
        e->value=value;
        e->size=1;e->f=f;
        e->sum=e->maxsum=e->mls=e->mrs=value;
        e->same=e->rev=false;
        e->c[0]=e->c[1]=null;
        return e;
    }
    inline int max(int a,int b){return a>b?a:b;}
    void update(SplayNode *p)
    {
        if (p==null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->sum = p->c[0]->sum + p->c[1]->sum + p->value;
        p->mls = p->c[0]->mls;
        p->mls = max( p->mls , p->c[0]->sum + p->value);
        p->mls = max( p->mls , p->c[0]->sum + p->value + p->c[1]->mls );
        p->mrs = p->c[1]->mrs;
        p->mrs = max( p->mrs , p->c[1]->sum + p->value);
        p->mrs = max( p->mrs , p->c[1]->sum + p->value + p->c[0]->mrs );
        p->maxsum = p->value;
        p->maxsum = max( p->maxsum , p->c[0]->maxsum );
        p->maxsum = max( p->maxsum , p->c[1]->maxsum );
        p->maxsum = max( p->maxsum , p->c[0]->mrs + p->value );
        p->maxsum = max( p->maxsum , p->c[1]->mls + p->value );
        p->maxsum = max( p->maxsum , p->c[0]->mrs + p->c[1]->mls + p->value );
    }
    void pushdown(SplayNode *p)
    {
        if (p==null) return;
        if (p->rev)
        {
            p->rev=false;
            SplayNode *q=p->c[0]; p->c[0]=p->c[1]; p->c[1]=q;
            p->c[0]->rev = !p->c[0]->rev;
            p->c[1]->rev = !p->c[1]->rev;
            int t=p->mls;
            p->mls=p->mrs; p->mrs=t;
        }
        if (p->same)
        {
            p->same=false;
            p->c[0]->same=p->c[1]->same=true;
            p->c[0]->value=p->c[1]->value=p->value;
            p->sum = p->maxsum = p->mls = p->mrs = p->value * p->size;
            if (p->value < 0)
                p->maxsum = p->mls = p->mrs = p->value;
        }
    }
    void rotate(SplayNode *x,int o)//Zig o=0 Zag o=1
    {
        SplayNode *y=x->f;
        pushdown(x->c[0]);
        pushdown(x->c[1]);
        pushdown(y->c[!o]);
        y->c[o] = x->c[!o];
        y->c[o]->f=y;
        x->f = y->f;
        if (y->f->c[0]==y)
            y->f->c[0]=x;
        else
            y->f->c[1]=x;
        y->f=x;
        x->c[!o]=y;
        update(y);
        update(x);
        if (root==y) root=x;
    }
    void splay(SplayNode *x,SplayNode *y)
    {
        pushdown(x);
        while (x->f!=y)
        {
            if (x->f->f==y)
            {
                if (x->f->c[0]==x)
                    rotate(x,0);
                else
                    rotate(x,1);
            }
            else if (x->f->f->c[0] == x->f)
            {
                if (x->f->c[0]==x)
                    rotate(x->f,0),rotate(x,0);
                else
                    rotate(x,1),rotate(x,0);
            }
            else
            {
                if (x->f->c[1]==x)
                    rotate(x->f,1),rotate(x,1);
                else
                    rotate(x,0),rotate(x,1);
            }
        }
    }
    void select(int k,SplayNode *y)
    {
        SplayNode *x=root;
        pushdown(x);
        for (;k != x->c[0]->size + 1;)
        {
            if (k <= x->c[0]->size)
                x=x->c[0];
            else
            {
                k-=x->c[0]->size + 1;
                x=x->c[1];
            }
            pushdown(x);
        }
        splay(x,y);
    }
    void Insert(int pos,int tot,int *C)
    {
        SplayNode *z,*t;
        z=t=NewNode(C[1],null);
        for (int i=2;i<=tot;i++)
            z=z->c[1]=NewNode(C[i],z);
        select(pos+1,null);
        select(pos+2,root);
        root->c[1]->c[0] = t;
        t->f=root->c[1];
        splay(z,null);
    }
    void Delete(int pos,int tot)
    {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0] = null;
        splay(root->c[1],null);
    }
    void MakeSame(int pos,int tot,int value)
    {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0]->same=true;
        root->c[1]->c[0]->value=value;
        splay(root->c[1]->c[0],null);
    }
    void Reverse(int pos,int tot)
    {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0]->rev=!root->c[1]->c[0]->rev;
        splay(root->c[1]->c[0],null);
    }
    int GetSum(int pos,int tot)
    {
        select(pos,null);
        select(pos+tot+1,root);
        pushdown(root->c[1]->c[0]);
        return root->c[1]->c[0]->sum;
    }
    int MaxSum()
    {
        pushdown(root);
        update(root);
        return root->maxsum;
    }
    void init()
    {
        SC=-1;
        null=0;
        null=NewNode(-INF,0);
        null->size=0;
        lb=root=NewNode(-INF,null);
        rb=root->c[1]=NewNode(-INF,root);
        null->sum = lb->sum = rb->sum=0;
        update(root);
    }
}Splay;
int N,M,C[MAXL],pos,i,j,A;
char Ctrl[20];
int main()
{
    freopen("seq2005.in","r",stdin);
    freopen("seq2005.out","w",stdout);
    Splay.init();
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++)
        scanf("%d",&C[i]);
    Splay.Insert(0,N,C);
    for (i=1;i<=M;i++)
    {
        scanf("%s",Ctrl);
        switch (Ctrl[0])
        {
            case 'I':
                scanf("%d%d",&pos,&N);
                for (j=1;j<=N;j++)
                    scanf("%d",&C[j]);
                Splay.Insert(pos,N,C);
                break;
            case 'D':
                scanf("%d%d",&pos,&N);
                Splay.Delete(pos,N);
                break;
            case 'R':
                scanf("%d%d",&pos,&N);
                Splay.Reverse(pos,N);
                break;
            case 'G':
                scanf("%d%d",&pos,&N);
                A=Splay.GetSum(pos,N);
                printf("%d\n",A);
                break;
            case 'M':
                if (Ctrl[2]=='K')
                {
                    scanf("%d%d%d",&pos,&N,&C[0]);
                    Splay.MakeSame(pos,N,C[0]);
                }
                else
                    printf("%d\n",Splay.MaxSum());
                break;
        }
    }
    return 0;
}

/**********************************************************************************
    Splay Tree v1.0 索引
    Node:
        void addIt(int ad) 区间添加ad
        void revIt() 区间翻转
        void upd() 更新结点,子树改变后使用
        void pushdown() 向下传递懒惰标记
    Splay:
        Node* newNode(int v,Node* f) 构造一个val值为v的节点,父节点为f,
        Node* build(int l,int r,Node* f) 构造区间[l,r],父节点为f;
        void rotate(Node* t,int d) 左旋右旋
        void splay(Node* t,Node* f) 将结点t伸展到f
        void select(int k) 返回第k个节点并伸展到f，不计虚拟结点
        Node*&get(int l, int r) 返回区间[l,r]，即l-1旋转到根，r+1旋转到根的右儿子
        void reverse(int l,int r) 翻转区间[l,r]
        void split(int l,int r,Node*&s1) 将区间[l,r]剪切到s1
        void cut(int l,int r) 将区间[l,r]剪切到序列尾部
        void init(int n) 构造区间[1,n]并初始化
        void show(Node* rt) 输出树rt的中序遍历,debug用
        void output(int l,int r) 输出并伸展区间[l,r],复杂度较高待优化
    注意:
        每种修改操作（插入、删除、修改和翻转）过后，
        要将修改的结点（即根结点右子结点的左子结点）Splay到根的位置。
        删除操作要回收空间，可以人工压栈回收结点指针
**********************************************************************************/
/*
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = 150000 + 10;
const int INF = ~0U >> 1;
struct Node{
    Node *ch[2],*pre;//左右子树,父节点
    int val;//关键字
    int size;//以它为根的子树的总结点数
    int mx;//最大值
    int add;//添加标记
    bool rev;//翻转标记
    Node(){
        size=0;
        val=mx=-INF;
        add=0;
    }
    void addIt(int ad){
        add+=ad;
        mx+=ad;
        val+=ad;
    }
    void revIt(){
        rev^=1;
    }
    void upd(){
        size=ch[0]->size+ch[1]->size+1;
        mx=max(val,max(ch[0]->mx,ch[1]->mx));
    }
    void pushdown();
}Tnull,*null=&Tnull;
void Node::pushdown(){
    if (add!=0){
        for (int i=0;i<2;++i)
            if (ch[i]!=null) ch[i]->addIt(add);
        add = 0;
    }
    if (rev){
        swap(ch[0],ch[1]);
        for (int i=0;i<2;i++)
            if (ch[i]!=null) ch[i]->revIt();
        rev = 0;
    }
}
struct Splay{
    Node nodePool[MAX_N],*cur;//内存分配
    Node* root;//根
    Splay(){
        cur=nodePool;
        root=null;
    }
    //清空内存,init()调用
    void clear(){
        cur=nodePool;
        root=null;
    }
    //新建节点,build()用
    Node* newNode(int v,Node* f){
        cur->ch[0]=cur->ch[1]=null;
        cur->size=1;
        cur->val=v;
        cur->mx=v;
        cur->add=0;
        cur->rev=0;
        cur->pre=f;
        return cur++;
    }
    //构造区间[l,r]中点m,init()使用
    Node* build(int l,int r,Node* f){
        if(l>r) return null;
        int m=(l+r)>>1;
        Node* t=newNode(m,f);
        t->ch[0]=build(l,m-1,t);
        t->ch[1]=build(m+1,r,t);
        t->upd();
        return t;
    }
    //旋转操作，c=0表示左旋，c=1表示右旋
    void rotate(Node* x,int c){
        Node* y=x->pre;
        y->pushdown();
        x->pushdown();
        //先将y结点的标记向下传递（因为y在上面）
        y->ch[!c]=x->ch[c];
        if (x->ch[c]!=null) x->ch[c]->pre=y;
        x->pre=y->pre;
        if (y->pre!=null)
        {
            if (y->pre->ch[0]==y) y->pre->ch[0]=x;
            else y->pre->ch[1]=x;
        }
        x->ch[c]=y;
        y->pre=x;
        y->upd();//维护y结点
        if (y==root) root=x;
    }
    //Splay操作，表示把结点x转到结点f的下面
    void splay(Node* x,Node* f){
        x->pushdown();//下传x的标记
        while (x->pre!=f){
            if (x->pre->pre==f){//父节点的父亲为f，执行单旋
                if (x->pre->ch[0]==x) rotate(x,1);
                else rotate(x,0);
            }else{
                Node *y=x->pre,*z=y->pre;
                if (z->ch[0]==y){
                    if (y->ch[0]==x) rotate(y,1),rotate(x,1);//一字型旋转
                    else rotate(x,0),rotate(x,1);//之字形旋转
                }else{
                    if (y->ch[1]==x) rotate(y,0),rotate(x,0);//一字型旋转
                    else rotate(x,1),rotate(x,0);//之字形旋转
                }
            }
        }
        x->upd();//最后再维护X结点
    }
    //找到处在中序遍历第k个结点，并将其旋转到结点f的下面
    void select(int k,Node* f){
        int tmp;
        Node* x=root;
        x->pushdown();
        k++;//空出虚拟节点
        for(;;){
            x->pushdown();
            tmp=x->ch[0]->size;
            if (k==tmp+1) break;
            if (k<=tmp) x=x->ch[0];
            else{
                k-=tmp+1;
                x=x->ch[1];
            }
        }
        splay(x,f);
    }
    //选择[l,r]
    Node*&get(int l, int r){
        select(l-1,null);
        select(r+1,root);
        return root->ch[1]->ch[0];
    }
    //翻转[l,r]
    void reverse(int l,int r){
        Node* o=get(l,r);
        o->rev^=1;
        splay(o,null);
    }
    //剪切出[l,r]到s1
    void split(int l,int r,Node*&s1)
    {
        Node* tmp=get(l,r);
        s1=tmp;
        root->ch[1]->ch[0]=null;
        splay(root->ch[1],null);
    }
    void cut(int l,int r)
    {
        Node* tmp;
        split(l,r,tmp);
        select(root->size-1,null);
        select(root->size-2,root);
        root->ch[0]->ch[1]=tmp;
        tmp->pre=root->ch[0];
        splay(tmp,null);
    }
    //初始化
    void init(int n){
        clear();
        root=newNode(0,null);
        root->ch[1]=newNode(n+1,root);
        root->ch[1]->ch[0]=build(1,n,root->ch[1]);
        root->upd();
    }
    //输出中序遍历,debug用
    void show(Node* rt){
        if (rt==null) return;
        if (rt->ch[0]!=null) show(rt->ch[0]);
        cerr<<"rt="<<rt->val;
        if (rt->ch[0]!=null) cerr<<" l="<<rt->ch[0]->val;
        if (rt->ch[1]!=null) cerr<<" r="<<rt->ch[1]->val;
        if (rt->pre  !=null) cerr<<" pre="<<rt->pre->val;
        cerr<<endl;
        if (rt->ch[1]!=null) show(rt->ch[1]);
    }
    //按序输出
    void output(int l,int r){
        for (int i=l;i<=r;i++){
            select(i,null);
            cout<<root->val<<endl;
        }
        //cout<<endl;
    }

}T;
int main()
{
    int n,m,a,b;
    while (~scanf("%d%d",&n,&m))
    {
        T.init(n);
        while (m--)
        {
            scanf("%d%d",&a,&b);
            if (b<a) swap(a,b);
            T.reverse(a,b);
            T.cut(a,b);
        }
        T.output(1,n);
    }
    return 0;
}
*/
