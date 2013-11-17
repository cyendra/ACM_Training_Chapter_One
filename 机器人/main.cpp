#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int f[500][500];
    bool a[500][500];
    int px,py,x,y,t,n,lx,ly,sum;
    for (int i=0;i<500;i++)
    {
        for (int j=0;j<500;j++)
        {
            a[i][j]=false;
            f[i][j]=0;
        }
    }
    n=0;
    lx=0;
    ly=0;
    sum=0;
    while (scanf("%d%d",&x,&y))
    {
        if ((x==-1)and(y==-1))
        {
            return 0;
        }
        if ((x!=0) and (y!=0) )
        {
            n++;
            a[x][y]=true;
            if (x>lx)
            {
                lx=x;
            }
            if (y>ly)
            {
                ly=y;
            }
        }

        if ((x==0)and(y==0))
        {
            //------------------------------------------
            //更新f[x][y]
            for (int i=1;i<=lx;i++)
            {
                t=0;
                for (int j=ly;j>=1;j--)
                {
                    f[i][j]=t;
                    if (a[i][j]==true)
                    {
                        t++;
                    }
                }
            }
            //检查
            px=1;
            py=1;
            getchar();
            while (n!=0)
            {
                //printf("px=%d,py=%d,n=%d,f=%d,a=%d",px,py,n,f[px][py],a[px][py]);
                //getchar();
                if (a[px][py]==true)
                {
                    a[px][py]=false;
                    n--;
                    for (int i=py-1;i>=1;i--)
                    {
                        f[px][i]-=1;
                    }
                }
                if (n==0)
                {
                    sum++;
                    break;
                }
                if ((px==lx)and(py==ly))
                {
                    sum++;
                    px=1;
                    py=1;
                }

                if (f[px][py]==0)
                {
                    px++;
                }
                else
                {
                    py++;
                }

            }
            //输出结果 初始化
            printf("%d\n",sum);
            n=0;
            lx=0;
            ly=0;
            sum=0;
            for (int i=0;i<500;i++)
            {
                for (int j=0;j<500;j++)
                {
                    a[i][j]=false;
                    f[i][j]=0;
                }
    }
            //------------------------------------------
        }
    }
    return 0;
}
