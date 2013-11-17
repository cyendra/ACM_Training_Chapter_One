#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MM=111111;

int next[MM],extand[MM];
char P[MM],T[MM];

void GetNext(const char *T)
{
    int len=strlen(T),a=0;
    next[0]=len;
    while(a<len-1 && T[a]==T[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2; k<len; k++)
    {
        int p=a+next[a]-1,L=next[k-a];
        if( (k-1)+L >= p)
        {
            int j = (p-k+1)>0 ? (p-k+1) : 0;
            while(k+j<len && T[k+j]==T[j]) j++;
            next[k]=j;
            a=k;
        }
        else
            next[k]=L;
    }
}
void GetExtand(const char *S,const char *T)
{
    GetNext(T);
    int slen=strlen(S),tlen=strlen(T),a=0;
    int MinLen = slen < tlen ? slen : tlen;
    while(a<MinLen && S[a]==T[a]) a++;
    extand[0]=a;
    a=0;
    for(int k=1; k<slen; k++)
    {
        int p=a+extand[a]-1, L=next[k-a];
        if( (k-1)+L >= p)
        {
            int j= (p-k+1) > 0 ? (p-k+1) : 0;
            while(k+j<slen && j<tlen && S[k+j]==T[j]) j++;
            extand[k]=j;
            a=k;
        }
        else
            extand[k]=L;
    }
}

int main()
{
    int lex;
    char cg[30];
    char eng[30];
    scanf("%d",&lex);
    while (lex--)
    {
        scanf("%s",cg);
        scanf("%s",T);
        for (int i=0; i<26; i++)
        {
            eng[cg[i]-'a']=i+'a';
        }
        int len=strlen(T);
        for (int i=0; i<len; i++)
        {
            P[i]=eng[T[i]-'a'];
        }
        //puts(T);
        //puts(P);
        GetExtand(T,P);
        int ret=len;
        for (int i=(len+1)/2;i<len;i++)
        {
            if (extand[i]+i>=len)
            {
                ret=i;
                break;
            }
        }
        for (int i=0;i<ret;i++) printf("%c",T[i]);
        for (int i=0;i<ret;i++) printf("%c",P[i]);
        puts("");
    }
    return 0;
}
