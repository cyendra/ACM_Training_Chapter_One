#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b;
    bool ok;
    while (scanf("%d%d",&a,&b))
    {
        if ((a==0)&&(b==0))
        {
            break;
        }
        a=a*100;
        ok=false;
        for (int i=0;i<=99;i++)
        {
            if ( ( (a+i) % b )==0 )
            {
                if (ok==true)
                {
                    printf(" ");
                }
                else
                {
                    ok=true;
                }
                printf("%02d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
