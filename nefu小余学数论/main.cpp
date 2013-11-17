#include <iostream>

using namespace std;

long long mod_mul(long long x,long long y,long long n){
if(!x)return 0;
return (((x&1)*y)%n+(mod_mul(x>>1,y,n)<<1)%n)%n;
}

long long a_b_mod_c(long long a,long long b,long long c)
{
    long long quan=a,res=1 ;//res用于保存结果
                                        //quan 做位权记录
    while(b)
    {
        if(b%2)
        res=(res*quan)%c ;
        quan=(quan*quan)%c ;
        b>>=1 ;
    }
    return res ;
}
/*
__long long a_b_Mod_c(__long long a,__long long b,__long long c)
{
    int digit[64];
    int i,k ;
    __long long result=1 ;
    i=0 ;
    while(b) //将b转化为2进制
    {
        digit[i++]=b%2 ;
        b>>=1 ;
    }
    for(k=i-1;k>=0;k--)//b2进制的高位开始
    {
        result=(result*result)%c ;//反复平方法
        if(digit[k]==1)
        {
            result=(result*a)%c ;
        }
    }
    return result ;
}
*/
int main()
{
    long long int a,b,c,ans;
    while (cin>>a>>b>>c)
    {
        ans=mod_mul(a,b,c);
        cout<<ans<<endl;
    }
    return 0;
}
