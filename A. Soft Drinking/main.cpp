#include <iostream>
using namespace std;
const int INF=0x3f3f3f;
int n,k,l,c,d,p,nl,np;
int main()
{
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int ans=INF;
    ans=min(ans,k*l/nl);
    ans=min(ans,c*d);
    ans=min(ans,p/np);
    cout<<ans/n<<endl;
    return 0;
}
