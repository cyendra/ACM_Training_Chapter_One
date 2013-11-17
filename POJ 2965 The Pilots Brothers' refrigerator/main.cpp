#include <iostream>
#include <cstring>
#include <queue>
#define MAX 65536

using namespace std;

int dir[16] = {4383,8751,17487,34959,4593,8946,17652,35064,7953,12066,
               20292,36744,61713,61986,62532,63624
              };
typedef struct
{
    int x;
    int pre;
} DAT;

typedef struct
{
    int sum;
    int num;
    int step;
} DATA;

char chr[5][5];
DATA id,tmp,bg;
bool v[MAX];
int n;
DAT step[MAX];

queue<DATA>que;
int key=0;
int tp;
char s[5];

void dfs(int index)
{
	if(index)
	{
		dfs(step[index].pre);
		cout<<step[index].x/4+1<<" "<<step[index].x%4+1<<endl;
	}
}

int main()
{
    memset(v,0,sizeof(v));
    memset(step,0,sizeof(step));
    tp=0;
    /*
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            cin>>chr[i][j];
            tp=tp<<1;
            if (chr[i][j]=='+') tp++;
        }
    }
    */

	for(int i=0;i<4;i++)
	{
		cin>>s;
		for(int j=0;j<4;j++)
		{
			if(s[j]=='+')
			{
				tp+=(1<<i*4+j);
			}
		}
	}


    while (!que.empty()) que.pop();
    id.sum=tp;
    id.num=0;
    id.step=0;
    step[1].pre=0;
    que.push(id);


    while ( !que.empty() )
    {
        id=que.front();
        que.pop();
        if (id.sum==0)
        {
            cout<<id.step<<endl;
            dfs(id.num);
            return 0;
        }

        for (int i=0; i<16; i++)
        {
            tmp=id;
            tmp.sum^=dir[ i ];
            if (!v[tmp.sum])
            {
                tmp.num=++key;
                tmp.step++;
                step[key].pre=id.num;
                step[key].x=i;
                v[tmp.sum]=true;
                que.push(tmp);
            }
        }

    }
    return 0;
}
