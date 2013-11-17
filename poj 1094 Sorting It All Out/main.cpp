#include <iostream>
#include <cstring>

using namespace std;

int a[30][30];
int d[30];
int put[30];

int main()
{
    int n,m;
    char c1,c2,tc;
    int e,v,t;
    int zero,p;
    bool flag0,flag2;
    int ans;
    int bad;
    while (cin>>n>>m)
    {
        if (n==0&&m==0) break;
        memset(a,0,sizeof(a));
        bad=-1;
        ans=-1;
        for (int sp=1; sp<=m; sp++)
        {
            cin>>c1>>tc>>c2;
            e=c1-'A';
            v=c2-'A';
            a[e][v]=1;
            //读入边

            memset(d,0,sizeof(d));
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (a[i][j]>0) d[j]++;
                }
            }
            //计算入度

            //cout<<sp<<endl;

            flag0=flag2=false;//初始化标记
            if ( ans==-1&&flag0==false )//若无正确解则进行拓扑排序
            for (int loop=0; loop<n; loop++)
            {
                zero=0;
                p=0;
                for (int i=0; i<n; i++)
                {
                    //cout<<d[i]<<" ";
                    if (d[i]==0)
                    {
                        zero++;
                        p=i;
                    }
                }
                //cout<<endl;
                if (zero==0)
                {
                    flag0=true;
                    if (bad==-1) bad=sp;
                    //cout<<bad<<endl;
                    break;
                }
                else if (zero>1)
                {
                    flag2=true;
                    for (int j=0; j<n; j++)
                    {
                        if (a[p][j]>0)
                        {
                            d[j]--;
                        }
                    }
                    d[p]=-1;
                }
                else if (zero==1)
                {
                    put[loop]=p;
                    for (int j=0; j<n; j++)
                    {
                        if (a[p][j]>0)
                        {
                            d[j]--;
                        }
                    }
                    d[p]=-1;
                }
            }
            //拓扑排序
            if ((!flag0)&&(!flag2)&&(ans==-1)) ans=sp;//若未出错并且无最优解则记录最优解
        }
        //读入并处理完毕

        if (ans==-1 && flag0==true)
        {
            cout<<"Inconsistency found after "<<bad<<" relations."<<endl;
        }
        else if (ans==-1 && flag2==true)
        {
            cout<<"Sorted sequence cannot be determined."<<endl;
        }
        else
        {
            cout<<"Sorted sequence determined after "<<ans<<" relations: ";
            for (int i=0; i<n; i++)
            {
                cout<<(char)(put[i]+'A');
            }
            cout<<"."<<endl;
        }
    }
    return 0;
}
