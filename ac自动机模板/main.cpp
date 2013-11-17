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
    int count;//��¼��ǰǰ׺���������ʳ��ֵĸ���
    node()
    {
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
        index = str[i]-'a';
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
        index = str[i]-'a';
        while(p->next[index]==NULL&&p!=root)//ʧ��
            p=p->fail;
        p=p->next[index];
        if(p==NULL)//ʧ��ָ��Ϊ��
            p = root;

        node *temp = p;
        while(temp!=root&&temp->count!=-1)//Ѱ�ҵ���ǰλ��Ϊֹ�Ƿ���ֲ����ؼ���
        {
            //if(temp->count!=0)
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

    return 0;
}
