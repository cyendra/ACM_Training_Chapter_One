#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T,n,x,y,ans,tmp;
    int a[200];
    cin>>T;
    for (int loop=1;loop<=T;loop++)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            cin >> x >> y;
            x=(x-1)/2;
            y=(y-1)/2;
            if (x>y)
            {
                tmp=x;
                x=y;
                y=tmp;
            }
            for (int j=x;j<=y;j++)
            {
                a[j]++;
            }
        }
        ans=0;
        for (int i=0;i<200;i++)
        {
            if (a[i]>ans)
            {
                ans=a[i];
            }
        }
        cout << ans*10 << endl;
    }
    return 0;
}
