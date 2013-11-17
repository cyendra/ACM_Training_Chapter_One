#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=1111;
const int maxm=2222222;

struct EDGENODE{
    int to;
    int next;
}edges[maxm];
int head[maxn];
int edge;

void addedge(int u,int v)
{
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;

}

