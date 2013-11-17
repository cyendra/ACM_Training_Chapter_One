#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//�����ڵ����ڲ���ʱnew�ģ�
//Ѱ��ʧ��ָ����ʹ�õĶ�����ֱ�ӵ���STL��
const int kind = 26;
struct node
{
    node *fail;
    node *next[kind];
    bool fff;
    int count;//��¼��ǰǰ׺���������ʳ��ֵĸ���
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

//Ѱ��ʧ��ָ��
void build_ac_automation(node *root)
{
    int i;
    queue<node *>Q;
    root->fail = NULL;
    Q.push(root);
    while(!Q.empty())
    {
        node *temp = Q.front();//q[head++];//ȡ����Ԫ��
        Q.pop();
        node *p = NULL;
        for(i=0; i<kind; i++)
        {
            if(temp->next[i]!=NULL)//Ѱ�ҵ�ǰ������ʧ��ָ��
            {
                p = temp->fail;
                while(p!=NULL)
                {
                    if(p->next[i]!=NULL)//�ҵ�ʧ��ָ��
                    {
                        temp->next[i]->fail = p->next[i];
                        break;
                    }
                    p = p->fail;
                }

                if(p==NULL)//�޷���ȡ����ǰ������ʧ��ָ��Ϊ��
                    temp->next[i]->fail = root;

                Q.push(temp->next[i]);
            }
        }
    }
}

//ѯ��str�а���n���ؼ����ж����ּ�ƥ��
int query(char *str,node *root)
{
    int i = 0,cnt = 0,index,len;
    len = strlen(str);
    node *p = root;
    while(str[i])
    {
        index = str[i]-'A';
        while(p->next[index]==NULL&&p!=root)//ʧ��
            p=p->fail;
        p=p->next[index];
        if(p==NULL)//ʧ��ָ��Ϊ��
            p = root;

        node *temp = p;
        while(temp!=root&&temp->count!=-1)//Ѱ�ҵ���ǰλ��Ϊֹ�Ƿ���ֲ����ؼ���
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

