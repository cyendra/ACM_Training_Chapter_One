
#include <cstring>
#include<fstream>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int d[4];
int p;
int a,b;

int main()
{
    cin>>p;
    memset(d,0,sizeof(d));
    d[p]=1;
    for (int i=1; i<=3; i++)
    {
        cin>>a>>b;
        swap( d[a] , d[b] );
    }
    for (int i=1; i<=3; i++)
    {
        if (d[i]==1)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
