#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int ans;

//���࣬���߽ṹ�嶨�嶼��
struct trie
{
    trie* next[128];
    int num;
    int value;
    trie()
    {
        for(int i=0; i<26; i++) next[i]=NULL;
        value=0;//��¼�ǲ���һ������
        num=0;//��¼���ʳ��ֵĴ���
    }
    void clear()
    {
        for(int i=0; i<26; i++) next[i]=NULL;
        value=0;//��¼�ǲ���һ������
        num=0;//��¼���ʳ��ֵĴ���
    }
} root;

//���룺
void insert(char* s)
{
    trie* p=&root;
    int l=strlen(s);
    for (int i=0; i<=l; i++)
    {
        if(!p->next[(int)s[i]])
        {
            p->next[(int)s[i]]=new trie;
        }
        p=p->next[(int)s[i]];
        p->num++;
    }
    p->value=1;
}

int main()
{
    int n;
    char str[1111];
    int cnt=0;
    while (~scanf("%d",&n))
    {
        cnt++;
        if (n==0) break;
        root.clear();
        ans=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%s",str);
            insert(str);
        }
        printf("Case %d: %d\n",cnt,ans);
    }
    return 0;
}
