#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int p[1000],rank[1000];
    int m,n,x,y,sum,pax,pay;
    bool check;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
        {
            break;
        }
        scanf("%d",&m);
        for (int i=0;i<=n;i++)
        {
            p[i]=0;
            rank[i]=1;
        }

        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            //-------------------------------
            pax=x;
            while (p[pax]!=0)
            {
                pax=p[pax];
            }
            pay=y;
            while (p[pay]!=0)
            {
                pay=p[pay];
            }
            if (pax==pay)
            {
                check=true;
            }
            else
            {
                check=false;
            }
            //------------------------------
            if (check==false)
            {
                if (rank[pax]>rank[pay])
                {
                    p[pay]=pax;
                }
                else
                {
                    p[pax]=pay;
                }
            }
        }
        sum=-1;
        for (int i=1;i<=n;i++)
        {
            if (p[i]==0)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
