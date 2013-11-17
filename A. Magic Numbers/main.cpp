#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c;
int n,num;
bool flag;

int main()
{
    flag=true;
    num=0;
    n=0;
    while (cin>>c)
    {
        if (n==0&&c!='1')
        {
            flag=false;
            break;
        }
        if (c!='1'&&c!='4')
        {
            flag=false;
            break;
        }
        if (c=='4') num++;
        else num=0;
        if (num>2)
        {
            flag=false;
            break;
        }
        n++;
    }
    if (flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
