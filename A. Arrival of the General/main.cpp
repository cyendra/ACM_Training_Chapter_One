#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[111];
    cin>>n;
    int mx=0,mi=999;
    int p1,p2;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]>mx){
            mx=a[i];
            p1=i;
        }
        if (a[i]<=mi){
            mi=a[i];
            p2=i;
        }
    }
    int ans=p1+(n-p2-1);
    if (p1>p2) ans--;
    cout<<ans<<endl;
    return 0;
}
