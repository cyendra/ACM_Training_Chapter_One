#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 50005
using namespace std;
int num[N];
struct Tree
{
    int l; //��˵�
    int r; //�Ҷ˵�
    int sum; //����
} tree[N*4]; // ���߶εĳ���ΪN��������Ļ�һ�㿪��N ���ı�
void build(int root,int l,int r)//root ��ʾ���ڵ� ���������䷶Χ��l,r��
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)// �����Ҷ˵����ʱ����Ҷ�ӽڵ�
    {
        tree[root].sum=num[l]; // ����ֵ
        return; // �ݹ����
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid); //k<<1�����k*2 ������������
    build(root<<1|1,mid+1,r); //k<<1|1 �൱��k*2+1,���������Һ���
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum; // ���׵�sum = ���ӵ�sum + �Һ��ӵ�sum
}
void update(int root,int pos,int val) //root �Ǹ��ڵ㣬pos��val��ʾ������Ҫ������pos �����ֵ����Ϊval
{
    if(tree[root].l==tree[root].r) // �����Ҷ�ӽڵ㣬����pos��Ӧ��λ��
    {
        tree[root].sum=val; // ���²���
        return; // �ݹ����
    }
    int mid=(tree[root].l+ tree[root].r)/2;
    if(pos<=mid) // ���pos ������ root ��Ӧ�����ӵĻ����͵��� update(k<<1,pos,val);����������
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum; // ���׵�sum = ���ӵ�sum+ �Һ��ӵ�sum
}
int query(int root,int L,int R)// root ��ʾ���ڵ㣬[L,R]��ʾҪ��ѯ������
{
    if(L<=tree[root].l&&R>=tree[root].r) // [L,R]Ҫ��ѯ������ ���� root �ڵ��ʾ������ֱ�ӷ���root�ڵ��sum ֵ
        return tree[root].sum;
    int mid=(tree[root].l+ tree[root].r)/2,ret=0;
    if(L<=mid) ret+=query(root<<1,L,R); // ��ѯ root �ڵ������
    if(R>mid) ret+=query(root<<1|1,L,R); // ��ѯroot �ڵ���Һ���
    return ret; // ����
}
int main()
{
    int ca,cas=1,n,Q,a,b;
    char str[10];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&num[i]); // ��ʾ��i��ı�������
        build(1,1,N); // �����߶������ڵ� 1����ʾ�����䷶Χ��1���Ρ�
        printf("Case %d:\n",cas++);
        while(scanf("%s",str),strcmp(str,"End"))
        {
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Query")==0)
            {
                if(a>b)swap(a,b); // ��ѯ������ ��a��b��
                printf("%d\n",query(1,a,b)); //�����ѯ���
            }
            else if(strcmp(str,"Add")==0)
            {
                num[a]=num[a]+b;
                update(1,a,num[a]); // ���� a��ֵΪnum[a]
            }
            else if(strcmp(str,"Sub")==0)
            {
                num[a]= num[a]-b;
                update(1,a,num[a]);
            }
        }
    }
    return 0;
}

