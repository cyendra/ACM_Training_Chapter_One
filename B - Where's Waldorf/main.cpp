#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

const int direct[8][2]= { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };

char map[55][55];
int n,m;
bool v[55][55];
char s[55];
int len;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

bool dfs(int x,int y,int deep,int g)
{
    if (deep>=len) return true;
    if (!check(x,y)) return false;
    if (map[x][y]!=s[deep]) return false;
    int dx=x+direct[g][0];
    int dy=y+direct[g][1];
    if (dfs(dx,dy,deep+1,g)) return true;
    return false;
}

int main()
{
    int T,k;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++) cin>>(map[i]+1);
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
            if (islower(map[i][j])) map[i][j]=toupper(map[i][j]);
        cin>>k;
        //for (int i=1; i<=n; i++) cerr<<(map[i]+1)<<endl;
        while (k--)
        {
            int i,j,g;
            bool ok=false;
            cin>>s;
            len=strlen(s);
            for (i=0; i<len; i++)
                if (islower(s[i])) s[i]=toupper(s[i]);
            //cerr<<s<<endl;
            for (i=1; i<=n; i++)
            {
                for (j=1; j<=m; j++)
                {
                    for (g=0; g<8; g++)
                    {
                        if (dfs(i,j,0,g))
                        {
                            ok=true;
                            cout<<i<<" "<<j<<endl;
                            break;
                        }
                    }
                    if (ok) break;
                }
                if (ok) break;
            }
        }
        if (T) cout<<endl;
    }
    return 0;
}
