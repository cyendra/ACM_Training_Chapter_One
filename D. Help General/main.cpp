#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if (n==1||m==1){
        cout<<n*m<<endl;
        return 0;
    }
    if (n==2||m==2){
        if (n<m) swap(n,m);
        int c=(n/4)*2;
        if (n%4>0) c++;
        if (n%4>1) c++;
        cout<<c*2<<endl;
        return 0;
    }
    int a,b,c,d;
    a=(n+1)/2;
    b=(m+1)/2;
    c=n/2;
    d=m/2;
    cout<<a*b+c*d<<endl;
    return 0;
}
