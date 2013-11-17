#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int f[1111111];

void getfail(char* P,int *f)
{
    int m=strlen(P);
    f[0]=f[1]=0;
    for (int i=1;i<m;i++)
    {
        int j=f[i];
        while (j&&P[i]!=P[j]) j=f[j];
        f[i+1]=(P[i]==P[j])?j+1:0;
    }
}

void find(char* T,char* P,int* f)
{
    int n=strlen(T),m=strlen(P);
    getfail(P,f);
    int j=0;
    for (int i=0;i<n;i++)
    {
        while (j&&P[j]!=T[i]) j=f[j];
        if (P[j]==T[i]) j++;
        if (j==m) printf("%d\n",i-m+1);
    }
}

int main()
{
    int n;
    char str[1111111];
    int cnt=0;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        cnt++;
        scanf("%s",str);
        getfail(str,f);
        printf("Test case #%d\n",cnt);
        for (int i=2;i<=n;i++)
        {
            if (f[i]>0&&i%(i-f[i])==0) printf("%d %d\n",i,i/(i-f[i]));
        }
        printf("\n");
    }
    return 0;
}
