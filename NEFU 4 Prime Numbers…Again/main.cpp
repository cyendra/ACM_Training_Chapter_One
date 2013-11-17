#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool prm[111111]= {0};
int a[11111]= {0};
long long sum[11111]= {0};
int n;
int cnt;

int main()
{
    int T;
    cnt=0;
    prm[0]=true;
    prm[1]=true;
    for (int i=2; i<=100000; i++)
    {
        if (!prm[i])
        {
            a[++cnt]=i;
            for (int j=i+i; j<=100000; j+=i)
            {
                prm[j]=true;
            }
        }
    }
    for (int i=1; i<=cnt; i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=1; i<=cnt; i++)
        {
            int low=0;
            int high=i-1;
            int mid;
            while(low <= high)
            {
                mid = (low + high)/2;
                if (sum[mid] > sum[i]-n)
                    high = mid - 1;
                else if (sum[mid] < sum[i]-n)
                    low = mid + 1;
                else break;
            }
            if (sum[mid]==sum[i]-n) ans++;
            /*
            for(int j=0; j<i; j++)
            {
                if(sum[i]-n==sum[j])
                    ans++;
            }
           */
        }
        printf("%d\n",ans);
    }
    return 0;
}

