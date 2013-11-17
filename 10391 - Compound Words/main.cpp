#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int maxn=32111;
const int maxm=11000019;

int head[maxm];
int next[maxm];
char word[maxn][30];

int hash(char *p,int prime=10000019)
{
    unsigned int h=0,g;
    for (;*p;++p){
        h=(h<<4)+*p;
        if (g=h&0xf0000000){
            h=h^(g>>24);
            h=h^g;
        }
    }
    return h%prime;
}

void addhash(int s)
{
    int h=hash(word[s]);
    next[s]=head[h];
    head[h]=s;
}

bool searchstr(char* str)
{
    int h=hash(str);
    for (int i=head[h];i!=-1;i=next[i])
    {
        if (strcmp(str,word[i])==0) return true;
    }
    return false;
}

int main()
{
    char str[30];
    int n=1;
    memset(head,-1,sizeof(head));
    while (gets(word[n]))
    {
        addhash(n);
        n++;
    }
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<strlen(word[i]);j++)
        {
            strcpy(str,word[i]);
            str[j]='\0';
            if (searchstr(str)&&searchstr(word[i]+j))
            {
                puts(word[i]);
                break;
            }
        }
    }
    return 0;
}

