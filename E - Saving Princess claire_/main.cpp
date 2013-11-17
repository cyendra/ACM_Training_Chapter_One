#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int direct[4][2]= { {0,1},{1,0},{-1,0},{0,-1} };

struct POINT
{
    int x;
    int y;
    long long sp;
    POINT()
    {
        x=0;
        y=0;
        sp=0;
    }
    POINT(int _x,int _y):x(_x),y(_y) {}
};

int a[5111][5111];
bool vis[5111][5111];
char map[5111][5111];
POINT P_num[5111];
int P_cnt;
int n,m,c;

long long ans;

queue<POINT>que;
POINT start,end;

bool check(POINT p)
{
    if (p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m)
    {
        return true;
    }
    return false;
}

int bfs(POINT st,char ch)
{
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    POINT tmp,q,ppp;
    q=st;
    vis[q.x][q.y]=true;
    que.push(q);
    while (!que.empty())
    {
        tmp=que.front();
        que.pop();
        for (int i=0; i<4; i++)
        {
            q=tmp;
            q.x+=direct[i][0];
            q.y+=direct[i][1];
            if ( check(q)&&map[q.x][q.y]!='#'&&!vis[q.x][q.y] )
            {
                if (map[q.x][q.y]=='C')
                {
                    return q.sp;
                }
                else if (map[q.x][q.y]=='P')
                {
                    for (int k=0; k<P_cnt; k++)
                    {
                        ppp=P_num[k];
                        ppp.sp=q.sp;
                        if (!vis[ppp.x][ppp.y])
                        {
                            vis[ppp.x][ppp.y]=true;
                            que.push(ppp);
                        }
                    }
                }
                else if (map[q.x][q.y]=='*')
                {
                    q.sp+=1;
                    vis[q.x][q.y]=true;
                    que.push(q);
                }
            }
        }
    }
    return -1;
}



int main()
{
    while (~scanf("%d%d%d",&n,&m,&c))
    {
        for (int i=1; i<=n; i++)
        {
            scanf("%s",map[i]+1);
        }
        P_cnt=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (map[i][j]=='Y')
                {
                    start.x=i;
                    start.y=j;
                }
                if (map[i][j]=='C')
                {
                    end.x=i;
                    end.y=j;
                }
                if (map[i][j]=='P')
                {
                    P_num[P_cnt++]=POINT(i,j);
                }
            }
        }
        ans=bfs(start,'C');
        if (ans==-1)
        {
            puts("Damn teoy!");
        }
        else
        {
            ans=ans*c;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int direct[4][2]= { {0,1},{1,0},{-1,0},{0,-1} };
int a[5111][5111];
bool vis[5111][5111];
char map[5111][5111];
int n,m,c;

int Y_to_P;
int C_to_P;
int Y_to_C;
long long ans;
long long ra,rb;

struct POINT
{
    int x;
    int y;
    long long sp;
    POINT()
    {
        x=0;
        y=0;
        sp=0;
    }
};
//queue<POINT>que;
POINT que[51111];
POINT start,end;

bool check(POINT p)
{
    if (p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m)
    {
        return true;
    }
    return false;
}

int bfs(POINT st,char ch)
{
    int ret=0;
    while (!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    POINT tmp,q;
    q=st;
    vis[q.x][q.y]=true;
    que.push(q);
    while (!que.empty())
    {
        tmp=que.front();
        que.pop();
        for (int i=0; i<4; i++)
        {
            q=tmp;
            q.x+=direct[i][0];
            q.y+=direct[i][1];
            if ( check(q)&&map[q.x][q.y]!='#'&&!vis[q.x][q.y] )
            {
                if (map[q.x][q.y]==ch)
                {
                    ret=q.sp;
                    return ret;
                }
                else if (ch=='P'&&(map[q.x][q.y]=='Y'||map[q.x][q.y]=='C'))
                {
                    return -1;
                }
                else if (map[q.x][q.y]=='*')
                {
                    q.sp+=1;
                    vis[q.x][q.y]=true;
                    que.push(q);
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (~scanf("%d%d%d",&n,&m,&c))
    {
        for (int i=1; i<=n; i++)
        {
            scanf("%s",map[i]+1);
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (map[i][j]=='Y')
                {
                    start.x=i;
                    start.y=j;
                }
                if (map[i][j]=='C')
                {
                    end.x=i;
                    end.y=j;
                }
            }
        }
        Y_to_P=bfs(start,'P');
        C_to_P=bfs(end,'P');
        Y_to_C=bfs(start,'C');
        //cerr<<Y_to_P<<" "<<C_to_P<<" "<<Y_to_C<<endl;
        if (Y_to_C!=-1)
        {
            ra=Y_to_C;
        }
        else
        {
            ra=-1;
        }
        if ( !(Y_to_P==-1||C_to_P==-1) )
        {
            rb=Y_to_P+C_to_P;
        }
        else
        {
            rb=-1;
        }
        ans=1e9;
        if (ra==-1&&rb==-1)
        {
            puts("Damn teoy!");
        }
        else
        {
            ans=1e9;
            if (ra!=-1)
            {
                ans=ra;
            }
            if (rb!=-1&&rb<ans)
            {
                ans=rb;
            }
            ans=ans*c;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}


*/
