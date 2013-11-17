#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

class LISNumberDivTwo{
    private:
    public:
        int calculate(vector<int> seq)
        {
            int ans=0;
            int n=seq.size();
            for (int i=0;i<n;i++)
            {
                while (i+1<n&&seq[i]<seq[i+1]) i++;
                ans++;
            }
            return ans;
        }
};

int main()
{
    int n;
    vector<int>seq;
    seq.clear();
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        seq.push_back(t);
    }
    LISNumberDivTwo sol;
    cout<<sol.calculate(seq)<<endl;
    return 0;
}
