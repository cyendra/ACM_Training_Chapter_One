#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

//110=6 001=1 011=3 100=4

int f[1<<12];
int tmp;

int dfs(int x)
{
    //cerr<<"x= "<<x<<endl;
    //getchar();
    if (f[x]!=-1) return f[x];
    int ret=0;
    for (int i=0;i<10;i++)
    {
        int t=x;
        if ( (x&(1<<(i+2))) && (x&(1<<(i+1))) && (x&(1<<i))==0 )
        {
            t^=(6<<i);
            t|=(1<<i);
            //cerr<<"check ok x= "<<x<<" i= "<<i<<" 6<<i= "<<(6<<i)<<" t="<<t<<endl;
            ret=max( ret, dfs(t)+1 );
        }
        t=x;
        if ( (x&(1<<(i+2)))==0 && (x&(1<<(i+1))) && (x&(1<<i)) )
        {
            t^=(3<<i);
            t|=(4<<i);
            //cerr<<"check ok x= "<<x<<" t="<<t<<endl;
            ret=max( ret, dfs(t)+1 );
        }
    }
    f[x]=ret;
    return ret;
}

ofstream fout("coco.out");

int main()
{
    int T;
    char s[20];
    int black,bit;
    memset(f,-1,sizeof(f));
    scanf("%d",&T);
    while (T--)
    {
        bit=0;
        black=0;
        scanf("%s",s);
        for (int i=0;s[i];i++)
        {
            if (s[i]=='o')
            {
                bit|=(1<<i);
                black++;
            }
        }
        //¶ÁÈëÍê±Ï
        int ans=dfs(bit);
        printf("%d\n",black-ans);
        //fout<<black-ans<<endl;
    }
    return 0;
}
