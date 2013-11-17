#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char str[11111];
char words[1111][44];
int f[11111];
int _cost;
int n;
int pot;

//用类，或者结构体定义都行
struct trie
{
    int next[26];
    int value;
    int cost;
    trie()
    {
       for(int i=0;i<26;i++) next[i]=0;
       value=0;//记录是不是一个单词
       cost=0;
    }
    void init()
    {
        memset(next,0,sizeof(next));
        value=0;
        cost=0;
    }
}mmr[333333];

//插入：
void insert(int root,char* s,int ct)
{
    int p=root;
    int k=0;
    while(s[k]!='\0')
    {
        if(!mmr[p].next[s[k]-'a'])
        {
            mmr[pot].init();
            mmr[p].next[s[k]-'a']=pot++;
        }
        p=mmr[p].next[s[k]-'a'];
        k++;
    }
    mmr[p].value=1;
    mmr[p].cost=ct;
}

//查找
void find(int root,char* s,int pos)
{
    int p=root;
    int k=0;
    while(s[k]!='\0'&&mmr[p].next[s[k]-'a'])
    {
        p=mmr[p].next[s[k]-'a'];
        if (mmr[p].value==1)
        {
            f[pos+k+1]=max(f[pos+k+1],f[pos]+mmr[p].cost);
        }
        k++;
    }
}

int main()
{
    int l;
    int root;
    while (~scanf("%d%s",&n,str+1))
    {
        memset(f,-1,sizeof(f));
        root=1;
        mmr[root].init();
        pot=2;
        l=strlen(str+1);
        for (int i=0;i<n;i++)
        {
            scanf("%s",words[i]);
            scanf("%d",&_cost);
            insert(root,words[i],_cost);
        }
        f[0]=0;
        for (int i=1;i<=l;i++)
        {
            if (f[i-1]!=-1)
            {
                find(root,str+i,i-1);
            }
        }
        printf("%d\n",f[l]);
    }
    return 0;
}


/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,cnt;
int len[1010],num[1010];
char s[10100];
int dp[10100];
queue<int>q;
struct node
{
    int next[26];
    int num;
    void init()
    {
        memset(next,-1,sizeof(next));
        num=0;
    }
}a[50000];
void insert(char s[],int id)
{
    int p=0;
    for(int i=0;s[i];i++)
    {
    int t=s[i]-'a';
    if(a[p].next[t]==-1)
    {
        a[cnt].init();
        a[p].next[t]=cnt++;
    }
    p=a[p].next[t];
    }
    a[p].num=id;
}
void query(char s[])
{
    int p=0;
    while(!q.empty())q.pop();
    for(int i=0;s[i];i++)
    {
    int t=s[i]-'a';
    if(a[p].next[t]==-1)return;
    p=a[p].next[t];
    if(a[p].num)q.push(a[p].num);
    }
}
int main()
{
    int i,j;
    char ss[30];
    while(scanf("%d%s",&m,s+1)!=-1)
    {
    n=strlen(s+1);
    cnt=1;
    a[0].init();
    for(i=1;i<=m;i++)
    {
        scanf("%s%d",ss,&num[i]);
        len[i]=strlen(ss);
        insert(ss,i);
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=1;i<=n;i++)if(dp[i-1]!=-1)
    {
        query(s+i);
        while(!q.empty())
        {
        int k=q.front();q.pop();
        dp[i+len[k]-1]=max(dp[i+len[k]-1],dp[i-1]+num[k]);
        }
    }
    printf("%d\n",dp[n]);
    }
}
*/
