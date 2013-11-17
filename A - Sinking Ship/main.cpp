#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct MAN{
    int d;
    int v;
    string name;
}a[111];

int n;
string s;

bool cmp(MAN a,MAN b)
{
    if (a.v!=b.v) return a.v<b.v;
    return a.d<b.d;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].name>>s;
        if (s=="rat") a[i].v=1;
        if (s=="woman") a[i].v=2;
        if (s=="child") a[i].v=2;
        if (s=="man") a[i].v=3;
        if (s=="captain") a[i].v=4;
        a[i].d=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        cout<<a[i].name<<endl;
    }
    return 0;
}
