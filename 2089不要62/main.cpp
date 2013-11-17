#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a[7];
    int *ans=new int[1000000];
    int n,m;
    bool ok;
    int sum;
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    ans[0]=1;
    a[0]=1;
    for (int loop=1;loop<1000000;loop++)
    {
        ok=true;
        for (int i=5;i>=0;i--)
        {
            if (a[i]==4)
            {
                ok=false;
            }
        }
        for (int i=5;i>=1;i--)
        {
            if ((a[i]==6)&&(a[i-1]==2))
            {
                ok=false;
            }
        }
        a[0]++;
        for (int i=0;i<=5;i++)
        {
            if (a[i]>=10)
            {
                a[i+1]++;
                a[i]=a[i]-10;
            }
        }

        if (ok==true)
        {
            ans[loop]=ans[loop-1]+1;
            //printf("%d",loop);getchar();
        }
        else
        {
            ans[loop]=ans[loop-1];
        }
    }
    while (scanf("%d%d",&n,&m))
    {
        if ((m==0)&&(n==0))
        {
            break;
        }

        if (n==0)
        {
            sum=ans[m];
        }
        else
        {
            sum=ans[m]-ans[n-1];
        }
        printf("%d\n",sum);
    }
    return 0;
}
