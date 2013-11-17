#include <iostream>

using namespace std;

int main()
{
    int al,ar;
    int bl,br;
    cin>>al>>ar;
    cin>>bl>>br;
    bool ok=false;
    if (al<=br+1&&al*2+3>br)
    {
        ok=true;
    }
    if (ar<=bl+1&&ar*2+3>bl)
    {
        ok=true;
    }
    if (ok)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
