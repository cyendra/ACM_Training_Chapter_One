#include <iostream>

using namespace std;

int main()
{
    string stra,strb;
    while (cin>>stra)
    {
        cin>>strb;
        if (stra.length()>strb.length())
        {
            cout<<1<<endl;
        }
        else if (stra.length()<strb.length())
        {
            cout<<-1<<endl;
        }
        else
        {
            if (stra>strb)
            {
                cout<<1<<endl;
            }
            else if (stra<strb)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
