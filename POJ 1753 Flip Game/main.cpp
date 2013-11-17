#include <iostream>
#include <queue>
#include <cstring>
#define MAX 65536

using namespace std;

char chr[5][5];
int a[5][5];
int id=0;
bool v[MAX];
int step[MAX];
int tmp;

queue<int>que;

int main()
{
    memset(v,0,sizeof(v));
    id=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            cin>>chr[i][j];
            if (chr[i][j]=='b') a[i][j]=1;
            else if (chr[i][j]=='w') a[i][j]=0;
            id=id<<1;
            if (a[i][j]==1) id+=1;
        }
    }
    if (id==0||id==65535)
    {
        cout<<"0"<<endl;
        return 0;
    }
    while (!que.empty())que.pop();
    que.push(id);
    while ( !que.empty() )
    {
        tmp=que.front();
        que.pop();
        id=tmp;
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                tmp=id;
                if (i==0)
                {
                    tmp^=1<<(11-4*i-j);
                }
                else if (i==3)
                {
                    tmp^=1<<(19-4*i-j);
                }
                else
                {
                    tmp^=1<<(11-4*i-j);
                    tmp^=1<<(19-4*i-j);
                }
                if (j==0)
                {
                    tmp^=3<<(14-4*i-j);
                }
                else if (j==3)
                {
                    tmp^=3<<(15-4*i-j);
                }
                else
                {
                    tmp^=7<<(14-4*i-j);
                }
                if (tmp==0||tmp==65535)
                {
                    cout<<step[id]+1<<endl;
                    return 0;
                }
                if (!v[tmp])
                {
                    v[tmp]=true;
                    que.push(tmp);
                    step[tmp]=step[id]+1;
                }
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}
