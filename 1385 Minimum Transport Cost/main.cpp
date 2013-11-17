#include <iostream>
#include <cstdio>

#define MAX 9999999
#define MAXN 110

using namespace std;

typedef struct{
    int value;
    int last;
}HERO;

int a[MAXN][MAXN];
int b[MAXN];
int v[MAXN];
HERO f[MAXN];

int n,bg,ed,mini,minf,p,tmp;

void findnum(int p);

void findnum(int p)
{
    if (f[p].last!=p)
    {
        findnum(f[p].last);
        printf("-->%d",p);
    }
    else
    {
        printf("%d",p);
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF && n!=0)
    {
        //读入数据
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]==-1)
                {
                    a[i][j]=MAX;
                }
            }
        }

        for (int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        //input over

        //询问
        while (scanf("%d%d",&bg,&ed)!=EOF && bg!=-1 && ed!=-1)
        {
            if (bg==ed)
            {
                printf("From %d to %d :\n",bg,ed);
                printf("Path: %d",bg);
                printf("\n");
                printf("Total cost : 0\n\n");
                continue;
            }
            //初始化
            for (int i=0;i<=n;i++)
            {
                f[i].value=MAX;
                f[i].last=i;
                v[i]=false;
            }
            f[bg].value=0;
            v[bg]=true;
            //迪杰斯特拉求最短路
            for (int loop=1;loop<n && v[ed]!=true;loop++)
            {
                for (int i=1;i<=n;i++)
                {
                    if (v[i]==true)
                    {
                        for (int j=1;j<=n;j++)
                        {
                            tmp=(j==ed)?(0):(b[j]);
                            if (v[j]==false && f[i].value+a[i][j]+tmp<f[j].value)
                            {
                                f[j].value=f[i].value+a[i][j]+tmp;
                                f[j].last=i;
                            }
                        }
                    }
                }
                mini=0;
                minf=MAX;
                for (int i=1;i<=n;i++)
                {
                    if (v[i]==false && f[i].value<minf)
                    {
                        minf=f[i].value;
                        mini=i;
                    }
                }
                v[mini]=true;
            }
            printf("From %d to %d :\n",bg,ed);
            printf("Path: ");
            p=ed;
            findnum(p);
            printf("\n");
            printf("Total cost : %d\n\n",f[ed].value);
        }
    }
    return 0;
}
