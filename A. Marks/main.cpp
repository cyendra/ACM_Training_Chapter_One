#include <iostream>

using namespace std;
int a[111][111];
char s[111][111];
bool v[111]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>(s[i]+1);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=s[i][j]-'0';
        }
    }
    for (int j=1;j<=m;j++){
        int mx=0;
        for (int i=1;i<=n;i++){
            if (a[i][j]>mx) mx=a[i][j];
        }
        for (int i=1;i<=n;i++){
            if (a[i][j]==mx) v[i]=true;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (v[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
