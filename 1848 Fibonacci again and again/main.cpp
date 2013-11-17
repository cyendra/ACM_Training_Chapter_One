#include <iostream>
#include <cstring>

using namespace std;

int fib[]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
int SG[1010];
bool b[1010];

void getsg()
{
    int p;
    memset(SG,0,sizeof(SG));
    for (int i=1;i<=1000;i++)
    {
        memset(b,0,sizeof(b));
        for (int j=0;i-fib[j]>=0;j++)
        {
            b[ SG[ i-fib[j] ] ]=true;
        }
        p=0;
        while ( b[p] ) p++;
        SG[i]=p;
    }
}

int main()
{
    int x,y,z,ans;
    getsg();
    while (cin>>x>>y>>z)
    {
        if (x==0&&y==0&&z==0)
        {
            break;
        }
        ans=SG[x]^SG[y]^SG[z];
        if (ans!=0)
        {
            cout<<"Fibo"<<endl;
        }
        else
        {
            cout<<"Nacci"<<endl;
        }
    }
    return 0;
}
