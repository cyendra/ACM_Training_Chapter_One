#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=111;

vector<int>atk;
vector<int>def;
vector<int>str;
vector<int>::iterator it;
bool v[maxn];
int n,m;
int ans1,ans2;
int main()
{
    while (cin>>n>>m)
    {
        ans1=ans2=0;
        memset(v,0,sizeof(v));
        atk.clear();
        def.clear();
        str.clear();
        for (int i=0;i<n;i++)
        {
            char s[4];
            int d;
            cin>>s>>d;
            if (!strcmp(s,"ATK")) atk.push_back(d);
            if (!strcmp(s,"DEF")) def.push_back(d);
        }
        for (int i=0;i<m;i++)
        {
            int d;
            cin>>d;
            str.push_back(d);
        }
        sort(atk.begin(),atk.end());
        sort(def.begin(),def.end());
        sort(str.begin(),str.end());
        //直接攻击
        int p=0;
        bool flag=false;
        for (int i=0;i<def.size();i++)
        {
            while (p<str.size()&&str[p]<=def[i]) p++;
            if (p>=str.size())
            {
                flag=true;
                break;
            }
            v[p]=true;
            p++;
        }
        p=0;
        for (int i=0;i<atk.size();i++)
        {
            while (p<str.size()&&(v[p]||str[p]<atk[i])) p++;
            if (p>=str.size())
            {
                flag=true;
                break;
            }
            v[p]=true;
            ans1+=str[p]-atk[i];
            p++;
        }
        for (int i=0;i<str.size();i++)
        {
            if (!v[i]) ans1+=str[i];
        }
        if (flag) ans1=0;
        //OTK
        p=str.size()-1;
        for (int i=0;i<atk.size();i++)
        {
            if (p>=0&&str[p]>=atk[i])
            {
                ans2+=str[p]-atk[i];
                p--;
            }
            else
            {
                break;
            }
        }
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}










/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=111;

int n,m;

struct MIX{
    int d;
    int tp;
}mix[maxn];

bool cmp(MIX a,MIX b)
{
    return a.d<b.d;
}

int atk[maxn]= {0};
int def[maxn]= {0};
int str[maxn]= {0};
bool vmix[maxn]= {0};
int ak,df,sr;
int ans1,ans2;
int main()
{
    ak=df=sr=ans1=ans2=0;
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        char s[5];
        int t;
        cin>>s>>t;
        if (strcmp(s,"ATK")==0){atk[ak++]=t;mix[i].tp=1;}
        if (strcmp(s,"DEF")==0){def[df++]=t;mix[i].tp=2;}
        mix[i].d=t;
    }
    for (int i=0; i<m; i++)
    {
        int t;
        cin>>t;
        str[sr++]=t;
    }
    sort(atk,atk+ak);
    sort(def,def+df);
    sort(str,str+sr);
    sort(mix,mix+n,cmp);
    bool flag1=false;
    //for (int i=0;i<n;i++) cerr<<tp[i]<<endl;
    if (m>n) //直接攻击
    {
        int p1=0;
        int p2=0;
        for (int i=0;i<n;i++)
        {
            p1=i;
            while ((p2<sr)&&
                    ((mix[p1].tp==1&&str[p2]<mix[p1].d)||
                     (mix[p1].tp==2&&str[p2]<=mix[p1].d))) p2++;
            if (p2>=sr) flag1=true;
            //cerr<<tp[p1]<<"tp"<<endl;
            if (mix[p1].tp==1) ans1+=str[p2]-mix[p1].d;
            vmix[p2]=true;
            p2++;
            //cerr<<"ans="<<ans1<<endl;
        }
        for (int i=0;i<sr;i++)
        {
            if (!vmix[i]) ans1+=str[i];
            //cerr<<"ans="<<ans1<<endl;
        }
        if (flag1) ans1=0;
    }
    //不直接攻击
    //int p1=ak-1;
    //cerr<<ak<<"?"<<endl;
    for (int i=ak-1; i>=0; i--)
    {
        int p1=i;
        int p2=sr-1;
        ans2=0;
        while (p1>=0&&p2>=0&&str[p2]>=atk[p1])
        {
            ans2+=str[p2]-atk[p1];
            p2--;
            p1--;
        }
        //cerr<<"ans2="<<ans2<<endl;
        ans1=max(ans1,ans2);
    }
    //cerr<<ans1<<endl<<ans2<<endl;
    cout<<ans1<<endl;
    return 0;
}
*/
        /*
        int p1=0;
        for (int i=0; i<df; i++)
        {
            while (p1<sr&&str[p1]<=def[i]) p1++;
            if (p1>=sr)
            {
                flag1=true;
                break;
            }
            else
            {
                vstr[p1]=true;
            }
        }
        p1=0;
        if (!flag1)
            for (int i=0; i<ak; i++)
            {
                while ((p1<sr&&str[p1]<atk[i])||vstr[p1]) p1++;
                if (p1>=sr)
                {
                    flag1=true;
                    break;
                }
                else
                {
                    vstr[p1]=true;
                    ans1+=str[p1]-atk[i];
                    //cerr<<"ans1="<<ans1<<endl;
                }
            }
        for (int i=0; i<sr; i++)
        {
            if (!vstr[i]) ans1+=str[i];
            //cerr<<"ans1="<<ans1<<endl;
        }
        if (flag1) ans1=0;
        */
