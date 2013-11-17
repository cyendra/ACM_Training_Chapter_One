/*
 * Problem: NOI2005 sequence
 * Author: Guo Jiabao
 * Time: 2009.5.30 14:19
 * State: Solved
 * Memo: ��չ��
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
    Splay Tree v1.0 ����
    Node:
        void addIt(int ad) �������ad
        void revIt() ���䷭ת
        void upd() ���½��,�����ı��ʹ��
        void pushdown() ���´���������
    Splay:
        Node* newNode(int v,Node* f) ����һ��valֵΪv�Ľڵ�,���ڵ�Ϊf,
        Node* build(int l,int r,Node* f) ��������[l,r],���ڵ�Ϊf;
        void rotate(Node* t,int d) ��������
        void splay(Node* t,Node* f) �����t��չ��f
        void select(int k) ���ص�k���ڵ㲢��չ��f������������
        Node*&get(int l, int r) ��������[l,r]����l-1��ת������r+1��ת�������Ҷ���
        void reverse(int l,int r) ��ת����[l,r]
        void split(int l,int r,Node*&s1) ������[l,r]���е�s1
        void cut(int l,int r) ������[l,r]���е�����β��
        void init(int n) ��������[1,n]����ʼ��
        void show(Node* rt) �����rt���������,debug��
        void output(int l,int r) �������չ����[l,r],���ӶȽϸߴ��Ż�
    ע��:
        ÿ���޸Ĳ��������롢ɾ�����޸ĺͷ�ת������
        Ҫ���޸ĵĽ�㣨����������ӽ������ӽ�㣩Splay������λ�á�
        ɾ������Ҫ���տռ䣬�����˹�ѹջ���ս��ָ��
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
    Node *ch[2],*pre;//��������,���ڵ�
    int val;//�ؼ���
    int size;//����Ϊ�����������ܽ����
    int mx;//���ֵ
    int add;//��ӱ��
    bool rev;//��ת���
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
    Node nodePool[MAX_N],*cur;//�ڴ����
    Node* root;//��
    Splay(){
        cur=nodePool;
        root=null;
    }
    //����ڴ�,init()����
    void clear(){
        cur=nodePool;
        root=null;
    }
    //�½��ڵ�,build()��
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
    //��������[l,r]�е�m,init()ʹ��
    Node* build(int l,int r,Node* f){
        if(l>r) return null;
        int m=(l+r)>>1;
        Node* t=newNode(m,f);
        t->ch[0]=build(l,m-1,t);
        t->ch[1]=build(m+1,r,t);
        t->upd();
        return t;
    }
    //��ת������c=0��ʾ������c=1��ʾ����
    void rotate(Node* x,int c){
        Node* y=x->pre;
        y->pushdown();
        x->pushdown();
        //�Ƚ�y���ı�����´��ݣ���Ϊy�����棩
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
        y->upd();//ά��y���
        if (y==root) root=x;
    }
    //Splay��������ʾ�ѽ��xת�����f������
    void splay(Node* x,Node* f){
        x->pushdown();//�´�x�ı��
        while (x->pre!=f){
            if (x->pre->pre==f){//���ڵ�ĸ���Ϊf��ִ�е���
                if (x->pre->ch[0]==x) rotate(x,1);
                else rotate(x,0);
            }else{
                Node *y=x->pre,*z=y->pre;
                if (z->ch[0]==y){
                    if (y->ch[0]==x) rotate(y,1),rotate(x,1);//һ������ת
                    else rotate(x,0),rotate(x,1);//֮������ת
                }else{
                    if (y->ch[1]==x) rotate(y,0),rotate(x,0);//һ������ת
                    else rotate(x,1),rotate(x,0);//֮������ת
                }
            }
        }
        x->upd();//�����ά��X���
    }
    //�ҵ��������������k����㣬��������ת�����f������
    void select(int k,Node* f){
        int tmp;
        Node* x=root;
        x->pushdown();
        k++;//�ճ�����ڵ�
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
    //ѡ��[l,r]
    Node*&get(int l, int r){
        select(l-1,null);
        select(r+1,root);
        return root->ch[1]->ch[0];
    }
    //��ת[l,r]
    void reverse(int l,int r){
        Node* o=get(l,r);
        o->rev^=1;
        splay(o,null);
    }
    //���г�[l,r]��s1
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
    //��ʼ��
    void init(int n){
        clear();
        root=newNode(0,null);
        root->ch[1]=newNode(n+1,root);
        root->ch[1]->ch[0]=build(1,n,root->ch[1]);
        root->upd();
    }
    //����������,debug��
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
    //�������
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
