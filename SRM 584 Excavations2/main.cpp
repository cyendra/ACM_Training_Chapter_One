#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Excavations2{
    private:
        long long ans;
        int n;
        int num[55];
        long long c[55][55];
        int a[55];
        int f[55];
        long long myc(int n,int r)
        {
            if (c[n][r]!=0) return c[n][r];
            long long sum=1;
            for (int i=1;i<=r;i++)
                sum=sum*(n+1-i)/i;
            c[n][r]=sum;
            return sum;
        }
        void dfs(int sp,int h)
        {
            if (h<0) return;
            if (n-sp-1>h) return;
            if (sp>=n&&h>0) return;
            if (sp==n)
            {
                long long tmp=1;
                for (int i=0;i<n;i++)
                    tmp*=myc(num[f[i]],a[i]);
                ans+=tmp;
                return;
            }
            for (int i=1;i<=num[f[sp]];i++)
            {
                a[sp]=i;
                dfs(sp+1,h-i);
            }
        }
    public:
    long long count(vector<int> kind, vector<int> found, int K)
    {
        memset(num,0,sizeof(num));
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        n=found.size();
        for (int i=0;i<n;i++) f[i]=found[i];
        for (int i=0;i<kind.size();i++) num[kind[i]]++;
        ans=0;
        dfs(0,K);
        return ans;
    }
};

int main()
{
    vector<int> kind;
    vector<int> found;
    int K;
    int t,m;
    Excavations2 solver;
    cin>>m;
    while (m--)
    {
        cin>>t;
        kind.push_back(t);
    }
    cin>>m;
    while (m--)
    {
        cin>>t;
        found.push_back(t);
    }
    cin>>K;
    cout<<solver.count(kind,found,K);
    return 0;
}
