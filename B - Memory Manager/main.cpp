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

/*alloc操作*/
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

/*erase操作*/
void solve_erase(int x)
{
    for(int i = 1 ; i <= m ; i++)
    {
        if(vis[i] == x) /*把相应的标记去除*/
        {
            vis[i] = 0;
        }
    }
}

/*defragment操作*/
void solve_defragment()
{
    int i , j;
    i = 1 , j = 1;
    /*这里相当于把后面的全部往前面移，用j来表示长度*/
    for(; i <= m ; i++)
    {
        if(vis[i])
            vis[j++] = vis[i];
    }
    /*j->m剩下的都是0，所以重新赋值为0*/
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
        pos = 1;/*初始值为1*/
        for(int i = 0 ; i < t ; i++)
        {
            scanf("%s" , words);
            /*如果是alloc操作*/
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
            /*如果是erase操作*/
            if(!strcmp(words , "erase"))
            {
                scanf("%d" , &num);
                if(num >= pos || num <= 0 || mark[num]==0) /*由于这里的num是32位整数范围，所以可能小于0。*/
                {
                    printf("ILLEGAL_ERASE_ARGUMENT\n");
                }
                else
                {
                    solve_erase(num);
                    mark[num] = 0;/*相应标记为0说明没有这个内存块*/
                }
            }
            /*如果是defragment操作*/
            if(!strcmp(words , "defragment"))
                solve_defragment();
        }
    }
    return 0;
}


