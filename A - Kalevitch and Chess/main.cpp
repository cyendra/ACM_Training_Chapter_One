#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 8

char G[N][N];

int main()
{
    while(scanf("%s" , G[0]) != EOF)
    {
        for(int i = 1 ; i < 8 ; i++)
            scanf("%s", G[i]);
        int ans , i , j;
        ans = 0;
        for(i = 0 ; i < 8 ; i++)
        {
            for(j = 0 ; j < 8 ; j++)
            {
                if(G[i][j] == 'W')
                    break;
            }
            if(j == 8)/*如果是全‘B’*/
                ans++;
            for(j = 0 ; j < 8 ; j++)
            {
                if(G[j][i] == 'W')
                    break;
            }
            if(j == 8)/*如果是全‘B’*/
                ans++;
        }
        printf("%d\n" , ans == 16 ? 8 : ans);
    }
    return 0;
}

