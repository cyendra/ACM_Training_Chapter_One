/*hdoj_1150匈牙利算法  月下版 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool mark1[100],mark2[100];
int list[100];
int n,m,edge,num;
vector<vector<int> > v;  //动态数组貌似是二维
bool dfs(int to)         //貌似是深搜
{
    register int i,point,s = list[to];
    for(i=0; i<v[s].size(); i++)
    {
        point = v[s][i];
        if(!mark2[point]) continue;
        mark2[point] = false;
        if(list[point]==-1 || dfs(point))
        {
            list[point] = s;
            return true;

        }
    }
    return false;
}

void Solve()
{
    int i,j,point;
    bool flog = false;
    memset(mark1,true,sizeof(mark1));
    memset(list,-1,sizeof(list));
    num=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<v[i].size(); j++) if(list[v[i][j]] == -1)
            {
                mark1[i] = false;
                list[v[i][j]] = i;
                num++;
                if(i==0) flog = true;
                break;

            }
    }
    for(i=0; i<n; i++)
    {
        if(mark1[i])
        {
            if(!v[i].empty())
            {
                memset(mark2,true,sizeof(mark2));
                for(j=0; j<v[i].size(); j++)
                {
                    point = v[i][j];
                    if(!mark2[point]) continue;
                    mark2[point] = false;
                    if(list[point] == -1 || dfs(point))
                    {
                        list[point] = i;
                        num++;
                        break;
                    }
                }
            }
            mark1[i] = false;
        }
    }
    if(flog || list[0] != -1) cout << num-1 << endl;
    else cout << num << endl;
}

int main()
{
    int i,j,s,d;
    while(cin>>n)
    {
        if(n == 0)break;
        v.clear();          //清空数组v
        v.resize(n);        //啥啊这是
        cin >> m >> edge;
        for(i=0; i<edge; i++)
        {
            cin >> j >> s >> d;
            v[s].push_back(d);
        }
        Solve();
    }
    return 0;
}
