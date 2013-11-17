#include <iostream>

using namespace std;

int gcd(int x,int y){
    if (x<y) swap(x,y);
    int t;
    while (y!=0){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main()
{
    int x,y,a,b,n;
    cin>>x>>y>>a>>b;
    n=lcm(x,y);
    cout<<b/n-(a-1)/n<<endl;
    return 0;
}
