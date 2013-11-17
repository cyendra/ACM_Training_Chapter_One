#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct Dat{
    int v;
    int id;
};

Dat a[111111];
bool cmp(Dat a,Dat b){
    return a.v<b.v;
}
vector<int>ansx,ansy;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].v;
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    //for (int i=0;i<n;i++) cout<<a[i].v<<" ";cout<<endl;
    int sumx=0,sumy=0;
    for (int i=0;i<n-1;i++){
        if (i&1){
            ansx.push_back(a[i].id);
            sumx+=a[i].v;
        }
        else{
            ansy.push_back(a[i].id);
            sumy+=a[i].v;
        }
    }
    if (sumx<sumy) ansx.push_back(a[n-1].id);
    else ansy.push_back(a[n-1].id);
    cout<<ansx.size()<<endl;
    for (int i=0;i<(int)ansx.size();i++) cout<<ansx[i]<<" ";cout<<endl;
    cout<<ansy.size()<<endl;
    for (int i=0;i<(int)ansy.size();i++) cout<<ansy[i]<<" ";cout<<endl;
    return 0;
}
