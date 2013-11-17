#include <cstring>
#include <iostream>

using namespace std;

bool v[11111];
char s[111];
int n,ans;
int x,y,t;

int main()
{
    memset(v,0,sizeof(v));
    ans=0;
    bool ok;
    cin>>n;
    while (n--)
    {
        cin>>x;
        cin>>y;
        t=x*100+(y%10)*10+y/10;
        if (!v[t])
        {
            ans++;
            for (int i=0; i<4; i++)
            {
                v[t]=true;
                t=(t%1000)*10+t/1000;
            }
        }
        if (n!=0) cin>>s;
    }
    cout<<ans<<endl;
}

/*
#include <stdio.h>
int check[6667];
int main()
{
	int n,ret=0;
	scanf("%d",&n);
	for (int q=0;q<n;++q)
	{
		if (q) { char tmp[256]; scanf("%s",tmp); }
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		int k = a * 100 + (b%10)*10 + b/10;
		if (check[k]) continue;
		ret++;
		for (int w=0;w<4;++w)
		{
			check[k] = 1;
			k = (k%1000) * 10 + k/1000;
		}
	}
	printf("%d\n",ret);
	return 0;
}
*/
