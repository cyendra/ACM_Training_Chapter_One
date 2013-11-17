#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long uLL;
const int MAX_N = 450000 + 10;
const int INF = ~0U >> 1;
const int SEED = 7;
uLL xp[MAX_N];
char s[MAX_N];
struct Node{
    Node *ch[2],*pre;//��������,���ڵ�
    int val;//�ؼ���
    int size;//����Ϊ�����������ܽ����
    uLL hash;//��������Ӧ���е�hashֵ
    uLL rush;//��ת���е�hash
    bool rev;//��ת���
    Node(){
        size=hash=rush=0;
        val=0;
    }
    void revIt(){
        rev^=1;
        swap(hash,rush);
    }
    void upd(){
        size=ch[0]->size+ch[1]->size+1;
        hash=ch[0]->hash+val*xp[ch[0]->size]+ch[1]->hash*xp[ch[0]->size+1];
        rush=ch[1]->rush+val*xp[ch[1]->size]+ch[0]->rush*xp[ch[1]->size+1];
    }
    void pushdown();
}Tnull,*null=&Tnull;
void Node::pushdown(){
    if (rev){
        for (int i=0;i<2;i++)
            if (ch[i]!=null) ch[i]->revIt();
        swap(ch[0],ch[1]);
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
        cur->hash=0;
        cur->rush=0;
        cur->rev=0;
        cur->pre=f;
        return cur++;
    }
    //��������[l,r]�е�m,init()ʹ��
    Node* build(int l,int r,Node* f){
        if(l>r) return null;
        int m=(l+r)>>1;
        Node* t=newNode(s[m]-'0',f);
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
    void del(int p){
        select(p-1,null);
        select(p+1,root);
        root->ch[1]->ch[0]=null;
        splay(root->ch[1],null);
    }
    void insert(int p,int v){
        select(p,null);
        select(p+1,root);
        root->ch[1]->ch[0]=newNode(v,root->ch[1]);
        splay(root->ch[1]->ch[0],null);
    }
    //gethash
    uLL hash(int i,int L){
        Node* o=get(i,i+L-1);
        return o->hash;
    }
    //LCS
    int lcs(int i,int j)
    {
        int len=root->size-2;
        int L=1,R=len-max(i,j)+1;
        int ans=0;
        while (L<=R){
            int M=L+(R-L)/2;
            if (hash(i,M)==hash(j,M)){
                ans=M;
                L=M+1;
            }
            else{
                R=M-1;
            }
        }
        return ans;
    }
    //��ʼ��
    void init(int n){
        clear();
        root=newNode(0,null);
        root->ch[1]=newNode(0,root);
        root->ch[1]->ch[0]=build(1,n,root->ch[1]);
        splay(root->ch[1]->ch[0],null);
    }
    //����������,debug��
    void show(Node* rt){
        if (rt==null) return;
        if (rt->ch[0]!=null) show(rt->ch[0]);
        printf("rt=%d size=%d\n",rt->val,rt->size);
        if (rt->ch[1]!=null) show(rt->ch[1]);
    }
    //�������
    void output(int l,int r){
        for (int i=l;i<=r;i++){
            select(i,null);
            cout<<root->val<<" ";
        }
        cout<<endl;
    }

}T;
int n,m;

int main()
{
    int cd;
    int num;
    while (~scanf("%d%d",&n,&m))
    {
        scanf("%s",(s+1));
        xp[0]=1;
        for (int i=1;i<n+m+3;i++) xp[i]=xp[i-1]*SEED;
        T.init(n);
        num=n;
        while (m--)
        {
            scanf("%d",&cd);
            if (cd==1)
            {
                int p,c;
                scanf("%d%d",&p,&c);
                T.insert(p,c);
                num++;
            }
            if (cd==2)
            {
                int p;
                scanf("%d",&p);
                T.del(p);
                num--;
            }
            if (cd==3)
            {
                int p1,p2;
                scanf("%d%d",&p1,&p2);
                T.reverse(p1,p2);
            }
            if (cd==4)
            {
                int p1,p2;
                scanf("%d%d",&p1,&p2);
                printf("%d\n",T.lcs(p1,p2));
            }
        }
    }
    return 0;
}
