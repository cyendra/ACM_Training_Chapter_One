#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char * p;
    char a[1001],b[1001];
    while (gets(a),gets(b))
    {
        int sum=0;
        while (strstr(a,b)!=NULL)
        {
            sum++;
            p=strstr(a,b);
            p[0]=' ';
        }
        printf("%d\n",sum);
    }
    return 0;
}
