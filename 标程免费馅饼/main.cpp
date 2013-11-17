/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    FILE *f1;
    int n,x,T;
    f1=fopen("data.in","w");
    for (int i=0;i<10;i++)
    {
        n=rand()%11111;
        fprintf(f1,"%d\n",n);
        for (int i=0;i<n;i++)
        {
            x=rand()%11;
            T=rand()%11111;
            fprintf(f1,"%d %d\n",x,T);
        }
    }
    fprintf(f1,"0\n");
    fclose(f1);
    return 0;
}
*/
