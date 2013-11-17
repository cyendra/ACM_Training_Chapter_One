#include <iostream>

using namespace std;

bool v[100001]={0};

int main()
{
    int n,t,ans;
    v[0]=true;
    v[1]=true;
    for (int i=2;i<=100000;i++)
    {
        if (!v[i])
        {
            for (int j=i+i;j<=100000;j+=i)
            {
                v[j]=true;
            }
        }
    }
    while (cin>>n)
    {
        ans=0;
        for (int i=0;i<n;i++)
        {
            cin>>t;
            if (!v[t])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
