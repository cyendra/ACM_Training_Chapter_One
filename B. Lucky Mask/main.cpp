#include <iostream>
#include <cmath>
using namespace std;
bool check(int a,int b){
    int n=0;
    int i=1;
    while (a>0){
        int t=a%10;
        a/=10;
        if (t==4||t==7){
            n=t*i+n;
            i*=10;
        }
    }
    if (n==b) return true;
    return false;
}
int main()
{
    int a,b;
    cin>>a>>b;
    if (a<b) cout<<b<<endl;
    else{
        do{
            a++;
        }while (!check(a,b));
        cout<<a<<endl;
    }
    return 0;
}
