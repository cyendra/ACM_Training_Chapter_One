#include <iostream>

using namespace std;

long long quick_mod(long long a,long long b,long long m)
{
    long long ans=1;
    a%=m;
    while(b)
    {
        if(b&1)           //���b���������ж�����������b&1
        {
            ans=ans*a%m;
            b--;
        }
        b>>=1;                //������൱��b/=2;
        a=a*a%m;
    }
    return ans;
}


int main()
{
    long long int a,b,c;
    while (cin>>a>>b>>c)
    {
        cout<<quick_mod(a,b,c)<<endl;
    }
    return 0;
}
