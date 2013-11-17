#include <iostream>

using namespace std;

struct Warm{
    int x,y,r;
}a[1111];
int n;
int x1,y1,x2,y2;
bool cold(int x,int y){
    for (int i=0;i<n;i++){
        if ( (x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)<=a[i].r*a[i].r ) return false;
    }
    return true;
}
int main()
{
    int ans=0;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    if (x1>x2) swap(x1,x2);
    if (y1>y2) swap(y1,y2);
    for (int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y>>a[i].r;
    }
    for (int i=x1;i<=x2;i++){
        if (cold(i,y1)) ans++;
        if (y1!=y2&&cold(i,y2)) ans++;
    }
    for (int i=y1+1;i<=y2-1;i++){
        if (cold(x1,i)) ans++;
        if (x1!=x2&&cold(x2,i)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
