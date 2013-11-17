#include <iostream>

using namespace std;

bool v[1000001]={0};
int a[1001];
int p;

int main()
{
    int n;
    p=0;
    v[0]=true;
    v[1]=true;
    for (int i=2;i<=100000;i++)
    {
        if (!v[i])
        {
            if (i>=3&&p<=1000&&(i-3)%4==0)
            {
                p++;
                a[p]=i;
            }
            for (int j=i+i;j<=100000;j+=i)
            {
                v[j]=true;
            }
        }
    }
    while (cin>>n)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
