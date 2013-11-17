#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
bool v[5555]={0};
int n;
char s[5555][5555];
bool dfs(int i,int dad)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
    {
        if (s[i][j]-'0')
        {
            if (s[j][dad]-'0')
            {
                printf("%d %d %d\n",dad,i,j);
                return true;
            }
            if (!v[j])
            {
                if (dfs(j,i)) return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }

    for (int i=1;i<=n;i++)
    {
        if (!v[i])
        {
            if (dfs(i,i)) return 0;
        }
    }
    printf("-1\n");
    return 0;
}
