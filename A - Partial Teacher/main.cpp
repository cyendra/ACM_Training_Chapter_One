#include<iostream>
using namespace std;

char s[1001];
int n;

int main()
{
    cin>>n;
    cin>>s;
	for(int i=0;i<n;++i)
	{
		int l,r,ll,rr;
		l=i-1;
		r=i;
		ll=rr=1;
		while(s[l]!='L'&&l>=0)
		{
		    if (s[l]=='R') ll++;
		    l--;
		}
		while(s[r]!='R'&&r<n)
		{
		    if (s[r]=='L') rr++;
		    r++;
		}
		if (ll>rr)
		{
		    cout<<ll<<" ";
		}
		else
		{
		    cout<<rr<<" ";
		}
	}
	return 0;
}
