/*
#include <iostream>
//#include <cstring>
#include <algorithm>
//#include <queue>
using namespace std;

//����ṹ
typedef struct{
    int x;
    int y;
    int v;
}PART;
/*
typedef struct{
    int x;
    int y;
    int step;
}MAPPOINT;

//��������
PART a[11000];
int f[11000];
int map[110][110];
//int all[110][110];
//int sword[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };

//�������
int n,ik,p,ans,bg,tmp,wtf,t1,t2;

//���庯��
int cmp(PART a,PART b);
int absnum(int a)
{
    if (a<0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}
//int findroad(int ax,int ay,int bx,int by);

//�������
//queue<MAPPOINT>que;

//sort��cmp
int cmp(PART a,PART b)
{
    return a.v<b.v;
}

//�ж��Ƿ��ܵ���
/*
bool findroad(int tk,int ax,int ay,int bx,int by)
{
    //�������
    MAPPOINT q1,qt;
    bool ok;
    //�������
    while (!que.empty())
    {
        que.pop();
    }

    //����ֵ
    q1.x=ax;
    q1.y=ay;
    q1.step=0;
    que.push(q1);
    ok=false;
    memset(all,0,sizeof(all));
    all[ax][ay]=1;

    //BFS
    while (!que.empty())
    {
        //����ջ��Ԫ��
        qt=que.front();
        que.pop();

        //�ж��Ƿ��ҵ�
        if ( qt.x==bx && qt.y==by )
        {
            ok=true;
            break;
        }

        //Ѱ���¸��ڵ�
        for (int i=0;i<4;i++)
        {
            q1.x=qt.x+sword[i][0];
            q1.y=qt.y+sword[i][1];
            q1.step=qt.step+1;
            if ( (q1.x>=0)&&(q1.y>=0)&&(q1.x<n)&&(q1.y<n)&&(q1.step<=tk)&&(all[q1.x][q1.y]==0)&&( abs(q1.x+q1.y-bx-by)<=abs(qt.x+qt.y-bx-by) ) )
            {
                all[q1.x][q1.y]=1;
                que.push(q1);
            }
        }
    }
    return ok;
}
//main
int main()
{
    while (cin >> n >> ik)
    {
        if (n==-1&&ik==-1)
        {
            break;
        }

        //��ʼ��
        //memset(f,0,sizeof(f));
        //memset(a,0,sizeof(a));
        p=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin >> map[i][j];
                a[p].x=i;
                a[p].y=j;
                a[p].v=map[i][j];
                p++;
            }
        }

        //����
        sort(a,a+p,cmp);

        //Ѱ�����
        for (int i=0;i<p;i++)
        {
            f[i]=0;
            if (a[i].x==0 && a[i].y==0)
            {
                bg=i;
                break;
            }
        }
        f[bg]=a[bg].v;
        ans=f[bg];
        //DP
        for (int i=bg+1;i<p;i++)
        {
            tmp=0;
            for (int k=bg;k<i;k++)
            {
                //if ( findroad(ik,a[i].x,a[i].y,a[k].x,a[k].y)==true && (a[k].v<a[i].v)  )
                //cout << ( abs(a[i].x-a[k].x)+abs(a[i].y-a[k].y) )<< " " << k <<" "<< a[k].v <<" "<< a[i].v << endl;
                if ( ( ( absnum(a[i].x-a[k].x)+absnum(a[i].y-a[k].y) )<=ik)&& (a[k].v<a[i].v) && (f[k] + a[i].v>tmp) )
                {
                    tmp=f[k]+a[i].v;
                }
            }
            f[i]=tmp;
            if (f[i]>ans)
            {
                ans=f[i];
            }
            //����
            //cout << i << " f[i]= " << tmp << endl;
        }

        //Ѱ�ҽ��
        /*
        for (int i=0;i<p;i++)
        {
            if ( f[i]>ans )
            {
                ans=f[i];
            }
        }

        //������
        cout << ans << endl;
    }
    return 0;
}
*/


#include <iostream>
#include <algorithm>
using namespace std;

//����ṹ
typedef struct{
    int x;
    int y;
    int v;
}PART;

//��������
PART a[11000];
int f[11000];
int map[110][110];

//�������
int n,ik,p,ans,bg,tmp;
int templar;

//���庯��
int cmp(PART a,PART b);
int absnum(int a)
{
    if (a<0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

//sort��cmp
int cmp(PART a,PART b)
{
    return a.v<b.v;
}

//main
int main()
{
    while (cin >> n >> ik)
    {
        if (n==-1&&ik==-1)
        {
            break;
        }

        //��ʼ��
        p=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin >> map[i][j];
                a[p].x=i;
                a[p].y=j;
                a[p].v=map[i][j];
                p++;
            }
        }

        //����
        sort(a,a+p,cmp);

        //Ѱ�����
        for (int i=0;i<p;i++)
        {
            f[i]=0;
            if (a[i].x==0 && a[i].y==0)
            {
                bg=i;
                break;
            }
        }
        f[bg]=a[bg].v;
        ans=f[bg];

        //DP
        for (int i=bg+1;i<p;i++)
        {
            tmp=0;
            for (int k=bg;k<i;k++)
            {
                if (a[i].x-a[k].x<0)
                {
                    templar=a[k].x-a[i].x;
                }
                else
                {
                    templar=a[i].x-a[k].x;
                }
                if (a[i].y-a[k].y<0)
                {
                    templar+=a[k].y-a[i].y;
                }
                else
                {
                    templar+=a[i].y-a[k].y;
                }
                if ( templar <= ik)
                {
                    if (a[k].v<a[i].v)
                    {
                        if (f[k] + a[i].v>tmp)
                        {
                            tmp=f[k]+a[i].v;
                        }
                    }
                }
                /*
                if ( ( ( absnum(a[i].x-a[k].x)+absnum(a[i].y-a[k].y) )<=ik)&& (a[k].v<a[i].v) && (f[k] + a[i].v>tmp) )
                {
                    tmp=f[k]+a[i].v;
                }
                */
            }
            f[i]=tmp;
            if (f[i]>ans)
            {
                ans=f[i];
            }
        }
        //������
        cout << ans << endl;
    }
    return 0;
}
