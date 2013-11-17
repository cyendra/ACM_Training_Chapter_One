#include <iostream>

using namespace std;

int phi(int n)
{
    int rea=n;
    for(int i=2; i*i<=n; i++)   //�����i*i<=n�������iС�ڵ��ڸ�����n
    {
        if(n%i==0)
        {
            rea=rea-rea/i;
            do
            {
                n/=i;
            }
            while(n%i==0);
        }
    }
    if(n>1)
    {
        rea=rea-rea/n;
    }
    return rea;
}


int main()
{
    int n;
    while (cin>>n)
    {
        cout<<phi(n)<<endl;
    }
    return 0;
}
