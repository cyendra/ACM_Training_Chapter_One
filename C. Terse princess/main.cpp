#include <iostream>
#include <vector>
using namespace std;

vector<int>ans;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    if (b==0&&a>0){
        if (a+b+1==n){
            cout<<-1<<endl;
            return 0;
        }
        ans.push_back(1);
        n--;
    }
    ans.push_back(1);
    for (int i=1;i<=b;i++){
        ans.push_back(1<<i);
    }
    for (int i=1;i<=a;i++){
        ans.push_back((1<<b)+i);
    }
    for (int i=a+b+2;i<=n;i++){
        ans.push_back(1);
    }
    for (int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
