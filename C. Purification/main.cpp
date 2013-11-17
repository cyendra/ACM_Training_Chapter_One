#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=111;

struct POINT{
    int x;
    int y;
    POINT(int a,int b):x(a),y(b){}
};
vector<POINT>ans;
char s[maxn][maxn];
int n;

int main()
{
    bool ok;
    bool flag;
    ans.clear();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>(s[i]+1);
    //bool ret=dfs(1);
    flag=true;
    for (int i=1;i<=n;i++)
    {
        ok=false;
        for (int j=1;j<=n;j++)
        {
            if (s[i][j]=='.')
            {
                ans.push_back(POINT(i,j));
                ok=true;
                break;
            }
        }
        if (!ok)
        {
            flag=false;
            break;
        }
    }
    if (!flag)
    {
        ans.clear();
        flag=true;
        for (int j=1;j<=n;j++)
        {
            ok=false;
            for (int i=1;i<=n;i++)
            {
                if (s[i][j]=='.')
                {
                    ans.push_back(POINT(i,j));
                    ok=true;
                    break;
                }
            }
            if (!ok)
            {
                flag=false;
                break;
            }
        }
    }
    if (!flag) cout<<"-1"<<endl;
    else
    {
        //cout<<ans.size()<<endl;
        for (int i=0;i<ans.size();i++)
        {
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
        }
    }
    return 0;
}
