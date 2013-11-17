#include <iostream>

using namespace std;
typedef long long LL;
const LL INFF=(1LL << 60);
int main()
{
    LL n,m,c,res;
    LL Max=0,Min=INFF;
    cin>>n;
    for (LL i=1;i*i<=n;i++){
        if (n%i==0){
            m=n/i;
            for (LL j=1;j*j<=m;j++){
                if (m%j==0){
                    c=m/j;
                    res=(i+1)*(j+2)*(c+2)-n;
                    Max=max(Max,res);
                    Min=min(Min,res);
                    res=(i+2)*(j+1)*(c+2)-n;
                    Max=max(Max,res);
                    Min=min(Min,res);
                    res=(i+2)*(j+2)*(c+1)-n;
                    Max=max(Max,res);
                    Min=min(Min,res);
                }
            }
        }
    }
    cout<<Min<<" "<<Max<<endl;
    return 0;
}
