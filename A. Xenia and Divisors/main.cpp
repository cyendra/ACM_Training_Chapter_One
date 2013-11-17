#include <iostream>

using namespace std;
int n;
int a[10]={0};
bool check(){
    for (int i=1;i<=7;i++) if (a[i]<0) return true;
    return false;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
    }
    if (n%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    if (a[5]>0||a[7]>0){
        cout<<-1<<endl;
        return 0;
    }
    int c1,c2,c3;
    c1=a[3];
    a[1]-=c1;
    a[3]-=c1;
    a[6]-=c1;
    if (check()){
        cout<<-1<<endl;
        return 0;
    }
    c2=a[6];
    a[1]-=c2;
    a[2]-=c2;
    a[6]-=c2;
    if (check()){
        cout<<-1<<endl;
        return 0;
    }
    c3=a[4];
    a[1]-=c3;
    a[2]-=c3;
    a[4]-=c3;
    if (check()){
        cout<<-1<<endl;
        return 0;
    }
    if (c1*3+c2*3+c3*3!=n){
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=7;i++) if (a[i]!=0) {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=0;i<c3;i++) cout<<"1 2 4"<<endl;
    for (int i=0;i<c2;i++) cout<<"1 2 6"<<endl;
    for (int i=0;i<c1;i++) cout<<"1 3 6"<<endl;
    return 0;
}
