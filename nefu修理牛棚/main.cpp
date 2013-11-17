#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m,s,c;
int d[300];
int a[300];
int k[300];
int l;
int len;
int bg,ed;

int main()
{
    while (cin>>m>>s>>c)
    {
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        for (int i=1;i<=c;i++)
        {
            cin>>a[i];
            d[ a[i] ]++;
        }
        sort(a+1,a+c+1);
        bg=a[1];
        ed=a[c];
        len=a[c]-a[1]+1;

        l=0;
        int sum=0;
        bool flag=true;
        d[ed+1]=1;
        for (int i=bg;i<=ed+1;i++)
        {
            if (d[i]==0)
            {
                sum++;
            }
            else if ( d[i]!=0&&sum!=0 )
            {
                k[l++]=sum;
                sum=0;
            }
        }
        sort(k,k+l);
        for (int i=1;i<=m-1;i++)
        {
            if (l-i<0) break;
            len-=k[l-i];
        }
        cout<<len<<endl;
    }
    return 0;
}
