#include <iostream>

using namespace std;

int main()
{
    int n,u,d;
    int tm,now;
    while ( cin >> n >> u >> d )
    {
        if (n==0)
        {
            break;
        }
        tm=0;
        now=n-u;
        tm=(n-u)/(u-d);
        tm=tm*2;
        now=now-(n-u)%(u-d);
        while (now<n)
        {
            now=now+u;
            tm++;
            if (now<n)
            {
                now=now-d;
                tm++;
            }
        }
        cout <<tm<<endl;
    }
    return 0;
}
