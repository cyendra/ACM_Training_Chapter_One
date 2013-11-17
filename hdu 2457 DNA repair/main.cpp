#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int kind = 4;
const int OO=1e9;

int cnt_data;

struct node
{
    node *fail;
    node *next[kind];
    int num;
    bool visit;
    bool flag;
    node()
    {
        fail = NULL;
        visit = false;
        flag = false;
        num = cnt_data++;
        memset(next,NULL,sizeof(next));
    }
};
node* data[111111];

node* query_temp_que[1111];

int f[1111][11111];

int get_dna(char c)
{
    if (c=='A') return 0;
    if (c=='G') return 1;
    if (c=='C') return 2;
    if (c=='T') return 3;
    return -1;
}

void insert(node *root,char *str)
{
    node *p=root;
    int i,index;
    int len=strlen(str);
    for (i=0; i<len; i++)
    {
        index=get_dna(str[i]);
        if(p->next[index]==NULL)
        {
            p->next[index]=new node();
            data[cnt_data-1]=p->next[index];
        }
        p=p->next[index];
        if (p->flag) break;
    }
    p->flag=true;
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
                //-------
                if(temp==root) temp->next[i]->fail=root;
                else
                {
                    temp->next[i]->fail=temp->fail->next[i];
                    if (temp->fail->next[i]->flag == true)
                        //说明从root 到 节点temp->next[i]的字符串中 包含子串 从root
                        // 到节点 temp->fail->next[i]的危险DNA序列，故此节点 标记为 1，
                        // 动态规划时不能到此状态。
                        temp->next[i]->flag = true;
                }
                //-------
                Q.push(temp->next[i]);
            }
            else
            {
                if(temp==root) temp->next[i]=root;
                else temp->next[i]=temp->fail->next[i];
            }
        }
    }
}

int query(node *root,char *str)
{
    int index;
    int head,tail;
    int len=strlen(str);
    head=tail=0;
    node *p = root;

    for (int i=0;i<=len;i++)
    {
        for (int j=0;j<=cnt_data;j++)
        {
            f[i][j]=OO;
        }
    }
    f[0][0]=0;
    for (int i=1;i<=len;i++)
    {
        index = get_dna(str[i-1]);
        for (int j=0;j<cnt_data;j++)
        {
            if (f[i-1][j]<OO)
            {
                for (int k=0;k<4;k++)
                {
                    if (!data[j]->next[k]->flag)
                    {
                        p=data[j]->next[k];
                        f[i][p->num]=min(f[i][p->num],f[i-1][j]+(index!=k));
                    }
                }
            }
        }
    }
    int ans=OO;
    for (int j=0;j<cnt_data;j++)
    {
        if (f[len][j]<ans) ans=f[len][j];
    }
    if (ans==OO) return -1;
    return ans;
}


int main()
{
    int n;
    char dna[1111];
    char key[111];
    node* root;
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        cnt_data=0;
        root=new node();
        data[cnt_data-1]=root;
        for (int i=0; i<n; i++)
        {
            scanf("%s",key);
            insert(root,key);
        }
        build_ac_automation(root);
        scanf("%s",dna);
        int ans=query(root,dna);
        printf("Case %d: %d\n",cnt++,ans);
    }
    return 0;
}


