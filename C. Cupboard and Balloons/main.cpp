#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r,h;
    int ans=0;
    cin>>r>>h;
    ans+=h/r*2;
    h=h%r;
    if (h>=sqrt(3)/2*r) ans+=3;
    else if (h>=1.0*r/2) ans+=2;
    else ans+=1;
    cout<<ans<<endl;
    return 0;
}
