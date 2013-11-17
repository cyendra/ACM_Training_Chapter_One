
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define NNN (1<<15)
using namespace std;

typedef struct{
    int d;
    int c;
    string name;
}HERO;

typedef struct{
    int tm;
    int ct;
    int st;
    short s[17];

}DPKING;

DPKING f[NNN];
HERO a[20];
DPKING x,y;

queue <DPKING> que;

int main()
{
    int t,n,p;

    cin >> t;
    for (int loop=0;loop<t;loop++)
    {
        cin >> n;
        for (int i=0;i<n;i++)
        {
            cin >> a[i].name >> a[i].d >> a[i].c;
        }
        memset(f,0,sizeof(f));
        while (que.empty()!=true)
        {
            que.pop();
        }
        for (int i=0;i<(1<<n);i++)
        {
            f[i].ct=-1;
        }
        //BFS
        x.tm=0;
        x.ct=0;
        x.st=0;
        x.s[0]=0;
        f[0]=x;
        que.push(x);
        while (!que.empty())
        {
            x=que.front();
            que.pop();
            for (int i=0;i<n;i++)
            {
                if ( ((x.st) & (1<<i))==0 )
                {
                    y.st=x.st|(1<<i);
                    y.tm=x.tm + a[i].c;
                    y.ct=x.ct;
                    if (y.tm>a[i].d)
                    {
                        y.ct+=(y.tm - a[i].d);
                    }
                    if ( (f[y.st].ct==-1)||( f[y.st].ct>y.ct) )
                    {
                        y.s[0]=x.s[0];
                        for (int tmp=1;tmp<=x.s[0];tmp++)
                        {
                            y.s[tmp]=x.s[tmp];
                        }
                        y.s[0]++;
                        y.s[ y.s[0] ]=i;
                        f[ y.st ]=y;
                        que.push(y);
                    }

                }
            }
        }
        //BFS_END
        p=(1<<n)-1;
        cout << f[ p ].ct << endl;
        for (int i=1;i<=n;i++)
        {
            cout << a[ f[p].s[i] ].name << endl ;
        }
    }
    return 0;
}


/*
#include "iostream"
#include "string.h"
#include "queue"
using namespace std;
#define N 1<<15
//使用状态压缩，如01001(二进制）表示做了第一个和第四个作业。

struct sub_node
{
    int time,dt;
    char name[100];
}sub[15];

struct dp_node
{
    int time,cost,status; //时间 罚分 完成状态
    char s[17];//记录顺序 课程的编号
}dp[N];//下标表示状态 如dp[5] 化为 二进制 dp[101] 表示完成了编号 0 ，2的作业(从0开始)
dp_node a,b;
int n;

queue<dp_node> Q;
void bfs()
{
    a.time = a.cost = a.status = 0; a.s[0] = '\0';
    dp[0] = a;
    Q.push(a);
    while(!Q.empty())
    {
        int i;
        a = Q.front(); Q.pop();
        for(i=0; i<n; i++)
            if((a.status&(1<<i)) == 0) //没有含有第i门课程
            {
                b.status = a.status | (1<<i);
                b.time = a.time + sub[i].time;
                b.cost = a.cost;
                if(b.time > sub[i].dt)
                    b.cost += b.time - sub[i].dt;
                if(dp[b.status].cost==-1 || b.cost < dp[b.status].cost)//更新
                {
                    strcpy(b.s,a.s);
                    int len = strlen(b.s);
                    b.s[len] = i + '0';
                    b.s[len+1] = '\0'; //忘了这个，多组错误，调试了好久
                    dp[b.status] = b;
                    Q.push(b);
                }
            }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int i;
        for (i=0; i<n; i++)
        {
            cin >> sub[i].name >> sub[i].dt >> sub[i].time;
        }

        memset(dp,0,sizeof(dp));
        while(!Q.empty())   Q.pop();
        for(i=0; i<1<<n; i++) dp[i].cost = -1;
        bfs();

        int l = (1<<n)-1;
        cout<<dp[l].cost<<endl;
        for (i=0; i<n; i++)
            cout<<sub[dp[l].s[i]-'0'].name<<endl;
    }

    return 0;
}
*/
