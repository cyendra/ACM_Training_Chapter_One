/*

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAXN 110

int t , m , pos;
int vis[MAXN];
int mark[MAXN];

bool solve_alloc(int x)
{
    int i , j;
    for(i = 1 ; i <= m ; i++)
    {
        if(!vis[i])
        {
            for(j = i ; j < i+x && j <= m ; j++)
            {
                if(vis[j])
                    break;
            }
            if(j == i+x)
            {
                for(j = i ; j < i+x ; j++)
                    vis[j] = pos;
                return true;
            }
        }
    }
    return false;
}

void solve_erase(int x)
{
    for(int i = 1 ; i <= m ; i++)
    {
        if(vis[i] == x)
        {
            vis[i] = 0;
        }
    }
}

void solve_defragment()
{
    int i , j;
    i = 1 , j = 1;
    for(; i <= m ; i++)
    {
        if(vis[i])
            vis[j++] = vis[i];
    }
    for(; j <= m ; j++)
        vis[j] = 0;
}

int main()
{
    char words[MAXN];
    int num;
    while(scanf("%d%d" , &t , &m) != EOF)
    {
        memset(vis , 0 , sizeof(vis));
        memset(mark , 0 , sizeof(mark));
        pos = 1;
        for(int i = 0 ; i < t ; i++)
        {
            scanf("%s" , words);

            if(!strcmp(words , "alloc"))
            {
                scanf("%d" , &num);
                if(solve_alloc(num))
                {
                    mark[pos] = 1;
                    printf("%d\n" , pos++);
                }
                else
                    printf("NULL\n");
            }
            if(!strcmp(words , "erase"))
            {
                scanf("%d" , &num);
                if(num >= pos || num <= 0 || !mark[num])
                {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
                else
                {
                    solve_erase(num);
                    mark[num] = 0;
                }
            }
            if(!strcmp(words , "defragment"))
                solve_defragment();
        }
    }
    return 0;
}




*/


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAXN 110

int t , m , pos;
int vis[MAXN];
int mark[MAXN];

/*alloc����*/
bool solve_alloc(int x)
{
    int i , j;
    for(i = 1 ; i <= m ; i++)
    {
        if(vis[i]==0)
        {
            for(j = i ; j < i+x && j <= m ; j++)
            {
                if(vis[j]!=0)
                    break;
            }
            if(j == i+x)
            {
                for(j = i ; j < i+x ; j++)
                    vis[j] = pos;
                return true;
            }
        }
    }
    return false;
}

/*erase����*/
void solve_erase(int x)
{
    for(int i = 1 ; i <= m ; i++)
    {
        if(vis[i] == x) /*����Ӧ�ı��ȥ��*/
        {
            vis[i] = 0;
        }
    }
}

/*defragment����*/
void solve_defragment()
{
    int i , j;
    i = 1 , j = 1;
    /*�����൱�ڰѺ����ȫ����ǰ���ƣ���j����ʾ����*/
    for(; i <= m ; i++)
    {
        if(vis[i])
            vis[j++] = vis[i];
    }
    /*j->mʣ�µĶ���0���������¸�ֵΪ0*/
    for(; j <= m ; j++)
        vis[j] = 0;
}

int main()
{
    char words[MAXN];
    int num;
    while(scanf("%d%d" , &t , &m) != EOF)
    {
        memset(vis , 0 , sizeof(vis));
        memset(mark , 0 , sizeof(mark));
        pos = 1;/*��ʼֵΪ1*/
        for(int i = 0 ; i < t ; i++)
        {
            scanf("%s" , words);
            /*�����alloc����*/
            if(!strcmp(words , "alloc"))
            {
                scanf("%d" , &num);
                if(solve_alloc(num))
                {
                    mark[pos] = 1;
                    printf("%d\n" , pos);
                    pos++;
                }
                else
                    printf("NULL\n");
            }
            /*�����erase����*/
            if(!strcmp(words , "erase"))
            {
                scanf("%d" , &num);
                if(num >= pos || num <= 0 || mark[num]==0) /*���������num��32λ������Χ�����Կ���С��0��*/
                {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
                else
                {
                    solve_erase(num);
                    mark[num] = 0;/*��Ӧ���Ϊ0˵��û������ڴ��*/
                }
            }
            /*�����defragment����*/
            if(!strcmp(words , "defragment"))
                solve_defragment();
        }
    }
    return 0;
}


