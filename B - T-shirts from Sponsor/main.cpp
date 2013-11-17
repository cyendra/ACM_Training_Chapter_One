#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int ns,nm,nl,nxl,nxxl;
int n;
string s;
int a[1111];
int sml[5];
int ans[1111];

int abs(int x)
{
    if (x<0) return -x;
    else return x;
}

void smlput( int t )
{
    if (t==0) cout<<"S";
    if (t==1) cout<<"M";
    if (t==2) cout<<"L";
    if (t==3) cout<<"XL";
    if (t==4) cout<<"XXL";
    cout<<endl;
}

int main()
{
    cin>>sml[0]>>sml[1]>>sml[2]>>sml[3]>>sml[4];
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (s=="S")
        {
            a[i]=0;
        }
        if (s=="M")
        {
            a[i]=1;
        }
        if (s=="L")
        {
            a[i]=2;
        }
        if (s=="XL")
        {
            a[i]=3;
        }
        if (s=="XXL")
        {
            a[i]=4;
        }
    }
    for (int i=1;i<=n;i++)
    {
        int p;
        int cls;
        cls=999;
        p=a[i];
        for (int j=0;j<=4;j++)
        {
            if ( abs(j-a[i])<cls&&sml[j]>0 )
            {
                p=j;
                cls=abs(j-a[i]);
            }
            else if (abs(j-a[i])==cls&&j>=p&&sml[j]>0)
            {
                p=j;
            }
        }
        ans[i]=p;
        sml[p]--;
    }
    for (int i=1;i<=n;i++)
    {
        smlput(ans[i]);
    }
    return 0;
}
