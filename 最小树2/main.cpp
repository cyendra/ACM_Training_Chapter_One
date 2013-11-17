#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,m,n,min,num,sum;
    char c1,c2;
    bool v[26]={false};
    int a[26][26];
    bool ok=false;
    //printf(" ‰»În,m:\n");
    scanf("%d%d",&n,&m);
    getchar();
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    {
        a[i][j]=-1;
    }
    for (int i=0;i<m;i++)
    {
        //printf(" ‰»Îc1,c2,t:\n");
        c1=getchar();
        getchar();
        c2=getchar();
        getchar();
        scanf("%d",&t);
        getchar();
        a[c1-'A'][c2-'A']=t;
        a[c2-'A'][c1-'A']=t;
    }
    v[0]=true;
    sum=0;
    for (int k=0;k<=n;k++)
    {
        ok=true;
        min=-1;
        for (int i=0;i<n;i++)
        {if (v[i]==true)

            for (int j=0;j<n;j++)
            if ((v[j]==false)and(a[i][j]!=-1))
            if ((min==-1)or(a[i][j]<min))
            {
                min=a[i][j];
                num=j;
                ok=false;
                //printf("i=%d,j=%d",i,j);getchar();
            }
        }
        if (min!=-1)
        {
            sum+=min;
        }
        v[num]=true;
        //printf("sum=%d,num=%d",sum,num);getchar();
    }
    if (ok==true)
    {
        printf("%d",sum);
    }
    else
    {
        printf("-1");
    }

    return 0;
}
