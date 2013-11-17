#include <iostream>
#include <cstring>

using namespace std;

//N=0,E=1,S=2,W=3

typedef struct{
    int x;
    int y;
    int d;
}ROB;

ROB a[300];
int map[111][111];

int T;
int A,B;
int n,m;

FILE *f;

int change(char c)
{
    int r;
    switch (c)
    {
        case 'N':
        {
            r=0;
            break;
        }
        case 'E':
        {
            r=1;
            break;
        }
        case 'S':
        {
            r=2;
            break;
        }
        case 'W':
        {
            r=3;
            break;
        }
    }
    return r;
}

bool checkwall(ROB t)
{
    if (t.x>=1 && t.x<=A && t.y>=1 && t.y<=B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkrob(ROB t)
{
    return map[t.x][t.y];
}

int main()
{
    int rob,rep;
    char chr,act;
    int robnotok;
    bool wallok,robok;
    int ansrob;
    cin>>T;
    while (T--)
    {
        wallok=true;
        robok=true;
        memset(map,0,sizeof(map));
        cin>>A>>B;
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>chr;
            a[i].d=change(chr);
            map[a[i].x][a[i].y]=i;
        }
        for (int i=1;i<=m;i++)
        {
            cin>>rob>>act>>rep;
            if (!robok) continue;
            if (!wallok) continue;
            switch (act)
            {
                case 'F':
                {
                    map[a[rob].x][a[rob].y]=0;
                    switch ( a[rob].d )
                    {
                        case 0:
                        {
                            for (int j=0;j<rep;j++)
                            {
                                a[rob].y++;
                                if ( !checkwall(a[rob]) )
                                {
                                    wallok=false;
                                    ansrob=rob;
                                    break;
                                }
                                else if ( checkrob(a[rob]) )
                                {
                                    robok=false;
                                    ansrob=rob;
                                    robnotok=checkrob(a[rob]);
                                    break;
                                }
                            }
                            if (robok&&wallok) map[a[rob].x][a[rob].y]=rob;
                            break;
                        }
                        case 1:
                        {
                            for (int j=0;j<rep;j++)
                            {
                                a[rob].x++;
                                if ( !checkwall(a[rob]) )
                                {
                                    ansrob=rob;
                                    wallok=false;
                                    break;
                                }
                                else if ( checkrob(a[rob]) )
                                {
                                    robok=false;
                                    ansrob=rob;
                                    robnotok=checkrob(a[rob]);
                                    break;
                                }
                            }
                            if (robok&&wallok) map[a[rob].x][a[rob].y]=rob;
                            break;
                        }
                        case 2:
                        {
                            for (int j=0;j<rep;j++)
                            {
                                a[rob].y--;
                                if ( !checkwall(a[rob]) )
                                {
                                    wallok=false;
                                    ansrob=rob;
                                    break;
                                }
                                else if ( checkrob(a[rob]) )
                                {
                                    robok=false;
                                    ansrob=rob;
                                    robnotok=checkrob(a[rob]);
                                    break;
                                }
                            }
                            if (robok&&wallok) map[a[rob].x][a[rob].y]=rob;
                            break;
                        }
                        case 3:
                        {
                            for (int j=0;j<rep;j++)
                            {
                                a[rob].x--;
                                if ( !checkwall(a[rob]) )
                                {
                                    wallok=false;
                                    ansrob=rob;
                                    break;
                                }
                                else if ( checkrob(a[rob]) )
                                {
                                    robok=false;
                                    ansrob=rob;
                                    robnotok=checkrob(a[rob]);
                                    break;
                                }
                            }
                            if (robok&&wallok) map[a[rob].x][a[rob].y]=rob;
                            break;
                        }
                    }
                    break;
                }
                case 'L':
                {
                    a[rob].d=(4+a[rob].d-rep%4)%4;
                    break;
                }
                case 'R':
                {
                    a[rob].d=(a[rob].d+rep)%4;
                    break;
                }
            }

        }
        if (!robok)
        {
            cout<<"Robot "<<ansrob<<" crashes into robot "<<robnotok<<endl;
        }
        else if (!wallok)
        {
            cout<<"Robot "<<ansrob<<" crashes into the wall"<<endl;
        }
        if (robok&&wallok)
        {
            cout<<"OK"<<endl;
        }
    }
    return 0;
}
