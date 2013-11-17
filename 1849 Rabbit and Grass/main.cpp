#include <iostream>

using namespace std;

int main()
{
    int m,ans;
    int a[1010];
    while (cin>>m)
    {
        if (m==0) break;
        for (int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        ans=a[0];
        for (int i=1;i<m;i++)
        {
            ans=ans^a[i];
        }
        if (ans!=0)
        {
            cout<<"Rabbit Win!"<<endl;
        }
        else
        {
            cout<<"Grass Win!"<<endl;
        }
    }
    return 0;
}
