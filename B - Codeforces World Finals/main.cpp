#include <iostream>
#include <cstdio>

using namespace std;

int dd,mm,yy;

int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool get(int d,int m,int y)
{
    if (m>12) return false;
    if (d>a[m]) return false;
    if (m==2&&d==29&&(y%4!=0)) return false;
    if ( (y+18)*365+m*30+d<=yy*365+mm*30+dd ) return true;
    return false;
}

int main()
{
    int d,m,y;
    scanf("%d.%d.%d",&dd,&mm,&yy);
    scanf("%d.%d.%d",&d,&m,&y);
    if (get(d,m,y)) cout<<"YES"<<endl;
    else if (get(d,y,m)) cout<<"YES"<<endl;
    else if (get(m,d,y)) cout<<"YES"<<endl;
    else if (get(m,y,d)) cout<<"YES"<<endl;
    else if (get(y,m,d)) cout<<"YES"<<endl;
    else if (get(y,d,m)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
