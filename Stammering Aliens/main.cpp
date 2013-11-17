#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;

const int SIZE = 100003;
const int SEED = 13331;
const int MAX_N = 50000 + 10;
char s[MAX_N];
struct HASH{
    ULL H[MAX_N];
    ULL XL[MAX_N];
    int len;
    HASH(){}
    void build(char *s){
        len=strlen(s);
        H[len]=0;
        XL[0]=1;
        for (int i=len-1;i>=0;i--){
            H[i]=H[i+1]*SEED+s[i];
            XL[len-i]=XL[len-i-1]*SEED;
        }
    }
    ULL hash(int i,int L){
        return H[i]-H[i+L]*XL[L];
    }
}hs;
int m,n;
int pos;
int rank[MAX_N];
ULL hash[MAX_N];
int cmp(const int & a, const int & b){
    return hash[a]<hash[b]||(hash[a]==hash[b]&&a<b);
}
bool possible(int L)
{
    int c=0;
    pos=-1;
    for (int i=0;i<n-L+1;i++)
    {
        rank[i]=i;
        hash[i]=hs.hash(i,L);
    }
    sort(rank,rank+n-L+1,cmp);
    for (int i=0;i<n-L+1;i++)
    {
        if (i==0||hash[rank[i]]!=hash[rank[i-1]]) c=0;
        c++;
        if (c>=m) pos=max(pos,rank[i]);
    }
    return pos>=0;
}

int main()
{
    while (~scanf("%d",&m))
    {
        if (m==0) break;
        scanf("%s",s);
        n=strlen(s);
        hs.build(s);
        if (!possible(1)) printf("none\n");
        else{
            int L=1,R=n;
            int ans=L;
            while (L<=R)
            {
                int M=L+(R-L)/2;
                if (possible(M)){
                    ans=M;
                    L=M+1;
                }else{
                    R=M-1;
                }
            }
            possible(ans);
            printf("%d %d\n",ans,pos);
        }
    }
    return 0;
}
