/*
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const double OO=1e9;

int n;
int a[1111];
int mina,maxa;
double p,t,l;

int main()
{
    memset(a,0,sizeof(a));
    t=0;
    l=0;
    p=OO;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=2;i<=n;i++)
    {
        t=double(10+10*(a[i]-a[1]))/double(i-1);
        //cout<<t<<endl;
        if (t<p) p=t;
    }
    t=(n*p+10.0*a[1]-10.0)/10.0;
    maxa=int(floor(t))-1;
    mina=int(ceil((n*10+10.0*a[1]-10.0)/10.0))+1;
    cout<<maxa<<" "<<mina<<endl;
    if (maxa!=mina)
    {
        cout<<"not unique"<<endl;
    }
    else
    {
        cout<<"unique"<<endl;
        cout<<maxa<<endl;
    }

    return 0;
}
*/
#include <iostream>
using namespace std;
int n;
int a,b;
int c=1e9,e;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        e=a*double(n+1)/double(i);
        if(b<e)b=e;
        e=(a+1.0-1e-9)*(n+1)/(double(i));
        if(c>e)c=e;
    }
    if (b==c)
    cout<<"unique\n"<<b;
    else cout<<"not unique\n";
}
