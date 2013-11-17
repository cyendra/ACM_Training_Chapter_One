#include <iostream>

using namespace std;

long long int s[500010];

int phi(int n) {
    int rea=n;
    for(int i=2; i*i<=n; i++) { //这里的i*i<=n就相等于i小于等于根号下n
        if(n%i==0) {
            rea=rea-rea/i;
            do {
                n/=i;
            } while(n%i==0);
        }
    }
    if(n>1) {
        rea=rea-rea/n;
    }
    return rea;
}


int main() {
    int n;
    s[1]=phi(1);
    for (int i=2; i<=500000; i++) {
        s[i]=s[i-1]+phi(i);
    }
    while (cin>>n) {
        cout<<s[n]<<endl;
    }
    return 0;
}
