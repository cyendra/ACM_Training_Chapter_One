#include <iostream>

using namespace std;

const int MAXN=9999;
int n;
int root[MAXN];

void make_set(int n)
{
    for (int i=1; i<=n; i++) root[i]=i;
}

int find_set(int x)
{
    if ( root[x]^x ) root[x]=find_set(root[x]);
    return root[x];
}

void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    root[y]=x;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
