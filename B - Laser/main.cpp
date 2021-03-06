#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,X1,Y1,X2,Y2;
        scanf("%d%d%d%d%d%d",&n,&m,&X1,&Y1,&X2,&Y2);
        int d1 = abs(X1-X2);
        int d2 = abs(Y1-Y2);
        long long s = (long long)max((n-2*d1),0)*max((m-2*d2),0);
        long long ret = (long long)n*m-((long long)2*(n-d1)*(m-d2)-s);
        printf("%I64d\n",ret);
    }

    return 0;
}
/*

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,m,X1,Y1,X2,Y2;
        scanf("%d%d%d%d%d%d",&n,&m,&X1,&Y1,&X2,&Y2);
        int d1 = abs(X1-X2);
        int d2 = abs(Y1-Y2);
        LL s = (LL)max((n-2*d1),0)*max((m-2*d2),0);
        LL ret = (LL)n*m-(2LL*(n-d1)*(m-d2)-s);
        printf("%I64d\n",ret);
    }

    return 0;
}

*/
