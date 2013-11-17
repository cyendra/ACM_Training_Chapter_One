#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//子树节点是在插入时new的，
//寻找失配指针中使用的队列是直接调用STL的
const int kind = 26;
struct node
{
    node *fail;
    node *next[kind];
    bool fff;
    int count;//记录当前前缀是完整单词出现的个数
    node()
    {
        fff=false;
        fail = NULL;
        count = 0;
        memset(next,NULL,sizeof(next));
    }
};

void insert(char *str,node *root)
{
    node *p=root;
    int i=0,index;
    while(str[i])
    {
        index = str[i]-'A';
        if(p->next[index]==NULL) p->next[index]=new node();
        p=p->next[index];
        i++;
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
        node *temp = Q.front();//q[head++];//取队首元素
        Q.pop();
        node *p = NULL;
        for(i=0; i<kind; i++)
        {
            if(temp->next[i]!=NULL)//寻找当前子树的失败指针
            {
                p = temp->fail;
                while(p!=NULL)
                {
                    if(p->next[i]!=NULL)//找到失败指针
                    {
                        temp->next[i]->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }

                if(p==NULL)//无法获取，当前子树的失败指针为根
                    temp->next[i]->fail = root;

                Q.push(temp->next[i]);
            }
        }
    }
}

//询问str中包含n个关键字中多少种即匹配
int query(char *str,node *root)
{
    int i = 0,cnt = 0,index,len;
    len = strlen(str);
    node *p = root;
    while(str[i])
    {
        index = str[i]-'A';
        while(p->next[index]==NULL&&p!=root)//失配
            p=p->fail;
        p=p->next[index];
        if(p==NULL)//失配指针为根
            p = root;

        node *temp = p;
        while(temp!=root&&temp->count!=-1)//寻找到当前位置为止是否出现病毒关键字
        {
            cnt+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}

char str[6100000];
char s1[6100000];
char s2[6100000];
char words[1111111];
int T,n;
node* root;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        root=new node();
        scanf("%d",&n);
        while (n--)
        {
            scanf("%s",words);
            insert(words,root);
        }
        build_ac_automation(root);
        getchar();
        char sc;
        int j=0;
        while (scanf("%c",&sc))
        {
            if (!( ((sc>='A')&&(sc<='Z')) || ((sc>='0')&&(sc<='9')) || (sc=='[') || (sc==']') )) break;
            if (sc>='A'&&sc<='Z')
            {
                s1[j++]=sc;
            }
            else if (sc=='[')
            {
                int d;
                char c;
                scanf("%d%c",&d,&c);
                getchar();
                while (d--)
                {
                    s1[j++]=c;
                }
            }
        }
        s1[j]='\0';
        int l=strlen(s1);
        for (int i=0; i<l; i++)
        {
            s2[i]=s1[l-i-1];
        }
        s2[l]='\0';
        //cerr<<endl<<s1<<endl<<s2<<endl<<endl;
        int reta=query(s1,root);
        int retb=query(s2,root);
        printf("%d\n",reta+retb);
    }
    return 0;
}

