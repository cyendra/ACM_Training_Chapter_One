#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n,sum;
    string s1,s2;
    set<string>st;
    map<string,string>mp;
    set<string>::iterator sit;
    map<string,string>::iterator mit;
    while (scanf("%d",&n))
    {
        st.clear();
        mp.clear();
        if (n==0)
        {
            break;
        }
        for (int i=0;i<n;i++)
        {
            cin >> s1>>s2;
            st.insert(s1);
            st.insert(s2);
            mp[s2]=s1;
        }
        sum=0;
        for( sit=st.begin();sit!=st.end();sit++)
        {
            if (mp[*sit].length()==0)
            {
                sum++;
            }
        }
        if (sum==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
