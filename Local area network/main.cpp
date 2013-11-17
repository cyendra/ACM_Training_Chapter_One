#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m,n,x1,x2,y1,y2,t;
    int a[41][41];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                a[i][j]=0;
            }
        }
        a[0][0]=1;
        if (x1+y1>x2+y2)
        {
            t=x1;
            x1=x2;
            x2=t;
            t=y1;
            y1=y2;
            y2=t;
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if ( (i==y2)&&(j==x2) )
                {
                    if ( (j-1>=0)&&!((i==y1)&&(j-1==x1)) )
                    {
                        a[i][j]+=a[i][j-1];
                    }
                    if ( (i-1>=0)&&!((i-1==y1)&&(j==x1)) )
                    {
                        a[i][j]+=a[i-1][j];
                    }
                }
                else
                {
                    if (i-1>=0)
                    {
                        a[i][j]+=a[i-1][j];
                    }
                    if (j-1>=0)
                    {
                        a[i][j]+=a[i][j-1];
                    }
                }

                /*
                if (i-1>=0)
                {
                    if ( !(( (i==x1)&&(j==y1)&&(i-1==x2)&&(j==y2) )||( (i==x2)&&(j==y2)&&(i-1==x1)&&(j==y1) )) )
                    {
                        a[i][j]+=a[i-1][j];
                        //printf("a[%d,%d]=%d\n",i,j,a[i][j]);
                    }
                }
                if (j-1>=0)
                {
                    if (!(( (i==x1)&&(j==y1)&&(i==x2)&&(j-1==y2) )||( (i==x2)&&(j==y2)&&(i==x1)&&(j-1==y1) )))
                    {
                        a[i][j]+=a[i][j-1];
                        //printf("a[%d,%d]=%d\n",i,j,a[i][j]);
                    }
                }
                */
            }
        }
        printf("%d\n",a[n-1][m-1]);
    }
    return 0;
}
