/*版本一
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n;
int a[1000010];
int s[1000010];
int f[1000010];

int main()
{
    int max;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=a[i]+s[i-1];
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=n-m+i;j>=i;j--)
            {
                //f[j]=f[j-1]+a[j];
                for (int k=i-1;k<j;k++)
                {
                    if ( f[j]<f[k]+(s[j]-s[k]))
                    {
                        f[j]=f[k]+(s[j]-s[k]);
                    }
                }
            }
            for (int j=i+1;j<=n-m+i;j++)
            {
                if (f[j]<f[j-1])
                {
                    f[j]=f[j-1];
                }
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}
*/
/*版本二
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n;
int a[1000010];
int f[2][1000010];

int main()
{
    int max;
    int p,l;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        p=0;
        l=1;
        for (int i=1;i<=m;i++)
        {
            p^=1;
            l^=1;
            for (int j=i;j<=n-m+i;j++)
            {
                f[p][j]=f[p][j-1]+a[j];
                for (int k=i-1;k<j;k++)
                {
                    if ( f[p][j]<f[l][k]+a[j])
                    {
                        f[p][j]=f[l][k]+a[j];
                    }
                }
            }
        }
        max=-99999999;
        for (int i=m;i<=n;i++)
        {
            if (f[p][i]>max)
            {
                max=f[p][i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
*/

//版本三
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m,n;
int a[1000010];
int s[1000010];
int f[1000010];
int b[2][1000010];

int main()
{
    int ans,p,l;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        a[0]=0;
        s[0]=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            s[i]=a[i]+s[i-1];
        }
        p=1;
        for (int i=0;i<=n;i++)
        {
            b[p][i]=0;
        }
        for (int i=1; i<=m; i++)
        {
            p=1-p;
            for (int j=i; j<=n; j++)
            {
                if (i==j)
                {
                    f[j]=s[j];
                    b[p][j]=s[j];
                }
                else
                {
                    f[j]=max(f[j-1],b[1-p][j-1])+a[j];
                    b[p][j]=max(b[p][j-1],f[j]);
                }
            }
        }
        cout << b[p][n] << endl;
    }
    return 0;
}


/*版本四
#include<iostream>
#include<cstdio>
using namespace std;

const int N=1000000;//100万
int sum[N+1],f[N+1],b[2][N+1];

inline int max(int &a,int &b)
{
 return a<b?b:a;
}

//f[i][j]：前j个数分为i段，第j个数必须选；1：第j个数单独为1段；2：第j个数与前面的数连一块。f[i][j]=max(b[i-1][j-1],f[i][j-1])+a[j];
//b[i][j]：前j个数分为i段，第j个数可选可不选；1：选第j个数，2：不选第j个数。b[i][j]=max(b[i][j-1],f[i][j])
//f[i][j]=max(b[i-1][j-1],f[i][j-1])+a[j];
//b[i][j]=max(b[i][j-1],f[i][j])；
//f[i][i],b[i][i]容求，所以由b[i-1][j-1]->f[i][j]->b[i][j],只要知道b[0][j]，全部都能成功运行
void dp(int m,int n)
{
 int i,j,k,t=1;
 for(i=0;i<=n;i++) b[0][i]=0;

 for(i=1;i<=m;i++)
 {
 // for(j=i;j<=n;j++) b[t][j]=0;//每轮准备

  for(j=i;j<=n;j++)
  {
   if(i==j) b[t][j]=f[j]=sum[j];//分奇数次轮、偶数次轮
   else
   {
    f[j]=max(b[1-t][j-1],f[j-1])+sum[j]-sum[j-1];
    b[t][j]=max(b[t][j-1],f[j]);
   }

  }
  t=1-t;
 }

 cout<<b[m%2][n]<<endl;//奇次轮还是偶次轮

}

int main()
{
 int i,j,k,n,m;

 while(scanf("%d%d",&m,&n)!=-1)
 {
  sum[0]=0;
  for(i=1;i<=n;i++) {scanf("%d",&k); sum[i]=sum[i-1]+k;}
  dp(m,n);
 }

 return 0;
}
*/
