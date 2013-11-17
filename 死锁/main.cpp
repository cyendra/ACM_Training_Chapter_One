#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int p,r,e1,e2,x,y;
int a[1001][1001];
bool ok=true;
void dps(int i);

void dps(int i)
{
    for (int j=0;j<p+r;j++)
    {
        if (a[i][j]==2)
        {
            ok=false;
            return;
        }
        if (a[i][j]==1)
        {
            a[i][j]=2;
            dps(j);
            a[i][j]=1;
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for (int loop=1;loop<=n;loop++)
    {
        memset(a,0,sizeof(a));
        ok=true;
        scanf("%d%d%d%d",&p,&r,&e1,&e2);
        for (int i=0;i<e1;i++)
        {
            scanf("%d%d",&x,&y);
            a[x][y+p]=1 ;
        }
        for (int i=0;i<e2;i++)
        {
            scanf("%d%d",&x,&y);
            a[x+p][y]=1;
        }
        //初始化完成
        for (int i=0;i<p+r;i++)
        {
            dps(i);
            if (ok==false)
            {
                break;
            }
        }
        if (ok==false)
        {
            printf("possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
