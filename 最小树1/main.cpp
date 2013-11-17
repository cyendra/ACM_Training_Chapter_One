#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,x,y,num;
    double a[50][50];
    double min,t,sum;
    bool ok=false;
    bool v[50]={false};
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        sum=0;
        ok=false;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                a[i][j]=-1;
            }
        }
        for (int i=0;i<(n*(n-1)/2);i++)
        {
            scanf("%d%d%lf",&x,&y,&t);
            a[x][y]=t;
            a[y][x]=t;
        }
        v[1]=true;
        //printf("first ok");getchar();
        while (ok==false)
        {
            ok=true;
            min=-1;
            //printf("for begin");
            for (int i=1;i<=n;i++)
            {
                if (v[i]==true)
                {
                    for (int j=1;j<=n;j++)
                    {
                        if ((v[j]==false)and (a[i][j]!=-1))
                        {
                            if ((min==-1)or(a[i][j]<min))
                            {
                                //printf("i=%d,j=%d",i,j);getchar();
                                min=a[i][j];
                                num=j;
                                ok=false;
                            }
                        }
                    }
                }
            }
            if (min!=-1)
            {
                sum+=min;
            }
            v[num]=true;
           // printf("sum=%f,num=%d",sum,num);getchar();
        }
        printf("%0.2f\n",sum);

    }
    return 0;
}
