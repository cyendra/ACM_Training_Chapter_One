#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    char last;
    int tm;
    string str;
    cin >> n;
    for (int loop=0;loop<n;loop++)
    {
        cin >> str;
        tm=1;
        last='0';
        for (int i=0;i<str.length();i++)
        {
            if (last==str[i])
            {
                tm++;
            }
            else if (last!='0')
            {
                if (tm==1)
                {
                    cout << last;
                }
                else if (tm>1)
                {
                    cout << tm << last;
                }
                tm=1;
            }
            last=str[i];
        }
        if ((tm!=0)&&(last!='0') )
        {
            if (tm==1)
            {
                cout << last;
            }
            else
            {
                cout << tm << last;
            }
        }
        cout << endl;
    }
    return 0;
}
