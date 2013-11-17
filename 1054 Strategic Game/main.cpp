#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct{
    int f;
    int s;
    int flag;
}TREE;

TREE tr[1510];

int d[1510];

int dn;

int main()
{
    int n,t,m,tv,ans,p,k,tmp;

    while ( scanf("%d",&n)!=EOF )
    {
        for (int i=0;i<n;i++)
        {
            tr[i].f=i;
            tr[i].s=0;
            tr[i].flag=0;
        }
        for (int loop=0;loop<n;loop++)
        {
            scanf("%d:(%d)",&t,&m);
            tr[t].s=m;
            for (int i=0;i<m;i++)
            {
                scanf("%d",&tv);
                tr[tv].f=t;
            }
        }

        //¼ìÑé
        /*
        for (int i=0;i<n;i++)
        {
            printf("i=%d f=%d s=%d flag=%d\n",i,tr[i].f,tr[i].s,tr[i].flag);
        }
        */

        dn=0;
        for (int i=0;i<n;i++)
        {
            if ( tr[i].s==0 )
            {
                d[dn]=i;
                dn++;
            }
        }

        /*
        for (int i=0;i<dn;i++)
        {
            printf("i=%d d=%d\n",i,d[i]);
        }
        */

        p=0;
        while(p<dn)
        {
            k=d[p];
            if( tr[k].f!=k )
            {
               tmp=tr[k].f;
               tr[tmp].s--;
               if(tr[tmp].s==0)
               {
                  d[dn]=tmp;
                  dn++;
               }
               if(tr[k].flag!=1) tr[tmp].flag=1;
                else if(tr[tmp].flag!=1) tr[tmp].flag=2;
            }
            else
            {
                if(tr[k].flag==0)
                 tr[k].flag=1;
            }
            p++;
        }
        ans=0;
        for(int i=0;i<n;i++)
            if(tr[i].flag==1)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
