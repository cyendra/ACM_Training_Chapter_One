#include <iostream>
#include <cstring>
using namespace std;

char str[1111];
int f[1111]={0};
int odd=0;

int main()
{
    int len;
    cin>>str;
    len=strlen(str);
    for (int i=0;i<len;i++)
    {
        f[str[i]-'a']++;
    }
    for (int i=0;i<26;i++)
    {
        if (f[i]&1) odd++;
    }
    if (odd==0)
    {
        cout<<"First"<<endl;
    }
    else if (odd==1)
    {
        cout<<"First"<<endl;
    }
    else if (odd%2==0)
    {
        cout<<"Second"<<endl;
    }
    else
    {
        cout<<"First"<<endl;
    }
    return 0;
}
