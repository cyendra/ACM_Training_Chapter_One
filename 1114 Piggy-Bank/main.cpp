#include <iostream>
#define MAX 999999
using namespace std;

int p[511]={0};
int w[511]={0};
int f[11001]={0};

int main()
{
    int T;
    int E,F,m,tmp,lp;
    int n;
    cin>>T;
    for (int loop=0;loop<T;loop++)
    {
        cin >> E >> F;
        cin >> n;
        m=F-E;

        for (int i=1;i<=n;i++)
        {
            cin >> p[i] >> w[i];
        }

        for (int i=1;i<=m;i++)
        {
            f[i]=MAX;
        }
        f[0]=0;

        for (int i=1;i<=n;i++)
        {
            for (int j=w[i];j<=m;j++)
            {
                if ( f[j]>f[j-w[i]]+p[i])
                {
                    f[j]=f[j-w[i]]+p[i];
                }
            }
        }
        if ( f[m]!=MAX )
        {
            cout << "The minimum amount of money in the piggy-bank is "<<f[m]<<"."<<endl;
        }
        else
        {
            cout <<"This is impossible."<<endl;
        }
    }
    return 0;
}
