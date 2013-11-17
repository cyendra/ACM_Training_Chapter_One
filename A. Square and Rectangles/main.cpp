#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF=1e9+7;

int n;
int xx1[6],xx2[6],yy1[6],yy2[6];

int main()
{
    int maxx=0;
    int maxy=0;
    int minx=INF;
    int miny=INF;
    int sum=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>xx1[i]>>yy1[i]>>xx2[i]>>yy2[i];
        maxx=max(maxx,xx2[i]);
        maxy=max(maxy,yy2[i]);
        minx=min(minx,xx1[i]);
        miny=min(miny,yy1[i]);
        sum+=(yy2[i]-yy1[i])*(xx2[i]-xx1[i]);
    }
    if (maxx-minx==maxy-miny&&
        (maxy-miny)*(maxy-miny)==sum) puts("YES");
    else puts("NO");
    return 0;
}
