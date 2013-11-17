#include <iostream>

using namespace std;

class TrafficCongestionDivTwo{
    private:
        long long two[70];
    public:
    long long theMinCars(int treeHeight)
    {
        long long ans=0;
        int n=treeHeight;
        two[0]=1;
        for (int i=1;i<61;i++) two[i]=two[i-1]*2;
        while (n>=1)
        {
            ans+=two[n-1];
            n-=2;
        }
        if (n==0) ans+=1;
        return ans;
    }
};

int main()
{
    int n;
    TrafficCongestionDivTwo sol;
    cin>>n;
    cout<<sol.theMinCars(n)<<endl;
    return 0;
}
