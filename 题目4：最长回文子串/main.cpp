//最长回文子串模板
//hdu3068，最长回文子串模板，Manacher算法，时间复杂度O(n)，相当快
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define M 200050
char str1[M],str[2*M];
int rad[M],nn,n;
void Manacher(int *rad,char *str,int n)
{
    int i;
    int mx = 0;
    int id;
    for(i=1;  i<n;  i++)
    {
        if( mx > i ) rad[i] = rad[2*id-i]<mx-i?rad[2*id-i]:mx-i;
        else rad[i] = 1;
        for(; str[i+rad[i]] == str[i-rad[i]]; rad[i]++)
            if( rad[i] + i > mx )
            {
                mx = rad[i] + i;
                id = i;
            }
    }
}
int main()
{
    int i,ans,Case=1;
    while(scanf("%s",str1)!=EOF)
    {
        nn=strlen(str1);
        n=2*nn+2;
        str[0]='$';
        for(i=0; i<=nn; i++)
        {
            str[2*i+1]='#';
            str[2*i+2]=str1[i];
        }
        Manacher(rad,str,n);
        ans=1;
        for(i=0; i<n; i++)
            ans=rad[i]>ans?rad[i]:ans;
        printf("%d\n",ans-1);
    }
    return 0;
}
