/*
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int,int>mp;

int main()
{
    int p[100010];
    int rank[100010];
    int x,y,n,px,py,bian,dian;
    bool ok;
    while (true)
    {
        for (int i=0;i<100010;i++)
        {
            p[i]=0;
            rank[i]=1;
        }
        ok=true;
        bian=0;
        dian=0;
        while (scanf("%d%d",&x,&y)!=EOF)
        {
            if ( (x==-1)and(y==-1) )
            {
                return 0;
            }
            if ( (x==0)and(y==0) )
            {
                break;
            }
            //------------------------------------
            mp[x]++;
            mp[y]++;
            bian++;
            px=x;
            py=y;
            while (p[px]!=0)
            {
                px=p[px];
            }
            while (p[py]!=0)
            {
                py=p[py];
            }
            if ((px!=0) and (py!=0) and (px==py))
            {
                ok=false;
            }
            else
            {
                if (rank[px]>rank[py])
                {
                    p[py]=px;
                }
                else if (rank[px]<rank[py])
                {
                    p[px]=py;
                }
                else
                {
                    p[px]=py;
                    rank[py]+=rank[px];
                }
            }

            //------------------------------------
        }
        if (ok==true && mp.size()==bian+1 )
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
*/


#include <stdio.h>
#include <string.h>
bool f[100005];     //标记节点是否已经存在
int  g[100005];        //并查集开辟的数组

int Find(int x)           //查集合中的末尾元素
{
    if(g[x]!=x)
        g[x]=Find(g[x]);
    return g[x];
}

int main()
{
   int x,y,i;
   int a,b,flag;
   int dian,bian;
   while(scanf("%d%d",&x,&y)==2&&(x+y!=-2))
   {
         if (x==0 && y==0)             //卧槽 ，少加个这样的条件一直没过,然后放弃了........（铭记教训）血的教训
         {
            printf ("Yes\n");
           continue;
         }

       memset(f,false,sizeof(f));        //初始化标记数组
       f[x]=true;
       f[y]=true;
       dian=2;
       bian=1;
       flag=1;
       for(i=1;i<=100005;i++)
           g[i]=i;
       g[x]=y;
       while(scanf("%d%d",&x,&y)==2&&(x+y))
       {
         if(!f[x])
         {
             dian++;
             f[x]=true;
         }
         if(!f[y])
         {
             dian++;
             f[y]=true;
         }
             bian++;                          //以上记录图中点和边的数量
        a=Find(x);
        b=Find(y);
        if(a!=b)
            g[a]=b;
        else
            flag=0;                            // 以上合并新节点，如果有环则标记
       }
       if(bian==dian-1&&flag)
          printf("Yes\n");
       else
          printf("No\n");
   }
    return 0;
}

