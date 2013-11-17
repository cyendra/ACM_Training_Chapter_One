#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,ah,am,as,bh,bm,bs,th,tm,ts;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
        th=0;
        tm=0;
        ts=0;
        ts=as+bs;
        tm=ts / 60;
        ts=ts % 60;
        tm=tm+am+bm;
        th=tm / 60;
        tm=tm % 60;
        th=th+ah+bh;
        printf("%d %d %d\n",th,tm,ts);
    }
    return 0;
}
