#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int root[55555];
int kind[55555];//kind[i]��ʾi�븸�ڵ�֮�����Թ�ϵ��0��ʾ��ͬ��1��ʾ�ԣ�2��ʾ����

int n,K;

void make_set(int n)
{
    for (int i=0; i<=n; i++)
    {
        root[i]=i;//��ʼ��Ϊn�������ļ���
        kind[i]=0;//���ڵ����Թ�ϵΪ0
    }
}

int find_set(int x)
{
    if (root[x]==x) return x;
    int fa=root[x];//��¼��ǰ�ĸ��ڵ�
    root[x]=find_set(root[x]);//Ѱ�Ҹ��ڵ�,��ָ����ڵ�,ע������������и��ڵ��kindֵ�����˸ı�
    kind[x]=(kind[x]+kind[fa])%3;//����ǰ�ĸ��ڵ����Թ�ϵ����
    return root[x];
}

bool union_set(int x,int y,int d)
{
    int a=find_set(x);
    int b=find_set(y);
    if (a==b)
    {
        if (d==1&&kind[x]!=kind[y]) return false;
        if (d==2&&((kind[x]-kind[y]+3)%3!=1)) return false;
        return true;
    }
    else
    {
        root[a]=b;//������a���뼯��b����ʱ��Ϊb��kind[b]Ϊ0��
        if (d==2)//����d��ֵ����kind[a]����x��y֮���kind�Ƴ�a�����b��kind
        {
            kind[a]=(kind[y]-kind[x]+1+3)%3;//k'[x]=(k[x]+k[a])%3=k[y]+1���ε�k[a]=(k[y]+1-k[x])%3
        }
        else if (d==1)
        {
            kind[a]=(kind[y]-kind[x]+3)%3;//k'[x]=(k[x]+k[a])%3=k[y]���ε�k[a]=(k[y]-k[x])%3
        }
        return true;
    }
}

int main()
{
    int x,y,d;
    scanf("%d%d",&n,&K);
    make_set(n);
    int ans=0;
    for (int lp=1; lp<=K; lp++)
    {
        scanf("%d%d%d",&d,&x,&y);
        if (x>n||y>n||(x==y&&d==2))
        {
            ans++;
            continue;
        }
        if (!union_set(x,y,d)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
