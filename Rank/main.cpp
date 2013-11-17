#include <iostream>
#include <algorithm>

using namespace std;

struct STU{
    int name;
    int grade;
}a[11111];

int jack;
int n;

bool cmp(STU a,STU b)
{
    if (a.grade==b.grade) return a.name<b.name;
    return a.grade>b.grade;
}

int main()
{
    int x,y;
    n=0;
    int p=0;
    while (cin>>jack)
    {
        n=0;
        p=0;
        while (cin>>x>>y)
        {
            if (x==0&&y==0) break;
            a[n].name=x;
            a[n].grade=y;
            if (x==jack) p=n;
            n++;
        }
        //cout<<p<<endl;
        int ans=1;
        for (int i=0;i<n;i++)
        {
            if (a[i].grade>a[p].grade) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
