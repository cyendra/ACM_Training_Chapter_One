#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int CHARSET = 26;
const int MAX_N_NODES = 2111111;
struct Aho_Corasick{
    struct Node{
        Node *next[CHARSET];
        Node *fail;
        int count;//记录当前前缀是完整单词出现的个数
        int sum;
        Node(){
            memset(next,0,sizeof(next));
            fail = NULL;
            count = 0;
            sum=0;
        }
        void clear(){
            memset(next,0,sizeof(next));
            fail = NULL;
            count = 0;
            sum=0;
        }
    };
    queue<Node*>Q;
    Node *root;
    Node nodePool[MAX_N_NODES], *cur;
    Node* newNode(){
        Node* t=cur++;
        t->clear();
        return t;
    }
    void init(){
        cur=nodePool;
        root=newNode();
    }
    void insert(char *str){
        Node* p=root;
        int index;
        int len=strlen(str);
        for (int i=0;i<len;i++){
            index=str[i]-'a';
            if(p->next[index]==NULL) p->next[index]=newNode();
            p=p->next[index];
        }
        p->count++;
    }
    void build_ac_automation(){
        int i;
        while (!Q.empty()) Q.pop();
        root->fail=NULL;
        Q.push(root);
        while(!Q.empty()){
            Node* temp=Q.front();
            Q.pop();
            Node* p=NULL;
            for(i=0;i<CHARSET;i++){
                if(temp->next[i]!=NULL){//寻找当前子树的失败指针
                    if (temp==root){
                        temp->next[i]->fail=temp;
                        temp->next[i]->sum=temp->sum+temp->next[i]->count;
                    }
                    else{
                        p = temp->fail;
                        while(p!=NULL){
                            if(p->next[i]!=NULL){//找到失败指针
                                temp->next[i]->fail=p->next[i];
                                break;
                            }
                            p=p->fail;
                        }
                        if(p==NULL) temp->next[i]->fail=root;//无法获取，当前子树的失败指针为根
                        //==========
                        temp->next[i]->sum=max( temp->sum, temp->next[i]->fail->sum )+temp->next[i]->count;
                        //==========
                    }
                    Q.push(temp->next[i]);
                }
            }
        }
    }
    int query(){//询问str中包含n个关键字中多少种即匹配
        int res=-1;
        for (Node* it=nodePool;it!=cur;it++){
            res=max(res,it->sum);
        }
        return res;
    }
}AC;
int main()
{
    char s[21111];
    int n;
    while (~scanf("%d",&n)){
        if (n==0) break;
        getchar();
        AC.init();
        for (int i=0;i<n;i++){
            //scanf("%s",s);
            gets(s);
            AC.insert(s);
        }
        AC.build_ac_automation();
        int ans=AC.query();
        printf("%d\n",ans);
    }
    return 0;
}
