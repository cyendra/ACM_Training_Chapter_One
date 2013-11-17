#include <iostream>
#include <cstring>

using namespace std;

int k;
int s[50];
bool b[50];
int ans[10];

void dfs( int deep ,int bg )
{
    if ( deep>=6 )
    {
        for (int i=0;i<5;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[5]<<endl;
        return;
    }
    else
    {
        for (int i=bg;i<k;i++)
        {
            if ( b[i]==false )
            {
                b[i]=true;
                ans[deep]=s[i];
                dfs(deep+1,i+1);
                b[i]=false;
            }
        }
    }
}

int main()
{
    while(cin>>k)
    {
        if (k==0)
        {
            break;
        }
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        for (int i=0;i<k;i++)
        {
            cin>>s[i];
        }
        dfs(0,0);
    }
    return 0;
}
