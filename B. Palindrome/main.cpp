#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxs=55555;
const int maxn=3333;
char s[maxs];
int n;
int cnt[27];
char mc;
char ans[maxs];
int t;
int f[maxn][maxn];
int dp(int l,int r){
    if (l>r) return 0;
    if (l==r) return 1;
    //if (l+1==r) return 1+(s[l]==s[r]);
    if (f[l][r]!=-1) return f[l][r];
    if (s[l]==s[r]) return f[l][r]=dp(l+1,r-1)+2;
    return f[l][r]=max(dp(l,r-1),dp(l+1,r));
}
void trace(int l,int r){
    if (l>r) return;
    if (l==r) ans[t++]=s[l];
	else if (s[l]==s[r]){
		ans[t++]=s[l];
		trace(l+1,r-1);
		ans[t++]=s[r];
	}
	else{
		if (f[l+1][r]<f[l][r-1]) trace(l,r-1);
		else trace(l+1,r);
	}
}

int main()
{
    cin>>(s+1);
    n=strlen(s+1);
    memset(cnt,0,sizeof(cnt));
    if (n>=2600){
        for (int i=1;i<=n;i++){
            cnt[s[i]-'a']++;
        }
        for (int i=0;i<26;i++){
            if (cnt[i]>=100){
                mc=i+'a';
                break;
            }
        }
        for (int i=0;i<100;i++){
            ans[i]=mc;
        }
        ans[100]=0;
        cout<<ans<<endl;
    }
    else{
        memset(f,-1,sizeof(f));
        dp(1,n);
        t=0;
        trace(1,n);
        ans[t]=0;
        //cerr<<"nice"<<endl;
        if (t<=100) cout<<ans<<endl;
        else{
            //cout<<"boy next door"<<endl;
            for (int i=0;i<50;i++) cout<<ans[i];
            for (int i=t-50;i<t;i++) cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}
