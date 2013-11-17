#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    int a[13];
    int sum=0;
    int ans=-1;
    cin>>k;
    for (int i=0;i<12;i++){
        cin>>a[i];
    }
    sort(a,a+12,greater<int>());
    if (k==0){
        cout<<0<<endl;
        return 0;
    }
    for (int i=0;i<12;i++){
        sum+=a[i];
        if (sum>=k){
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
