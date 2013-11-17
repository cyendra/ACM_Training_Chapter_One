#include <iostream>
#include <cstring>
using namespace std;

bool a[222][222];
int ans[2222];
int n,m;
int cnt;
int bg;
bool dfs(int u,int deep)
{
    ans[deep]=u;//����u���뵽·����
    if (deep==m)//�����������еı�
    {
        if (u==bg)//�յ������㣬���ҵ�ŷ����·
        {
            for (int i=0; i<=m; i++)
            {
                cout<<ans[i]<<" ";//���·��
            }
            cout<<endl;
        }
        return true;//�ҵ��ֵ�����С��ŷ����·
    }
    for (int i=1; i<=n; i++)//�������нڵ�
    {
        if (a[u][i])//����ǰ��u���i���б�
        {
            a[u][i]=false;a[i][u]=false;//�����˱߱�ʾ�Ѿ�������
            if (dfs(i,deep+1))//Ѱ����һ����
            {
                return true;//�ҵ��ֵ�����С��ŷ����·��ֱ�ӷ���true
            }
            a[u][i]=true;a[i][u]=true;//����
        }
    }
    return false;//δ�ҵ�ŷ����·
}

/*
void dfs(int u)
{
    for (int i=1;i<=n;i++)
    {
        if (a[u][i])
        {
            a[u][i]=false;
            a[i][u]=false;
            dfs(i);
            ans[++cnt]=i;
        }
    }
}
*/
int main()
{

    while(cin>>n>>m>>bg)
    {
        cnt=0;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        for (int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]=true;
            a[y][x]=true;
        }
        dfs(bg,0);
        /*
        if (ret)
        {
            for (int i=1;i<=m;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Not find"<<endl;
        }
        */
    }
    return 0;
}
