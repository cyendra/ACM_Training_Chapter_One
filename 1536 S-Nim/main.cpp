#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int SG[10001];
bool b[10001];
int  fb[101];
int K,t,ans,m,tmp;

void getsg()
{
    int p;
    memset(SG,0,sizeof(SG));
    for (int i=0;i<=10000;i++)
    {
        memset(b,0,sizeof(b));
        for (int j=0;i-fb[j]>=0&&j<K;j++)
        {
            b[ SG[i-fb[j]] ]=true;
        }
        p=0;
        while ( b[p] ) p++;
        SG[i]=p;
    }
}

int main()
{
    while (cin >> K)
    {
        if (K==0) break;
        memset(SG,-1,sizeof(SG));
        for (int i=0;i<K;i++)
        {
            cin>>fb[i];
        }
        sort(fb,fb+K);
        getsg();
        cin>>t;
        while(t--)
        {
            cin>>m;
            ans=0;
            for (int i=0;i<m;i++)
            {
                cin>>tmp;
                ans^=SG[tmp];
            }
            if (ans==0)
            {
                cout<<"L";
            }
            else
            {
                cout<<"W";
            }
        }
        cout<<endl;
    }
    return 0;
}



/*

*/
/*
int mex(int p)
{
    int i,t;
    bool g[101]={0};
    for (i=0;i<k;i++)
    {
        t=p-fib[i];
        if (t<0) break;
        if ( f[t]==-1 )
        {
            f[t]=mex(t);
            g[ f[t] ]=1;
        }
    }
    i=0;
    while (g[i]) i++;
    return i;
}
*/

/*


int getsg(int x)
{
    int i;
    bool b[101];
    memset(b,0,sizeof(b));
    if(SG[x]!=-1) return SG[x]; //集合S一致，则每个数量的mex一样，所以可以重复利用
    if(x-s[0]<0) return SG[x]=0; //s[0]为集合中最小值，x-s[0]<0,则x不可能到达其他状态，一定为P
    for(int i=0;i<k && x-s[i]>=0;i++) //判断条件，因为s[]排了序，当x-s[i]<0就停止循环。
    {
        b[getsg(x-s[i])]=true; //x的后继SG函数中的没有出现的最小非负数
    }
    i=0;
    while (b[i]) i++; //通过x的后继SG函数出现的非负数得x的结果
    SG[x]=i;
    return i;
}



*/
