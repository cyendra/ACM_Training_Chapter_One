#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

char words[1111][111111];
bool ok;

//���࣬���߽ṹ�嶨�嶼��
struct trie
{
    trie* next[26];
    int num;
    int value;
    trie()
    {
       for(int i=0;i<26;i++) next[i]=NULL;
       value=0;//��¼�ǲ���һ������
       num=0;//��¼���ʳ��ֵĴ���
    }
};

//���룺
void insert(trie* root,char* s)
{
    trie* p=root;
    int k=0;
    while(s[k]!='\0')
    {
        if(!p->next[s[k]-'0']) p->next[s[k]-'0']=new trie;
        p=p->next[s[k]-'0'];
        p->num++;
        k++;
    }
    p->value+=1;
}

//����
void find(trie* root,char* s)
{
    trie* p=root;
    int k=0;
    while(s[k]!='\0'&&p->next[s[k]-'0'])
    {
        p=p->next[s[k]-'0'];
        if (p->value>0&&s[k+1]!='\0')
        {
            ok=false;
        }
        if (p->value>1)
        {
            ok=false;
        }
        k++;
    }
}

int main()
{
    int n;
    trie* root;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        root=new trie;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",words[i]);
            insert(root,words[i]);
        }
        ok=true;
        for (int i=1;i<=n;i++)
        {
            find(root,words[i]);
        }
        if (ok)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

