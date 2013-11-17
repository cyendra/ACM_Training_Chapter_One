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

int n,bg,ed,mini,minf,p,cost;

void findnum(int p);

void findnum(int p)
{
    if (f[p].last!=p)
    {
        findnum(f[p].last);
        cost=cost+b[p];
        printf("-->%d",p);
    }
    else
    {
        printf("%d",p);
        cost=cost+b[p];
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF && n!=0)
    {
        //��������
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

        //ѯ��
        while (scanf("%d%d",&bg,&ed)!=EOF && bg!=-1 && ed!=-1)
        {
            //��ʼ��
            for (int i=0;i<=n;i++)
            {
                f[i].value=MAX;
                f[i].last=i;
                v[i]=false;
            }
            f[bg].value=0;
            v[bg]=true;
            //�Ͻ�˹���������·
            for (int loop=1;loop<n && v[ed]!=true;loop++)
            {
                for (int i=1;i<=n;i++)
                {
                    if (v[i]==true)
                    {
                        for (int j=1;j<=n;j++)
                        {
                            if (v[j]==false && f[i].value+a[i][j]<f[j].value)
                            {
                                f[j].value=f[i].value+a[i][j];
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
            cost=0;
            findnum(p);
            printf("\n");
            printf("Total cost : %d\n",cost);
        }
    }
    return 0;
}
