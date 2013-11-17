#include <iostream>
using namespace std;

bool v[100001]={0};

int n;

int main()
{
    v[0]=true;
    v[1]=true;
    for (int i=2;i<=100000;i++)
    {
        if (!v[i])
        {
            for (int j=i+i;j<=100000;j+=i)
            {
                v[j]=true;
            }
        }
    }
    while (cin>>n)
    {
        if (!v[n])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
