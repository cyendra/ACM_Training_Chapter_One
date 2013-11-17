#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

char str[1111111];

int a[11];
int b[11];
int c[11];
int FFF(){
    for (int i=9;i>=1;i--){
        for (int j=1;j<=9;j++){
            if (a[j]>0&&b[(i-j+10)%10]>0&&(i-j+10)%10!=0){
                a[j]--;
                b[(i-j+10)%10]--;
                c[i]++;
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%s",str);
        n=strlen(str);
        for (int i=0;i<n;i++) a[str[i]-'0']++;
        scanf("%s",str);
        for (int i=0;i<n;i++) b[str[i]-'0']++;
        int fst=FFF();
        for (int i=9;i>=0;i--){
            for (int j=0;j<=9;j++){
                while (a[j]>0&&b[(i-j+10)%10]>0){
                    //cerr<<a[j]<<"----"<<b[(i-j+10)%10]<<endl;
                    a[j]--;
                    b[(i-j+10)%10]--;
                    c[i]++;
                }
            }
        }
        //cerr<<"---------wtf"<<endl;
        printf("Case #%d: ",cas);
        if (fst==-1){
            printf("0\n");
            continue;
        }
        printf("%d",fst);
        c[fst]--;
        for (int i=9;i>=0;i--){
            while (c[i]>0){
                c[i]--;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6;
int sum[3][15];
char a[maxn+10], b[maxn+10];

int main()
{
    int t, ca = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        memset(sum,0,sizeof(sum));
        int i,j;
        int l = strlen(a);
        for(i=0; i<l; i++)
            sum[0][a[i]-'0']++;
        for(i=0; i<l; i++)
            sum[1][b[i]-'0']++;
        int x=0,y=0,max=0;
        for(i=1; i<=9; i++)
            for(j=1; j<=9; j++)
            {
                if(sum[0][i] >0 && sum[1][j]>0 && (i+j)%10>max)
                {
                    max = (i+j)%10;
                    x = i;
                    y = j;
                }
            }
        if(max == 0)
        {
            printf("Case #%d: 0\n",++ca);
            continue;
        }
        sum[0][x]--;
        sum[1][y]--;
        for(i=9; i>=0; i--)
            for(j=0; j<=9; j++)
            {
                if(j<=i)
                {
                    while(sum[0][j]>0 && sum[1][i-j]>0 )
                    {
                        sum[2][i] ++;
                        sum[0][j]--;
                        sum[1][i-j]--;
                    }
                }
                while(sum[0][j]>0 && sum[1][i+10-j]>0)
                {
                    sum[2][i] ++;
                    sum[0][j]--;
                    sum[1][i+10-j]--;
                }
            }
        printf("Case #%d: %d",++ca,max);
        for(i=9; i>=0; i--)
        {
            while(sum[2][i]>0)
            {
                printf("%d",i);
                sum[2][i]--;
            }
        }
        printf("\n");
    }
    return 0;
}

*/
