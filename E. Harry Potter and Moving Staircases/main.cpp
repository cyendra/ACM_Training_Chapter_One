#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define max_int       INT_MAX / 2
#define max_long      0xFFFFFFFFFFFFFFFLL / 2
#define two(a)        (1 << (a))
#define eps           1e-6
#define FF(i, a, b)   for (int i = (a); i <= (b); i++)
#define FFD(i, a, b)  for (int i = (a); i >= (b); i--)

/**********************************************
*       定义结构体Edge
**********************************************/

struct Edge//边的结构体
{
    int u, v;//顶点
    bool changed;
    Edge() {}
    Edge(int u, int v) : u(u), v(v), changed(false) {}
};

int n, m;
vector <Edge > edges;//储存边的数组
vector <int > edgeList[100010];//储存点与边对应关系的数组

/**********************************************
*       增加一条边的函数
**********************************************/

void AddEdge(int u, int v)
{
    int k = edges.size();
    edgeList[u].push_back(k);//增加与点u连接的边k
    edgeList[v].push_back(k);
    edges.push_back(Edge(u, v));
}

/**********************************************
*       集合结构体的定义
*       记录集合的信息
*       重载<操作符
*       在构造函数中初始化集合
**********************************************/

struct Component
{
    int root;//根节点
    int numEdges;//边数
    int numV;//点数
    int extraEdge;//特殊的边(作用暂时不明)

    Component()//构造函数，初始化集合
    {
        root = numEdges = numV = 0;
        extraEdge = -1;
    }

    bool operator <(const Component & x) const
    {
        if (numEdges - numV == x.numEdges - x.numV) return numEdges > x.numEdges;
        else return numEdges - numV > x.numEdges - x.numV;
    }
};

/**********************************************
*       定义各种变量与数组
**********************************************/

int numComps, comp[100010];
vector <Component > components;

vector <vector <int > > moveSteps;
vector <vector <int > > moveEdges;
bool vis[100010];
int startComp, nextComp;

/**********************************************
*       深度优先搜索
*       寻找与点u相连的点并进行处理
*       u为当前节点的编号
*       father为入边的编号
**********************************************/

void dfs(int u, int father)
{
    comp[u] = numComps;//将点u标记为集合numComps
    int numChild = 0;//子节点数
    for (int i = 0; i < edgeList[u].size(); i++)//遍历与u相连的所有边
    {
        int e = edgeList[u][i];//与点u相连的第i条边的编号为e
        if (e == father) continue;//若e与入边相同则跳过此边
        int v = (edges[e].u == u) ? edges[e].v : edges[e].u;//v为边的另一个顶点
        if (comp[v] == -1)//若点v未做标记
        {
            dfs(v, e);//dfs染色
            numChild += 1;//子节点数加1
        }
        else components.back().extraEdge = e;
    }
    if (numChild == 0 && father != -1 && components.back().extraEdge == -1)
    {
        if (edges[father].v != u) swap(edges[father].u, edges[father].v);
        components.back().extraEdge = father;
    }
}

/**********************************************
*       寻找路径
**********************************************/

void travel(int u, int father)
{
    if (vis[u]) return;//若点u已访问过则返回
    vis[u] = true;//标记点u为已访问
    if (father == -1) moveSteps.push_back(vector <int >());//若点u为起点则添加一个新的移动路径到数组中
    moveSteps.back().push_back(u);//将点u加入当前到路径中
    for (int i = 0; i < edgeList[u].size(); i++)//遍历与u相连的所有边
    {
        int e = edgeList[u][i];//与点u相连的第i条边的编号为e
        if (e == father || edges[e].changed) continue;//若e为入边或已经改变过则跳过此边
        int v = (edges[e].u == u) ? edges[e].v : edges[e].u;//v为边的另一个顶点
        if (vis[v] == 0)
        {
            travel(v, e);
            moveSteps.back().push_back(u);
        }
        if (edges[e].changed == 0 && nextComp < components.size())
        {
            edges[e].changed = 1;
            int w = components[nextComp].root;
            vector <int > tmp;
            tmp.push_back(e + 1);
            tmp.push_back(u);
            tmp.push_back(w);
            moveEdges.push_back(tmp);//记录一次边的改动
            nextComp += 1;
            moveSteps.push_back(vector <int >());
            travel(w, e);
            moveSteps.back().push_back(u);
        }
    }
}


