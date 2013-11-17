#include <iostream>
#include <string>

using namespace std;

string s;
int k;
long long cnt[2222222]={0};
long long sum;
long long ans;

int main()
{
    cin>>k;
    cin>>s;
    int len=s.length();
    sum=0;
    ans=0;
    for (int i=0;i<len;i++)
    {
        cnt[sum]++;
        if (s[i]=='1') sum++;
        if (sum-k>=0) ans+=cnt[sum-k];
    }
    cout<<ans<<endl;
    return 0;
}
