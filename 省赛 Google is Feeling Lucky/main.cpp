#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int T;
struct DATA{
    string name;
    int v;
    int id;
}a[1111];

bool cmp(DATA a,DATA b)
{
    if (a.v==b.v) return a.id<b.id;
    return a.v>b.v;
}

int main()
{
    cin>>T;
    for (int lp=1;lp<=T;lp++)
    {
        for (int i=0;i<10;i++)
        {
            cin>>a[i].name>>a[i].v;
            a[i].id=i;
        }
        sort(a,a+10,cmp);
        int t=a[0].v;
        cout<<"Case #"<<lp<<":"<<endl;
        cout<<a[0].name<<endl;
        for (int i=1;i<10;i++)
        {
            if (a[i].v==t)
            {
                cout<<a[i].name<<endl;
            }
        }
    }
    return 0;
}
