#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char T[1111111];
char P[1111111];
int  f[1111111];


bool find()
{
    int n=strlen(T),m=strlen(P);
    f[0]=0;
    f[1]=0;
    for (int i=1; i<m; i++)
    {
        int j=f[i];
        while (j && P[i]!=P[j]) j=f[j];
        f[i+1]=(P[i]==P[j])?(j+1):(0);
    }

    int j=0;
    for (int i=0; i<n; i++)
    {
        while (j && P[j]!=T[i]) j=f[j];
        if (P[j]==T[i]) j++;
        if (j==m) return true;
    }
    return false;
}

int main()
{
    while (~scanf("%s%s",T,P))
    {
        memset(f,0,sizeof(f));
        int lenT=strlen(T);
        int lenP=strlen(P);
        if (lenT!=lenP)
        {
            printf("no\n");
        }
        else if (strcmp(P,T)==0)
        {
            printf("no\n");
        }
        else
        {
            for (int i=lenT; i<lenT*2; i++)
            {
                T[i]=T[i-lenT];
            }
            T[lenT*2]='\0';
            if (find())
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }

    }
    return 0;
}

/*
int next[1111110];
void get_next(char t[])
{
    int i,j;
    i=1;
    next[1]=0;
    j=0;
    while(i<strlen(t))
    {
        if(j==0||t[i-1]==t[j-1])
        {
            i++;
            j++;
            if(t[i-1]!=t[j-1])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else
            j=next[j];

    }
}
int kmp(char s[],char t[])
{
    get_next(t);
    int i,j;
    int lens,lent;
    i=1;
    j=1;
    while(i<=strlen(s)&&j<=strlen(t))
    {
        if(j==0||s[i-1]==t[j-1])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j>strlen(t)) return 1;
    else return 0;
}
*/

