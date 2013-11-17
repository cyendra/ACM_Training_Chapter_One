#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int x[333];
int y[333];
int n;
int f[333][333];

bool check1(int i,int j,int k)
{
    int x1=x[i]-x[j];
    int y1=y[i]-y[j];
    int x2=x[j]-x[k];
    int y2=y[j]-y[k];
    if (k==0) return true;
    if (x1*y2-x2*y1==0)
    {
        if (min(x1,x2)<=0&&max(x1,x2)>=0&&min(y1,y2)<=0&&max(y1,y2)>=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (x1*y2-x2*y1>0)
    {
        return true;
    }
    return false;
}

bool check2(int i,int j,int k)
{
    int x1=x[i]-x[j];
    int y1=y[i]-y[j];
    int x2=x[j]-x[k];
    int y2=y[j]-y[k];
    if (k==0) return true;
    if (x1*y2-x2*y1==0)
    {
        if (min(x1,x2)<=0&&max(x1,x2)>=0&&min(y1,y2)<=0&&max(y1,y2)>=0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (x1*y2-x2*y1<0)
    {
        return true;
    }
    return false;
}


int main()
{
    while (~scanf("%d",&n))
    {
        if  (n==0) break;
        memset(f,0,sizeof(f));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        //Ë³Ê±Õë
        int ans1=0;
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                for (int k=0;k<j;k++)
                {
                    if (check1(i,j,k))
                    {
                        if (f[k][j]+1>f[j][i])
                        {
                            f[j][i]=f[k][j]+1;
                        }
                    }
                    if (f[j][i]>ans1)
                    {
                        ans1=f[j][i];
                    }
                }
            }
        }
        //ÄæÊ±Õë
        memset(f,0,sizeof(f));
        int ans2=0;
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                for (int k=0;k<j;k++)
                {
                    if (check2(i,j,k))
                    {
                        if (f[k][j]+1>f[j][i])
                        {
                            f[j][i]=f[k][j]+1;
                        }
                    }
                    if (f[j][i]>ans2)
                    {
                        ans2=f[j][i];
                    }
                }
            }
        }
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cerr<<f[i][j]<<" ";
            }
            cerr<<endl;
        }
        */
        //cerr<<"-------"<<endl<<ans1<<" "<<ans2<<endl<<"--------"<<endl;
        if (ans1==n-1)
        {
            printf("C\n");
        }
        else if (ans2==n-1)
        {
            printf("CC\n");
        }
        else
        {
            int ans;
            bool ok1=false;
            if (ans1>=ans2)
            {
                ans=ans1;
                ok1=true;
            }
            else
            {
                ans=ans2;
                ok1=false;
            }
            if (ok1)
            {
                printf("Remove %d bead(s), C\n",n-1-ans);
            }
            else
            {
                printf("Remove %d bead(s), CC\n",n-1-ans);
            }
        }
    }
    return 0;
}
