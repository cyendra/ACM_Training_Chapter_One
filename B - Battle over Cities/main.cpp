#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int map[2][10][10];

struct POINT{
    int x;
    int y;
};

struct TWOPOINT{
    POINT one;
    POINT two;
};

queue<TWOPOINT>que;

bool v[10][10][10][10];

TWOPOINT bg;
POINT st1,st2;
POINT end;

int main()
{
    cin>>T;
    T--;
            st1.x=0;
        st1.y=0;
        st2.x=0;
        st2.y=0;
        end.x=0;
        end.y=0;
          for (int i=1;i<=6;i++)
        {
            for (int j=1;j<=6;j++)
            {
                cin>>map[i][j];
                if (map[i][j]&(1<<(6-1)))
                {
                    if (st1.x==0)
                    {
                        st1.x=i;
                        st1.y=j;
                    }
                    else
                    {
                        st2.x=i;
                        st2.y=j;
                    }
                }
                if (map[i][j]&(1<<(7-1)))
                {
                    end.x=i;
                    end.y=j;
                }
            }
        }
        bg.one=st1;
        bg.two=st2;


    while (T--)
    {

        memset(v,0,sizeof(v));
        while (!que.empty()) que.pop();

        //init_over
        cout<<bg.one.x<<bg.one.y<<bg.two.x<<bg.two.y<<endl;
        cout<<end.x<<end.y<<endl;

    }
    return 0;
}
