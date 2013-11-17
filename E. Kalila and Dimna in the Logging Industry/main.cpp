/*
//f[i]=min(f[j]+a[i]*b[j]) j<i
//-a[i]*b[j]+f[i]=f[j]
//令f[j]为y，b[j]为x，-a[i]为k，截距为dp[i]
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

typedef long long LL;

const int maxn=111111;

LL a[maxn],b[maxn],f[maxn];
int n;
int que[maxn*4];
int head,tail;
//y1-y2
LL fun(int k1,int k2){
    return f[k1]-f[k2];
}
//y1-y2>=k*(x1-x2)
bool cmp_head(int k1,int k2,int i){
    return fun(k1,k2)>=-a[i]*(b[k1]-b[k2]);
}
//y1-y2/x1-x2>=y2-yi/x2-xi
bool cmp_tail(int k1,int k2,int i){
    return double(fun(k1,k2))/double(b[k1]-b[k2])>=double(fun(k2,i))/double(b[k2]-b[i]);
}
//y-kx
LL dp_sol(int i,int j){return f[j]+a[i]*b[j];}
//y1-y2/x1-x2
double k_sol(int i,int j){return double(f[i]-f[j])/double(b[i]-b[j]);}

int main()
{
    while (cin>>n)
    {
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i];
        head=tail=0;
        que[tail++]=0;
        f[0]=0;
        for (int i=1;i<n;i++)
        {
            while (tail-head>1&&dp_sol(i,que[head])>=dp_sol(i,que[head+1])) head++;
            //while (tail-head>1&&cmp_head(que[head],que[head+1],i)) head++;
            f[i]=dp_sol(i,que[head]);
            while (tail-head>1&&k_sol(i,que[tail-1])>=k_sol(que[tail-1],que[tail-2])) tail--;
            //while (tail-head>1&&cmp_tail(que[tail-2],que[tail-1],i) ) tail--;
            que[tail++]=i;
        }
        cout<<f[n-1]<<endl;
    }
    return 0;
}
