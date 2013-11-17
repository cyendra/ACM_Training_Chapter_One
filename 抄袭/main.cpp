#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,p,tp;
    char str[51][101];
    int par[101];
    int son[101];
    int f[101][101];
    int max=0;
    memset(f,0,sizeof(f));
    memset(par,0,sizeof(par));
    memset(son,0,sizeof(son));
    scanf("%d%d",&n,&p);
    getchar();
    for (int i=1;i<=n;i++)
    {
        gets(str[i]);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            //--比较i串与j串
            max=0;
            for (int l1=0;l1<strlen(str[i]);l1++)
            {
                for (int l2=0;l2<strlen(str[j]);l2++)
                {
                    //--动归求最大公共串
                    if (str[i][l1]==str[j][l2])
                    {
                        if ((l1==0)or(l2==0))
                        {
                            f[l1][l2]=1;
                        }
                        else
                        {
                            f[l1][l2]=f[l1-1][l2-1]+1;
                        }
                        if (f[l1][l2]>max)
                        {
                            max=f[l1][l2];
                        }
                    }
                    else
                    {
                        f[l1][l2]=0;
                    }
                    if (      (max*2*100)/(strlen(str[i])+strlen(str[j]))>=p       )
                    {
                        tp=i;
                        while (par[tp]!=0)
                        {
                            tp=par[tp];
                        }
                        par[j]=tp;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        printf("%d ",par[i]);
    }
    return 0;
}
