#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

unsigned char word[3333333];
unsigned char s[3333333];
unsigned char tcode[3333333];

const int kind = 256;


struct node
{
    node *fail;
    node *next[kind];
    int count;
    bool visit;
    node()
    {
        fail = NULL;
        count = 0;
        visit = false;
        memset(next,NULL,sizeof(next));
    }
};
node* query_temp_que[1111];
void insert(unsigned char *str,node *root,int slen)
{
    node *p=root;
    int i,index;
    for (i=0;i<slen;i++)
    {
        index = (int)str[i];
        if(p->next[index]==NULL) p->next[index]=new node();
        p=p->next[index];
    }
    p->count++;
}

//寻找失败指针
void build_ac_automation(node *root)
{
    int i;
    queue<node *>Q;
    root->fail = NULL;
    Q.push(root);
    while(!Q.empty())
    {
        node *temp=Q.front();//q[head++];//取队首元素
        Q.pop();
        node *p=NULL;
        for(i=0; i<kind; i++)
        {
            if(temp->next[i]!=NULL)//寻找当前子树的失败指针
            {
                p=temp->fail;
                while(p!=NULL)
                {
                    if(p->next[i]!=NULL)//找到失败指针
                    {
                        temp->next[i]->fail=p->next[i];
                        break;
                    }
                    p=p->fail;
                }
                if(p==NULL)//无法获取，当前子树的失败指针为根
                    temp->next[i]->fail=root;
                Q.push(temp->next[i]);
            }
        }
    }
}

//询问str中包含n个关键字中多少种即匹配
int query(unsigned char *str,node *root,int slen)
{
    int i,cnt = 0,index;
    int head,tail;
    head=tail=0;
    node *p = root;
    for (i=0;i<slen;i++)
    {
        index = (int)str[i];
        while(p->next[index]==NULL&&p!=root) p=p->fail;
        p=p->next[index];
        if(p==NULL) p = root;
        node *temp = p;
        while(temp!=root&&!temp->visit)//寻找到当前位置为止是否出现病毒关键字
        {
            cnt+=temp->count;
            temp->visit=true;
            query_temp_que[tail++]=temp;
            temp=temp->fail;
        }
    }
    while (head<tail)
    {
        node* cur=query_temp_que[head++];
        cur->visit=false;
    }
    return cnt;
}

void encode(unsigned char word[],unsigned char s[],int& slen)
{
    int p=0;
    int dcl=0;
    for (int i=0;word[i];i++)
    {
        if (word[i]>='A'&&word[i]<='Z')
        {
            tcode[i]=word[i]-'A';
        }
        if (word[i]>='a'&&word[i]<='z')
        {
            tcode[i]=word[i]-'a'+26;
        }
        if (word[i]>='0'&&word[i]<='9')
        {
            tcode[i]=word[i]-'0'+52;
        }
        if (word[i]=='+')
        {
            tcode[i]=62;
        }
        if (word[i]=='/')
        {
            tcode[i]=63;
        }
        if (word[i]=='=')
        {
            tcode[i]=0;
            dcl++;
        }
    }
    for (int i=0;word[i];i+=4)
    {
        s[p++]= (tcode[i] <<2) | (tcode[i+1] >>4);
        s[p++]= ((tcode[i+1] & 0xf) <<4) | (tcode[i+2] >>2);
        s[p++]= ((tcode[i+2] & 0x3) <<6) | (tcode[i+3]);
    }
    s[p]='\0';
    while (dcl--)
    {
        p--;
        s[p]='\0';
    }
    slen=p;
}

node* root;

int main()
{
    int n,m;
    while (~scanf("%d",&n))
    {
        int slen=0;
        root=new node;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",word);
            encode(word,s,slen);
            insert(s,root,slen);
        }
        build_ac_automation(root);
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%s",word);
            encode(word,s,slen);
            int ans=query(s,root,slen);
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