/**********************************************
*       主函数在此
**********************************************/
int main(int argc, char** argv)
{

    /**********************************************
    *       读入并初始化数据
    **********************************************/

    cin >> n >> m;//读入n与m的值，n个点，m条边
    edges.clear();//初始化，清空所有边
    for (int i = 1; i <= n; i++) edgeList[i].clear();//清空所有点相连的边

    int e, u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;//读入一点边上的两个顶点
        AddEdge(u, v);//添加边
    }

    components.clear();//初始化，清空所有集合
    numComps = 0;//集合标记初始化为0
    memset(comp, -1, sizeof(comp));//点所属于的集合标记为无（-1）

    /**********************************************
    *       遍历所有点并记录集合
    **********************************************/

    for (int i = 1; i <= n; i++)//遍历所有点
    {
        if (comp[i] != -1) continue;//若点i没有所属的集合
        components.push_back(Component());//新建一个集合
        components.back().root = i;//集合的根设为i
        dfs(i, -1);//深度优先搜索寻找与点i相连的点
        numComps += 1;//集合数+1
    }

    /**********************************************
    *       计算每个集合的点数与边数
    **********************************************/

    for (int i = 1; i <= n; i++)
    {
        components[comp[i]].numV += 1;//若点i属于集合comp[i]则，该集合的点数+1
        components[comp[i]].numEdges += edgeList[i].size();//i所属集合的总边数加上所有与i相连的边数
    }
    for (int i = 0; i < components.size(); i++)
    {
        components[i].numEdges /= 2;//去掉重边
    }

    /**********************************************
    *       意义不明
    **********************************************/

    startComp = 0;
    nextComp = 1;
    memset(vis, 0, sizeof(vis));
    if (components.size() > 1)
    {
        sort(components.begin() + 1, components.end());
    }
    moveSteps.clear();
    moveEdges.clear();
    vector <int > tmp;
    if (components[0].numV == 1)
    {
        if (n == 1)
        {
            cout << "YES" << endl;
            cout << "0" << endl;
            cout << "1 1" << endl;
            return 0;
        }
        if (components[1].extraEdge == -1)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {
            tmp.clear();
            tmp.push_back(1);
            moveSteps.push_back(tmp);
            e = components[1].extraEdge;
            v = edges[e].u;
            tmp.clear();
            tmp.push_back(e + 1);
            tmp.push_back(1);
            tmp.push_back(v);
            moveEdges.push_back(tmp);
            startComp = 1;
            components[1].root = v;
            vis[1] = true;
            edges[e].changed = true;
            if (components[1].numEdges + 1 == components[1].numV)
            {
                components.push_back(Component());
                components.back().root = edges[e].v;
                components.back().numV = 1;
            }
        }
    }
    nextComp = startComp + 1;
    travel(components[startComp].root, -1);

    /**********************************************
    *       输出处理
    **********************************************/

    for (int i = 1; i <= n; i++) if (vis[i] == 0)//若有点无法达到
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    cout << moveEdges.size() << endl;
    if (moveEdges.size() == moveSteps.size())
        moveSteps.push_back(vector <int >());
    for (int i = 0; i < moveEdges.size(); i++)
    {
        cout << moveSteps[i].size() << " ";
        for (int j = 0; j < moveSteps[i].size(); j++)
            cout << moveSteps[i][j] << " ";
        cout << endl;
        for (int j = 0; j < moveEdges[i].size(); j++)
            cout << moveEdges[i][j] << " ";
        cout << endl;
    }
    cout << moveSteps.back().size() << " ";
    for (int j = 0; j < moveSteps.back().size(); j++)
        cout << moveSteps.back()[j] << " ";
    cout << endl;

    return (EXIT_SUCCESS);
}
