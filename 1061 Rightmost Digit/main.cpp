#include <iostream>

using namespace std;

int main()
{
    int a[30];
    int L,n,ans;
    for (int loop=1;loop<=25;loop++)
    {
        n=loop;
        ans=1;
        for (int i=0;i<n;i++)
        {
            ans=(ans*n)%10;
        }
        a[loop-1]=ans;
    }
    cin >>L;
    for (int loop=0;loop<L;loop++)
    {
        cin>>n;
        n=(n-1)%20;
        cout << a[n]<<endl;
    }
    return 0;
}
