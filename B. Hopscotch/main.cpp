#include <iostream>
#include <cstring>
using namespace std;

void solve(int a,int x,int y){
    if (y%a==0){
        cout<<-1<<endl;
        return;
    }
    int fl=y/a;
    if (fl==0){
        if (2*x<a&&2*x>-a) cout<<1<<endl;
        else cout<<-1<<endl;
        return;
    }
    int nu=(fl+1)/2;
    if (fl%2==1){
        if (2*x<a&&2*x>-a) cout<<nu*3-1<<endl;
        else cout<<-1<<endl;
        return;
    }
    else{
        if (x>0&&x<a) cout<<nu*3+1<<endl;
        else if (x<0&&x>-a) cout<<nu*3<<endl;
        else cout<<-1<<endl;
        return;
    }
}

int main()
{
    int a,x,y;
    cin>>a>>x>>y;
    solve(a,x,y);
    return 0;
}
