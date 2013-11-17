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
bool f[100005];     //��ǽڵ��Ƿ��Ѿ�����
int  g[100005];        //���鼯���ٵ�����

int Find(int x)           //�鼯���е�ĩβԪ��
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
         if (x==0 && y==0)             //�Բ� ���ټӸ�����������һֱû��,Ȼ�������........�����ǽ�ѵ��Ѫ�Ľ�ѵ
         {
            printf ("Yes\n");
           continue;
         }

       memset(f,false,sizeof(f));        //��ʼ���������
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
             bian++;                          //���ϼ�¼ͼ�е�ͱߵ�����
        a=Find(x);
        b=Find(y);
        if(a!=b)
            g[a]=b;
        else
            flag=0;                            // ���Ϻϲ��½ڵ㣬����л�����
       }
       if(bian==dian-1&&flag)
          printf("Yes\n");
       else
          printf("No\n");
   }
    return 0;
}

