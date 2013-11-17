#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
const int MOD=20071027;
char str[333333];
char words[4444][111];
int f[333333];

const int CHARSET = 26;
const int MAX_N_NODES = int(3e5) + 10;
struct TrieNode
{
    TrieNode* next[CHARSET];
    int num;//记录是不是一个单词
    int value;//记录单词出现的次数
    TrieNode(){
       memset(next,0,sizeof(next));
       value=0;
       num=0;
    }
    void clear(){
       memset(next,0,sizeof(next));
       value=0;
       num=0;
    }
}*root;
TrieNode nodePool[MAX_N_NODES],*cur;
TrieNode* newNode(){
	TrieNode* t = cur++;
	t->clear();
	return t;
}
void trieInit() {
	cur=nodePool;
	root=newNode();
}
//插入：
void insert(char* s){
    TrieNode* p=root;
    int k=0;
    while(s[k]!='\0'){
        if(!p->next[s[k]-'a']) p->next[s[k]-'a']=newNode();
        p=p->next[s[k]-'a'];
        p->num++;
        k++;
    }
    p->value=1;
}
//查找
int find(char* s){
    TrieNode* p=root;
    int k=0;
    while(s[k]!='\0'&&p->next[s[k]-'a']){
        p=p->next[s[k]-'a'];
        k++;
    }
    if(s[k]=='\0') return p->num;
    return 0;
}
//DP查找
void dpfind(char* s,int pos){
    TrieNode* p=root;
    int k=0;
    while(s[k]!='\0'&&p->next[s[k]-'a']){
        p=p->next[s[k]-'a'];
        if (p->value==1){
            //do something like dp...
            //f[pos+k+1]=(f[pos+k+1]+f[pos])%MOD;
        }
        k++;
    }
}

int main()
{
    int l,s;
    int cnt=0;
    while (~scanf("%s",str+1))
    {
        cnt++;
        memset(f,0,sizeof(f));
        trieInit();
        scanf("%d",&s);
        l=strlen(str+1);
        for (int i=0;i<s;i++)
        {
            scanf("%s",words[i]);
            insert(words[i]);
        }
        f[0]=1;
        for (int i=1;i<=l;i++)
        {
            if (f[i-1])
            {
                dpfind(str+i,i-1);
            }
        }
        printf("Case %d: %d\n",cnt,f[l]);
    }
    return 0;
}
