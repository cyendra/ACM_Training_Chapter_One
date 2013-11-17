#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct tp{
    int d;
    int v;
}a[4];

bool cmp(tp a,tp b)
{
    return a.v>b.v;
}

int main()
{
    cin>>a[0].v>>a[1].v>>a[2].v;
    a[0].d=1;
    a[1].d=2;
    a[2].d=3;
    sort(a,a+3,cmp);
    for (int i=0;i<3;i++)
    {
        cout<<a[i].d<<" ";
    }
    cout<<endl;
    return 0;
}
