#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=111111;
int a[maxn];
int n,s;
vector<int>ans;
int main()
{
    while (~scanf("%d%d",&n,&s)){
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int l=0,r=n-1;
        ans.clear();
        while (l<r){
            if (a[l]+a[r]>s){
                ans.push_back(a[l++]);
                ans.push_back(a[r--]);
            }
            else{
                ans.push_back(a[l++]);
                ans.push_back(a[l++]);
            }
        }
        if (l==r) ans.push_back(a[l]);
        int res=0;
        ans.push_back(0);
        for (int i=0;i<n;i++){
            if (ans[i]+ans[i+1]<=s){
                i++;
            }
            res++;
        }
        printf("%d\n",res);
        //for (int i=0;i<n-1;i++) printf("%d ",ans[i]);
        //printf("%d\n",ans[n-1]);
    }
    return 0;
}
