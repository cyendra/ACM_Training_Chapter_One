#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f;
const int MAXN=10000;
struct Data{
    string name;
    int a;
    int h;
}f[MAXN];
bool cmp(Data x,Data y){
    return x.a<y.a;
}
int n,m;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>f[i].name>>f[i].a;
    }
    sort(f,f+n,cmp);
    for (int i=0;i<n;i++){
        if (f[i].a>i){
            cout<<-1<<endl;
            return 0;
        }
    }
    m=0;
    for (int i=0;i<n;i++){
        f[i].h=i+1-f[i].a;
        for (int j=0;j<i;j++){
            if (f[j].h>=f[i].h) f[j].h++;
        }

    }
    for (int i=0;i<n;i++){
        cout<<f[i].name<<" "<<f[i].h<<endl;
    }
    return 0;
}
