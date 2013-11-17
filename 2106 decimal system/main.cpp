#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long int n;
    long int d;
    char str[1001];
    long int ans,num;
    while (scanf("%ld",&n)!=EOF)
    {
        ans=0;
        for (int loop=0;loop<n;loop++)
        {
            scanf("%s",str);
            sscanf(str,"%ld(%ld)",&num,&d);
            //printf("%d %d",num,d);getchar();
            for (int i=0;num!=0;i++)
            {
                ans+=(num%10)*(long int)(pow(d,i));
                num=num/10;
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
