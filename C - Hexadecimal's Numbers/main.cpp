#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int ans;
int tmp;
bool ok;
int len;
int bit[1000];

int main()
{

    while (cin >> n)
    {
        ans=0;
        len=0;
        memset(bit,0,sizeof(bit));
        ok=true;
        for (int i=0; ok; i++)
        {
            bit[0]++;
            for ( int k=0;k<=len;k++ )
            {
                if ( bit[k]>1 )
                {
                    bit[k+1]+=1;
                    bit[k]=0;
                }
            }
            if ( bit[len+1]>0 )
            {
                len++;
            }
            tmp=0;
            for (int j=len; j>=0; j--)
            {
                tmp=tmp*10+bit[j];
            }
            //cout << tmp << endl;
            if ( tmp>n )
            {
                ans=i;
                ok=false;
                break;
            }
        }
        cout << ans << endl ;
    }
    return 0;
}
