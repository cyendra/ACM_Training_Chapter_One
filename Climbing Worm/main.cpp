#include <iostream>

using namespace std;

int n,u,d;
int ans;
int p;

int main()
{
    while (cin>>n)
    {
        cin>>u>>d;
        if (n==0) break;
        ans=0;
        p=0;
        while (p<n)
        {
            p+=u;ans++;
            if (p<n){
                p-=d;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
