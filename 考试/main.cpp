#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,k;
int a[111111];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int cnt=0;
    while (cin>>n>>m>>k)
    {
        cnt++;
        int num=0;
        for (int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[num++];
            }
        }
        sort(a,a+num,cmp);
        cout<<"Scenario #"<<cnt<<endl;
        cout<<a[k-1]<<endl<<endl;
    }
    return 0;
}
