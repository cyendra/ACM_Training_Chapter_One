#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int a[111111];
int n;
bool vprm[111111]= {0};
int prm[11111];
int cnt;

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    vprm[0]=true;
    vprm[1]=true;
    cnt=0;
    for (int i=3;i<=n;i++)
    {
        if (n%i==0)
        {
            prm[cnt++]=i;
        }
    }

    /*
    for (int i=2; i<=n; i++)
    {
        if (!vprm[i])
        {
            prm[cnt++]=i;
            for (int j=i+i; j<=n; j+=i)
            {
                vprm[j]=true;
            }
        }
    }
    */
    //for (int i=0; i<cnt; i++) printf("%d\n",prm[i]);
    bool ok=false;
    for (int k=0; k<cnt; k++)
    {
        if (n%prm[k]==0)
        {
            int bg_ed=n/prm[k];
            for (int bg=1; bg<=bg_ed; bg++)
            {
                ok=true;
                for (int i=bg;i<=n;i+=bg_ed)
                {
                    if (a[i]==0)
                    {
                        ok=false;
                        break;
                    }
                }
                if (ok)
                {
                    break;
                }
            }
        }
        if (ok) break;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
