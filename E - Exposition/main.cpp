#include <iostream>

using namespace std;

const int mm=111111;
int ma[mm<<2],mi[mm<<2],ql[mm],qr[mm];
int i,j,k,n,ans,t;

void build(int l,int r,int rt)
{
    if (l==r)
    {
        cin>>ma[rt];
        mi[rt]=ma[rt];
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    ma[rt]=max(ma[rt<<1],ma[rt<<1|1]);
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
}

int queryma(int L,int R,int l,int r,int rt)
{
    if (L<=l&&R>=r) return ma[rt];
    int m=(l+r)>>1,ret=0;
    if (L<=m) ret=max(ret,queryma(L,R,l,m,rt<<1));
    if (R>m) ret=max(ret,queryma(L,R,m+1,r,rt<<1|1));
    return ret;
}

int querymi(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r) return mi[rt];
    int m=(l+r)>>1,ret=2e9;
    if (L<=m) ret=min(ret,querymi(L,R,l,m,rt<<1));
    if (R>m) ret=min(ret,querymi(L,R,m+1,r,rt<<1|1));
    return ret;
}

int main()
{
    while (cin>>n>>k)
    {
        build(1,n,1);
        ans=t=0;
        for (i=j=1;j<=n;++i)
        {
            if (j<i) j=i;
            while (j<=n&&(queryma(i,j,1,n,1)-querymi(i,j,1,n,1)<=k))++j;
            if (j-i>ans)
            {
                ans=j-i;
                ql[0]=i;
                qr[0]=j-1;
                t=1;
            }
            else if (j-i==ans)
            {
                ql[t]=i;
                qr[t]=j-1;
                t++;
            }
        }
            cout<<ans<<" "<<t<<endl;
            for (i=0;i<t;i++)
            {
                cout<<ql[i]<<" "<<qr[i]<<endl;
            }
    }
    return 0;
}
