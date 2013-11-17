#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    FILE *f=fopen("rand.out","w");
    scanf("%d",&n);
    fprintf(f,"%d\n1\n",n);
    for (int i=2;i<=n;i++)
    {
        int t;
        t=rand()%(i-1)+1;
        fprintf(f,"%d %d\n",i,t);
    }
    return 0;
}
