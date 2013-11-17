#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
    int x;
    int y;
}POINT;

int n,m,in;
char map[111][111];
int a[111][111];
POINT p,bg;

bool check(POINT p)
{
    if (p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m) return true;
    else
    {
        //cout<<p.x<<" "<<p.y<<" = false"<<endl;
        return false;
    }
}

int main()
{
    int tmp;
    int step,loop;
    bool isexit,isloop;
    while (cin>>n>>m>>in)
    {
        if (n==0&&m==0&&in==0) break;
        memset(a,0,sizeof(a));
        step=loop=0;
        isexit=false;
        isloop=false;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>map[i][j];
            }
        }
        p.x=1;
        p.y=in;
        bg=p;
        a[p.x][p.y]=1;
        while (check(p))
        {
            //cout<<"x="<<p.x<<" y="<<p.y<<endl;
            tmp=a[p.x][p.y];
            switch (map[p.x][p.y])
            {
                case 'N':
                {
                    p.x--;
                    break;
                }
                case 'S':
                {
                    p.x++;
                    break;
                }
                case 'W':
                {
                    p.y--;
                    break;
                }
                case 'E':
                {
                    p.y++;
                    break;
                }
            }
            if (!check(p))
            {
                isexit=true;
                isloop=false;
                step=tmp+1;
                //cout<<"exit"<<endl;
                break;
            }
            else if (check(p)&&a[p.x][p.y]==0)
            {
                a[p.x][p.y]=tmp+1;
            }
            else if (check(p)&&a[p.x][p.y]!=0)
            {
                isloop=true;
                isexit=false;

                step=a[p.x][p.y];
                if (p.x==bg.x&&p.y==bg.y) step=1;
                loop=tmp+1-a[p.x][p.y];
                //cout<<"loop"<<endl;
                break;
            }
        }
        if (isloop)
        {
            cout<<step-1<<" step(s) before a loop of "<<loop<<" step(s)"<<endl;
        }
        else if (isexit)
        {
            cout<<step-1<<" step(s) to exit"<<endl;
        }
    }
    return 0;
}
