#include <iostream>
#include <cstring>

using namespace std;

char s[111111];

int main()
{
    bool ok=false;
    cin.getline(s,10000);
    int len=strlen(s);
    //cout<<len<<endl;
    for (int i=len-1;i>=0;i--)
    {
        if ( (s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z') )
        {
            char c=s[i];
            switch (c)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    ok=true;
                    break;
            }
            break;
        }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
