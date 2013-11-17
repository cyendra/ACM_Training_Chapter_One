#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int kind = 26;

bool v[33];

char str[1111111];
char words[33];
char mask[33];
char ts[33];
int T,n,m;

int ans,ret;
int a1,a2;

struct node
{
    node *fail;
    node *next[kind];
    int count;
    bool id[33];
    node()
    {
        fail = NULL;
        count = 0;
        memset(id,0,sizeof(id));
        memset(next,NULL,sizeof(next));
    }
};

node* root;
void del_node(node* p)
{
    for (int i=0;i<kind;i++)
    {
        if (p->next[i]) del_node(p->next[i]);
    }
    delete p;
}

void insert(node *root,char *str,int lk)
{
    node *p=root;
    int i=0,index;
    while(str[i])
    {
        index = str[i]-'a';
        if(p->next[index]==NULL) p->next[index]=new node();
        p=p->next[index];
        i++;
    }
    p->count++;
    p->id[lk]=true;
}

void build_ac_automation(node *root)
{
    int i;
    queue<node *>Q;
    root->fail = NULL;
    Q.push(root);
    while(!Q.empty())
    {
        node *temp = Q.front();
        Q.pop();
        node *p = NULL;
        for(i=0; i<kind; i++)
        {
            if(temp->next[i]!=NULL)
            {
                p = temp->fail;
                while(p!=NULL)
                {
                    if(p->next[i]!=NULL)
                    {
                        temp->next[i]->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }
                if(p==NULL) temp->next[i]->fail = root;
                Q.push(temp->next[i]);
            }
        }
    }
}

int query(node *root,char *str)
{
    int i = 0,cnt = 0,index,len;
    len = strlen(str);
    node *p = root;
    while(str[i])
    {
        index = str[i]-'a';
        while(p->next[index]==NULL&&p!=root)
            p=p->fail;
        p=p->next[index];
        if(p==NULL)
            p = root;
        node *temp = p;
        while(temp!=root&&temp->count!=-1)
        {
            for (int k=1;k<=n;k++)
            {
                if (temp->id[k]) v[k]=true;
            }
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
    while (~scanf("%s",str))
    {
        memset(v,0,sizeof(v));
        root=new node;
        ans=0;
        scanf("%d",&m);
        scanf("%s",mask);
        scanf("%d",&n);
        a1=30;
        a2=30;
        for (int i=0;mask[i];i++)
        {
            if (mask[i]=='1')
            {
                if (a1==30) a1=i;
                else a2=i;
            }
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%s",words);
            if (a1==30)
            {
                insert(root,words,i);
            }
            else if (a1!=30)
            {
                if (a2==30)
                {
                    for (int j='a';j<='z';j++)
                    {
                        words[a1]=j;
                        insert(root,words,i);
                    }
                }
                else if(a2!=30)
                {
                    for (int j='a';j<='z';j++)
                    {
                        for (int k='a';k<='z';k++)
                        {
                            words[a1]=j;
                            words[a2]=k;
                            insert(root,words,i);
                        }
                    }
                }
            }
        }
        build_ac_automation(root);
        ret=query(root,str);
        for (int i=1;i<=n;i++)
        {
            if (v[i]) ans++;
        }
        printf("%d\n",ans);
        del_node(root);
    }
    return 0;
}
