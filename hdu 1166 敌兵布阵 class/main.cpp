#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class emtree{
    public:
        emtree(int t);
        void setnum(int t);
        void input();
        void updata(int i,int x);
        int query(int i);
    private:
        int n;
        int a[55555];
        int lowbit(int i);

};

void emtree::setnum(int t)
{
    n=t;
    for (int i=0;i<=n;i++)
    {
        a[i]=0;
    }
}

emtree::emtree(int t)
{
    n=t;
    for (int i=0;i<=n;i++)
    {
        a[i]=0;
    }
}

int emtree::query(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=a[i];
        i=i-lowbit(i);
    }
    return sum;
}

void emtree::updata(int i,int x)
{
    while (i<=n)
    {
        a[i]=a[i]+x;
        i+=lowbit(i);
    }
}

void emtree::input()
{
    int tmp;
    for (int i=1;i<=n;i++)
    {
        //cin>>tmp;
        scanf("%d",&tmp);
        updata(i,tmp);
    }
}

int emtree::lowbit(int i)
{
    return i&(-i);
}

int main()
{
    int cas=0;
    string str;
    int T,n;
    int a,b;
    //cin>>T;
    scanf("%d",&T);
    emtree tree(0);
    while (T--)
    {
        cas++;
        cout<<"Case "<<cas<<":"<<endl;
        //cin>>n;
        scanf("%d",&n);
        tree.setnum(n);
        tree.input();
        while (cin>>str)
        {
            if (str=="End") break;
            if (str=="Add")
            {
                //cin>>a>>b;
                scanf("%d%d",&a,&b);
                tree.updata(a,b);
            }
            if (str=="Sub")
            {
                //cin>>a>>b;
                scanf("%d%d",&a,&b);
                tree.updata(a,-b);
            }
            if (str=="Query")
            {
                //cin>>a>>b;
                scanf("%d%d",&a,&b);
                cout<<(tree.query(b)-tree.query(a-1))<<endl;
            }
        }
    }
    return 0;
}
