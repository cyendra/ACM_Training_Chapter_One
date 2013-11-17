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
*       ����ṹ��Edge
**********************************************/

struct Edge//�ߵĽṹ��
{
    int u, v;//����
    bool changed;
    Edge() {}
    Edge(int u, int v) : u(u), v(v), changed(false) {}
};

int n, m;
vector <Edge > edges;//����ߵ�����
vector <int > edgeList[100010];//�������߶�Ӧ��ϵ������

/**********************************************
*       ����һ���ߵĺ���
**********************************************/

void AddEdge(int u, int v)
{
    int k = edges.size();
    edgeList[u].push_back(k);//�������u���ӵı�k
    edgeList[v].push_back(k);
    edges.push_back(Edge(u, v));
}

/**********************************************
*       ���Ͻṹ��Ķ���
*       ��¼���ϵ���Ϣ
*       ����<������
*       �ڹ��캯���г�ʼ������
**********************************************/

struct Component
{
    int root;//���ڵ�
    int numEdges;//����
    int numV;//����
    int extraEdge;//����ı�(������ʱ����)

    Component()//���캯������ʼ������
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
*       ������ֱ���������
**********************************************/

int numComps, comp[100010];
vector <Component > components;

vector <vector <int > > moveSteps;
vector <vector <int > > moveEdges;
bool vis[100010];
int startComp, nextComp;

/**********************************************
*       �����������
*       Ѱ�����u�����ĵ㲢���д���
*       uΪ��ǰ�ڵ�ı��
*       fatherΪ��ߵı��
**********************************************/

void dfs(int u, int father)
{
    comp[u] = numComps;//����u���Ϊ����numComps
    int numChild = 0;//�ӽڵ���
    for (int i = 0; i < edgeList[u].size(); i++)//������u���������б�
    {
        int e = edgeList[u][i];//���u�����ĵ�i���ߵı��Ϊe
        if (e == father) continue;//��e�������ͬ�������˱�
        int v = (edges[e].u == u) ? edges[e].v : edges[e].u;//vΪ�ߵ���һ������
        if (comp[v] == -1)//����vδ�����
        {
            dfs(v, e);//dfsȾɫ
            numChild += 1;//�ӽڵ�����1
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
*       Ѱ��·��
**********************************************/

void travel(int u, int father)
{
    if (vis[u]) return;//����u�ѷ��ʹ��򷵻�
    vis[u] = true;//��ǵ�uΪ�ѷ���
    if (father == -1) moveSteps.push_back(vector <int >());//����uΪ��������һ���µ��ƶ�·����������
    moveSteps.back().push_back(u);//����u���뵱ǰ��·����
    for (int i = 0; i < edgeList[u].size(); i++)//������u���������б�
    {
        int e = edgeList[u][i];//���u�����ĵ�i���ߵı��Ϊe
        if (e == father || edges[e].changed) continue;//��eΪ��߻��Ѿ��ı���������˱�
        int v = (edges[e].u == u) ? edges[e].v : edges[e].u;//vΪ�ߵ���һ������
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
            moveEdges.push_back(tmp);//��¼һ�αߵĸĶ�
            nextComp += 1;
            moveSteps.push_back(vector <int >());
            travel(w, e);
            moveSteps.back().push_back(u);
        }
    }
}


/**********************************************
*       �������ڴ�
**********************************************/
int main(int argc, char** argv)
{

    /**********************************************
    *       ���벢��ʼ������
    **********************************************/

    cin >> n >> m;//����n��m��ֵ��n���㣬m����
    edges.clear();//��ʼ����������б�
    for (int i = 1; i <= n; i++) edgeList[i].clear();//������е������ı�

    int e, u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;//����һ����ϵ���������
        AddEdge(u, v);//��ӱ�
    }

    components.clear();//��ʼ����������м���
    numComps = 0;//���ϱ�ǳ�ʼ��Ϊ0
    memset(comp, -1, sizeof(comp));//�������ڵļ��ϱ��Ϊ�ޣ�-1��

    /**********************************************
    *       �������е㲢��¼����
    **********************************************/

    for (int i = 1; i <= n; i++)//�������е�
    {
        if (comp[i] != -1) continue;//����iû�������ļ���
        components.push_back(Component());//�½�һ������
        components.back().root = i;//���ϵĸ���Ϊi
        dfs(i, -1);//�����������Ѱ�����i�����ĵ�
        numComps += 1;//������+1
    }

    /**********************************************
    *       ����ÿ�����ϵĵ��������
    **********************************************/

    for (int i = 1; i <= n; i++)
    {
        components[comp[i]].numV += 1;//����i���ڼ���comp[i]�򣬸ü��ϵĵ���+1
        components[comp[i]].numEdges += edgeList[i].size();//i�������ϵ��ܱ�������������i�����ı���
    }
    for (int i = 0; i < components.size(); i++)
    {
        components[i].numEdges /= 2;//ȥ���ر�
    }

    /**********************************************
    *       ���岻��
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
    *       �������
    **********************************************/

    for (int i = 1; i <= n; i++) if (vis[i] == 0)//���е��޷��ﵽ
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
