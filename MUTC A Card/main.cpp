#include <iostream>
#include <cstring>

using namespace std;
const int mm=52;
int a[60],b[60];
int ans[1111][60];
int n,l,r;
int lp;


bool check(int a[],int b[])
{
    for (int i=1;i<=mm;i++)
        if (a[i]!=b[i]) return false;
    return true;
}
void move(int a[],int l,int r)
{
    int tmp[60]={0};
    for (int i=1;i<=r-l+1;i++) tmp[i]=a[i+l-1];
    for (int i=l-1;i>=1;i--) a[i+r-l+1]=a[i];
    for (int i=1;i<=r-l+1;i++) a[i]=tmp[i];
}
int main()
{
    int T;
    int cas=1;
    cin>>T;
    while (T--)
    {
        //init()
        lp=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=mm;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            ans[lp][i]=a[i];
        }
        cin>>n>>l>>r;
        do
        {
            move(a,l,r);
            lp++;
            for (int i=1;i<=mm;i++) ans[lp][i]=a[i];
            //for (int i=1;i<=mm;i++) cerr<<" "<<ans[lp][i];cerr<<endl;
        }while (!check(a,b));
        //cerr<<lp<<endl;
        int p=n%lp;
        cout<<"Case #"<<cas<<":";
        cas++;
        for (int i=1;i<=mm;i++) cout<<" "<<ans[p][i];
        cout<<endl;
    }
    return 0;
}
