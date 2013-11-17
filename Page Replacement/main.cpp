#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T;
int n,m;

queue<int>que;

int v[111111];

int idx;
int ans;
int get;

int main()
{
    cin>>T;
    while (T--)
    {
        memset(v,0,sizeof(v));
        while (!que.empty()) que.pop();
        ans=0;
        cin>>m>>n;
        idx=0;
        for (int lp=0; lp<n; lp++)
        {
            int x;
            cin>>x;
            if (v[x]>0) m++;
            else ans++;
            que.push(x);
            v[x]++;
            while (que.size()>m)
            {
                get=que.front();
                que.pop();
                v[get]--;
                if (v[get]>0)
                {
                    m--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


/*
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T;
int n,m;

queue<int>que[2];

bool v[111111];

int idx;
int ans;
int get;

int main()
{
    cin>>T;
    while (T--)
    {
        memset(v,0,sizeof(v));
        while (!que[0].empty()) que[0].pop();
        while (!que[1].empty()) que[1].pop();
        ans=0;
        cin>>m>>n;
        idx=0;
        for (int lp=0;lp<n;lp++)
        {
            int x;
            cin>>x;
            if (!v[x])
            {
                //cerr<<"que.push"<<endl;
                que[idx].push(x);
                //cerr<<"push="<<x<<endl;
                v[x]=true;
                ans++;
                //cerr<<"lp="<<lp<<" ans="<<ans<<endl;
                if (que[idx].size()>m)
                {
                    get=que[idx].front();
                    //cerr<<"size>m get="<<get<<endl;
                    que[idx].pop();
                    v[get]=false;
                }
            }
            else
            {
                //cerr<<"que.pop"<<endl;
                int l=idx;
                idx=(idx+1)%2;
                while ( !que[l].empty() )
                {
                    get=que[l].front();
                    if (get!=x)
                    {
                        que[idx].push(get);
                        //cerr<<"push="<<get<<" ";
                    }
                    que[l].pop();
                }
                que[idx].push(x);
                //cerr<<"push="<<x<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
