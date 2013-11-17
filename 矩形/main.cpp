#include <iostream>

using namespace std;

typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}RET;

RET a[500];

int main()
{
    int n,ans;
    bool cover;
    while(cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        }
        ans=0;
        for (int i=0;i<n;i++)
        {
            cover=false;
            for (int j=0;j<n;j++)
            {
                if ( i!=j )
                {
                    if ( a[j].x1<=a[i].x1 && a[j].y1<=a[i].y1 && a[j].x2>=a[i].x2 && a[j].y2>=a[i].y2 )
                    {
                        cover=true;
                        break;
                    }
                }
            }
            if ( cover ) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
