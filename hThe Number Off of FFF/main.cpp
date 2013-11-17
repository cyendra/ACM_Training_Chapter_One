#include <iostream>
#include <cstdio>
using namespace std;
int a[111111];
int n;
int main()
{
    int T;
    int ans;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        ans=1;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for (int i=2;i<=n;i++){
            if (a[i]!=a[i-1]+1){
                ans=i;
                break;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
