#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int plc,n,t,p;
int r[101]={0};
int l[101]={0};
int at[101]={0};
int an[101]={0};
int f[101][601];
int bk[101];
int ans=0;
void blt(int ft);
void brt(int ft);
int dp(int x,int y);



int dp(int x,int y)
{
    int max=0;
    int tmp=0;
    //if (f[x][y]!=0)
    //{
    //    return f[x][y];
    //}
    if (an[x]!=0)
    {
        for (int i=1;i<=an[x];i++)
        {
            if (tmp+5<=y-at[x]*2)
            {
                tmp+=5;
                max++;
            }
            else
            {
                break;
            }
        }
        f[x][y]=max;
        return max;
    }
    for (int k=0;k<=y-at[x]*2;k++)
    {
        tmp=dp(l[x],y-at[x]*2-k)+dp(r[x],k);
        if (tmp>max)
        {
            max=tmp;
        }
    }
    f[x][y]=max;
    return max;
}

void blt(int ft)
{
    int tmp;
    scanf("%d%d",&t,&n);
    p++;
    l[ft]=p;
    at[p]=t;
    an[p]=n;
    bk[p]=bk[ft]+t;
    tmp=p;
    if (n==0)
    {
        blt(tmp);
        brt(tmp);
    }
}
void brt(int ft)
{
    int tmp;
    scanf("%d%d",&t,&n);
    p++;
    r[ft]=p;
    at[p]=t;
    an[p]=n;
    bk[p]=bk[ft]+t;
    tmp=p;
    if (n==0)
    {
        blt(tmp);
        brt(tmp);
    }
}

int main()
{
    while (scanf("%d",&plc))
    {
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        memset(at,0,sizeof(at));
        memset(an,0,sizeof(an));
        memset(f,0,sizeof(f));
        p=1;
        scanf("%d%d",&t,&n);
        at[1]=t;
        an[1]=n;
        bk[1]=t;
        if (n==0)
        {
            blt(1);
            brt(1);
        }
        //------------初始化完成-----------------------------------------
/*
        for (int i=1;i<=p;i++)
        {
            printf("at[%d]=%d,an[%d]=%d\n",i,at[i],i,an[i]);
            printf("l[%d]=%d,r[%d]=%d\n",i,l[i],i,r[i]);
        }
*/
        //------------检验完成-------------------------------------------
        ans=dp(1,plc-1);
        printf("%d",ans);
    }
    return 0;
}
