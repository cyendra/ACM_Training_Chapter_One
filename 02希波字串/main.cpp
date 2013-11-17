#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int f[30];
    char str[150];
    int max;
    while (cin >> str)
    {
        memset(f,0,sizeof(f));
        for (int i=0;i<strlen(str);i++)
        {
            f[str[i]-'a']++;
        }
        max=0;
        for (int i=0;i<7;i++)
        {
            if (f[i]>max)
            {
                max=f[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
