#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class TopFox{
    public:
        int possibleHandles(string a,string b)
        {
            int ans;
            set<string>st;
            for (int i=0;i<a.size();i++)
            {
                for (int j=0;j<b.size();j++)
                {
                    st.insert(a.substr(0,i+1)+b.substr(0,j+1));
                }
            }
            ans=st.size();
            return ans;
        }
};

string a,b;
int ans;
int main()
{
    TopFox solver;

    cin>>a>>b;
    cout<<solver.possibleHandles(a,b)<<endl;
    return 0;
}
