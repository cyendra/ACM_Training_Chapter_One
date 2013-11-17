#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int tree[2222][2222];

int lowbit(int i)
{
    return i&(-i);
}

void updata(int x,int y,int d)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=n;j+=lowbit(j))
        {
            tree[i][j]+=d;
        }
    }
}

int query(int x,int y)
{
    int ret=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        for (int j=y;j>0;j-=lowbit(j))
        {
            ret+=tree[i][j];
        }
    }
    return ret;
}

int main()
{
    int x,y,d,l,r,b,t;
    int type;
    while (scanf("%d",&type)!=EOF)
    {
        if (type==0)
        {
            scanf("%d",&n);
            memset(tree,0,sizeof(tree));
        }
        if (type==1)
        {
            scanf("%d%d%d",&x,&y,&d);
            x++;
            y++;
            updata(x,y,d);
        }
        if (type==2)
        {
            scanf("%d%d%d%d",&l,&b,&r,&t);
            l++;
            r++;
            b++;
            t++;
            int ret=query(r,t)-query(l-1,t)-query(r,b-1)+query(l-1,b-1);
            printf("%d\n",ret);
        }
        if (type==3)
        {
            break;
        }
    }
    return 0;
}
