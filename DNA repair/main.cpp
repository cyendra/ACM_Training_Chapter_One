#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int CHARSET = 26;
const int MAX_N_NODES = int(3e5) + 10;
int f[1111][11111];
int get_DNA(char c)
{
    if (c=='A') return 0;
    if (c=='G') return 1;
    if (c=='C') return 2;
    if (c=='T') return 3;
    return -1;
}
struct Node
{
    Node *next[CHARSET];
    Node *fail;
    int count;//记录当前前缀是完整单词出现的个数
    Node(){
        memset(next,0,sizeof(next));
        fail = NULL;
        count = 0;
    }
    void clear(){
        memset(next,0,sizeof(next));
        fail = NULL;
        count = 0;
    }
}*root;
Node nodePool[MAX_N_NODES], *cur;
Node* newNode(){
	Node* t=cur++;
    t->clear();
	return t;
}
void ACinit(){
	cur=nodePool;
	root=newNode();
}
void insert(char *str){
    Node* p=root;
    int i=0,index;
    while(str[i]!='\0'){
        index=str[i]-'a';
        if(p->next[index]==NULL) p->next[index]=newNode();
        p=p->next[index];
        i++;
    }
    p->count++;
}

//寻找失败指针
void build_ac_automation()
{
    int i;
    queue<Node*>Q;
    root->fail=NULL;
    Q.push(root);
    while(!Q.empty())
    {
        Node* temp=Q.front();
        Q.pop();
        Node* p=NULL;
        for(i=0;i<CHARSET;i++){
            if(temp->next[i]!=NULL){//寻找当前子树的失败指针
                p = temp->fail;
                while(p!=NULL){
                    if(p->next[i]!=NULL){//找到失败指针
                        temp->next[i]->fail=p->next[i];
                        break;
                    }
                    p=p->fail;
                }
                if(p==NULL) temp->next[i]->fail=root;
                //无法获取，当前子树的失败指针为根
                Q.push(temp->next[i]);
            }
        }
    }
}
//询问str中包含n个关键字中多少种即匹配
int query(char *str){
    int i=0,cnt=0,index;
    Node* p = root;
    while(str[i]){
        index=str[i]-'a';
        while(p->next[index]==NULL&&p!=root) p=p->fail;//失配
        p=p->next[index];
        if(p==NULL) p = root;//失配指针为根
        Node* temp = p;
        while(temp!=root&&temp->count!=-1)//寻找到当前位置为止是否出现关键字
        {
            cnt+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}


int main()
{
    int n;
    char DNA[1111];
    char key[111];
    int cas=0;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        ACinit();
        REP(i,n)
        {
            scanf("%s",key);
            insert(key);
        }
        build_ac_automation();
        scanf("%s",DNA);
        int ans=query(DNA);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

