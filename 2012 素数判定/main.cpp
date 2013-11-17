#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    bool check;
    int x,y,ans,t;
    bool prime[100000]={false};
    prime[0]=true;
    prime[1]=true;
    for (int i=2;i<=100000;i++)
    {
        if (prime[i]==true){continue;}
        t=i+i;
        while (t<=100000)
        {
           prime[t]=true;
           t=t+i;
        }
    }
/*
    for (int i=2;i<=100000;i++)
    {
        if (prime[i]==false)
        {
            printf("%d ",i);
            getchar();
        }
    }
*/
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if (x==0&&y==0)
        {
            break;
        }
        check=true;
        for (int i=x;i<=y;i++)
        {
            ans=i*i+i+41;
            if (prime[ans]==true)
            {
                check=false;
                break;
            }
        }
        if (check==true)
        {
            printf("OK\n");
        }
        else
        {
            printf("Sorry\n");
        }
    }
    return 0;
}
