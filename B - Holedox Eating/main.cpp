#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int OO=1e9;

map<int,int>mp;
map<int,int>::iterator it,itr,itl;
map<int,int>::iterator p;
int main()
{
    //freopen("input.txt","r",stdin);
    int T,len,m,tp,x;
    int dir;
    int ans;
    int cas=1;
    int ke;
    scanf("%d",&T);
    while (T--)
    {
        ans=0;
        ke=0;
        mp.clear();
        scanf("%d%d",&len,&m);
        dir=1;
        mp[OO]=1;
        mp[-OO]=1;
        mp[0]=0;
        p=mp.find(0);
        while (m--)
        {
            scanf("%d",&tp);
            if (tp==0)
            {
                scanf("%d",&x);
                mp[x]++;
                ke++;
                continue;
            }
            if (ke==0) continue;
            ke--;
            itl=itr=it=p;
            itl--;
            itr++;
            if (p->second>0)
            {
                p->second--;
                continue;
            }
            else if ( p->first - itl->first < itr->first - p->first &&
                      itl->first!=OO &&
                      itl->first!=-OO )
            {
                ans+=p->first - itl->first;
                p=itl;
                p->second--;
                dir=-1;
            }
            else if ( p->first - itl->first > itr->first - p->first &&
                      itr->first!=OO &&
                      itr->first!=-OO )
            {
                ans+=itr->first - p->first;
                p=itr;
                p->second--;
                dir=1;
            }
            else if ( p->first - itl->first == itr->first - p->first &&
                      itl->first!=OO &&
                      itl->first!=-OO &&
                      itr->first!=OO &&
                      itr->first!=-OO )
            {
                if (dir==1)
                {
                    ans+=itr->first - p->first;
                    p=itr;
                    p->second--;
                }
                else if (dir==-1)
                {
                    ans+=p->first - itl->first;
                    p=itl;
                    p->second--;
                }
            }
            if (it->second==0)
            {
                mp.erase(it);
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
