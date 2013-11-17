#include <iostream>
#include <cstring>
using namespace std;

int p;
int n;

int main()
{
    cin>>n;
    p=0;
    for (int i=1;i<=n-1;i++)
    {
        p=(p+i)%n;
        cout<<p+1<<" ";
    }
    cout<<endl;
    return 0;
}
