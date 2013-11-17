#include <iostream>

using namespace std;

const int MAXN=100;//最大点数量

int tree[MAXN];
int tree2[MAXN][MAXN];
int tree3[MAXN][MAXN][MAXN];

int n;//点数

/*
    lowbit
*/
int lowbit(int i)
{
    return i&(-i);
}


/*
    一维树状数组
*/
void updata(int i,int x)
{
    while (i<=n)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}

int query(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}


/*
    二维树状数组
*/
void updata(int x,int y,int d)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=n;j+=lowbit(j))
        {
            tree2[i][j]+=d;
        }
    }
}

int query(int x,int y)
{
    int sum=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        for (int j=y;j>0;j-=lowbit(j))
        {
            sum+=tree2[i][j];
        }
    }
    return sum;
}


/*
    三维树状数组
*/
void updata(int x,int y,int z,int d)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=n;j+=lowbit(j))
        {
            for (int k=z;k<=n;k+=lowbit(k))
            {
                tree3[i][j][k]+=d;
            }
        }
    }
}

int query(int x,int y,int z)
{
    int sum=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        for (int j=y;j>0;j-=lowbit(j))
        {
            for (int k=z;k>0;k-=lowbit(k))
            {
                sum+=tree3[i][j][k];
            }
        }
    }
    return sum;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
