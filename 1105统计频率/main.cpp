#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    char str[50];
    int s=0;
    int n;
    map<string,int> ct;
    map<string,int>::iterator p;//传说中的迭代器
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",str);
        ct[str]++;
        s++;
    }
    double ans;
    for (p=ct.begin();p!=ct.end();p++)
    {
        ans=100*((double)p->second/(double)s);
        cout << p->first;
        printf(" %0.2f\n",ans);

    }
    return 0;
}
