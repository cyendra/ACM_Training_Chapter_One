/*
#include <iostream>

using namespace std;

bool v[1011];
int prm[1000];
int p=0;

int main()
{
    int n,k,ed,mid;
    v[0]=true;
    v[1]=true;
    for (int i=2; i<=1000; i++)
        if (!v[i])
            for (int j=i+i; j<=1000; j+=i)
                v[j]=true;
    prm[0]=1;
    p=0;
    for (int i=2; i<=1000; i++)
        if (!v[i])
            prm[++p]=i;
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        ed=p;
        for (int i=1; i<=p; i++)
        {
            if (prm[i]>n)
            {
                ed=i-1;
                break;
            }
        }
        if (ed%2==1)
        {
            cout<<n<<" "<<k<<":";
            mid=ed/2;
            if (ed+1<2*k)
            {
                for (int i=0; i<=ed; i++)
                {
                    cout<<" "<<prm[i];
                }
                cout<<endl;
            }
            else
            {
                for (int i=mid-k+1; i<=mid+k; i++)
                {
                    cout<<" "<<prm[i];
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<n<<" "<<k<<":";
            mid=ed/2;
            if (ed+1<2*k-1)
            {
                for (int i=0; i<=ed; i++)
                {
                    cout<<" "<<prm[i];
                }
                cout<<endl;
            }
            else
            {
                for (int i=mid-k+1; i<=mid+k-1; i++)
                {
                    cout<<" "<<prm[i];
                }
                cout<<endl;
            }
        }
        //cout<<endl;
    }
    return 0;
}
*/





#include <iostream>

using namespace std;

bool v[1011];
int prm[1000];
int p=0;

int main()
{
    int n,k,ed,mid;
    v[0]=true;
    v[1]=true;
    for (int i=2; i<=1000; i++)
        if (!v[i])
            for (int j=i+i; j<=1000; j+=i)
                v[j]=true;
    prm[0]=1;
    p=0;
    for (int i=2; i<=1000; i++)
        if (!v[i])
            prm[++p]=i;
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        ed=p;
        for (int i=1; i<=p; i++)
        {
            if (prm[i]>n)
            {
                ed=i-1;
                break;
            }
        }
        if (ed%2==1)
        {
            //cout<<n<<" "<<k<<":";
            mid=ed/2;
            if (ed+1<2*k)
            {
                for (int i=0; i<ed; i++)
                {
                    cout<<prm[i]<<" ";
                }
                cout<<prm[ed]<<endl;
            }
            else
            {
                for (int i=mid-k+1; i<mid+k; i++)
                {
                    cout<<prm[i]<<" ";
                }
                cout<<prm[mid+k]<<endl;
            }
        }
        else
        {
            //cout<<n<<" "<<k<<":";
            mid=ed/2;
            if (ed+1<2*k-1)
            {
                for (int i=0; i<ed; i++)
                {
                    cout<<prm[i]<<" ";
                }
                cout<<prm[ed]<<endl;
            }
            else
            {
                for (int i=mid-k+1; i<mid+k-1; i++)
                {
                    cout<<prm[i]<<" ";
                }
                cout<<prm[mid+k-1]<<endl;
            }
        }
        //cout<<endl;
    }
    return 0;
}

