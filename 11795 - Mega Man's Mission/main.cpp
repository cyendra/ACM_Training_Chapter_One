#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int BIT=1<<17;

int n;

int kill[20];
int baskill;
int g[BIT];
long long f[BIT];

int main()
{
    int T;
    char s[111111];
    int cnt=1;
    scanf("%d",&T);
    while (T--)
    {
        memset(kill,0,sizeof(kill));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        baskill=0;
        scanf("%d",&n);

        //读入基础攻击力
        scanf("%s",s);
        for (int k=0; s[k]; k++)
        {
            if (s[k]=='1')
            {
                baskill=baskill|(1<<k);
            }
        }
        //cerr<<"basekill= "<<baskill<<endl;

        //读入每个敌人的武器
        for (int i=0; i<n; i++)
        {
            scanf("%s",s);
            for (int k=0; s[k]; k++)
            {
                if (s[k]=='1')
                {
                    kill[i]=kill[i]|(1<<k);
                }
            }
            //cerr<<"emp= "<<kill[i]<<endl;
        }

        //处理武器收入量
        for (int i=0; i<(1<<n); i++)
        {
            g[i]=baskill;
            int bit;
            for (int k=0; k<n; k++)
            {
                bit=1<<k;
                if (i&bit)
                {
                    g[i]=g[i]|kill[k];
                }
            }
            //cerr<<i<<" "<<g[i]<<endl;
        }
        f[0]=1LL;
        for (int i=1; i<(1<<n); i++)
        {
            int bit;
            for (int k=0; k<n; k++)
            {
                bit=1<<k;
                if ((i&bit)&&(g[i^bit]&bit))
                {
                    f[i]+=f[i^bit];
                }
            }
            //cerr<<"f= "<<f[i]<<endl;
        }
        printf("Case %d: %lld\n",cnt++,f[(1<<n)-1]);
    }
    return 0;
}

/*

*/
