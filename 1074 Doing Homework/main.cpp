
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
//ʹ��״̬ѹ������01001(�����ƣ���ʾ���˵�һ���͵��ĸ���ҵ��

struct sub_node
{
    int time,dt;
    char name[100];
}sub[15];

struct dp_node
{
    int time,cost,status; //ʱ�� ���� ���״̬
    char s[17];//��¼˳�� �γ̵ı��
}dp[N];//�±��ʾ״̬ ��dp[5] ��Ϊ ������ dp[101] ��ʾ����˱�� 0 ��2����ҵ(��0��ʼ)
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
            if((a.status&(1<<i)) == 0) //û�к��е�i�ſγ�
            {
                b.status = a.status | (1<<i);
                b.time = a.time + sub[i].time;
                b.cost = a.cost;
                if(b.time > sub[i].dt)
                    b.cost += b.time - sub[i].dt;
                if(dp[b.status].cost==-1 || b.cost < dp[b.status].cost)//����
                {
                    strcpy(b.s,a.s);
                    int len = strlen(b.s);
                    b.s[len] = i + '0';
                    b.s[len+1] = '\0'; //���������������󣬵����˺þ�
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
