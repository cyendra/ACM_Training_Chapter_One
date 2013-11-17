#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x,y,d;
    cin>>x>>y;
    d=abs(x)+abs(y);
    if (x>0&&y>0){
        cout<<"0 "<<d<<" "<<d<<" 0"<<endl;
    }
    if (x<0&&y>0){
        cout<<-d<<" 0 0 "<<d<<endl;
    }
    if (x>0&&y<0){
        cout<<"0 "<<-d<<" "<<d<<" 0"<<endl;
    }
    if (x<0&&y<0){
        cout<<-d<<" 0 0 "<<-d<<endl;
    }
    return 0;
}
