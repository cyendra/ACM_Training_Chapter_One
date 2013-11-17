#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int rows[101];
int columns[101];
int r[101];
int l[101];
int u[101];
int d[101];
int a[101][101];
int n,m,cod,p;
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
        {
            break;
        }
        scanf("%d",&m);
        memset(rows,0,sizeof(rows));
        memset(columns,0,sizeof(columns));
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        memset(u,0,sizeof(u));
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        cod=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]==1)
                {
                    cod++;
                    if (rows[i]==0)
                    {
                        rows[i]=cod;
                    }
                    else
                    {
                        p=rows[i];
                        while (r[p]!=0)
                        {
                            p=r[p];
                        }
                        r[p]=cod;
                        l[cod]=p;
                    }
                    if (columns[j]==0)
                    {
                        columns[j]=cod;
                    }
                    else
                    {
                        p=columns[j];
                        while (d[p]!=0)
                        {
                            p=d[p];
                        }
                        d[p]=cod;
                        u[cod]=p;
                    }
                }
            }
        }
        //¼ìÑé
        /*
        for (int i=1;i<=cod;i++)
        {
            printf("cod=%d,l=%d,r=%d,u=%d,d=%d\n",i,l[i],r[i],u[i],d[i]);
        }
        for (int i=1;i<=n;i++)
        {
            printf("%d ",rows[i]);
        }
        printf("\n");
        for (int j=1;j<=m;j++)
        {
            printf("%d ",columns[j]);
        }
        printf("\n");
        */
        //¼ìÑéÍê±Ï
    }
    return 0;
}
