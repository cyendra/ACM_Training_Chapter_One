#include <iostream>
#include <string>

using namespace std;

string s[4];
int a[4];
int w[4]={0};

int abs(int x)
{
    if (x<0) return -x;
    else return x;
}

int main()
{
    for (int i=0;i<3;i++)
    {
        cin>>s[i];
        if (s[i]=="rock")
        {
            a[i]=1;
        }
        if (s[i]=="paper")
        {
            a[i]=2;
        }
        if (s[i]=="scissors")
        {
            a[i]=0;
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (i!=j)
            {
                if ( a[i]==a[j] ) continue;
                if ( abs(a[i]-a[j])<=1 )
                {
                    if ( a[i]>a[j] )
                    {
                        w[i]++;
                    }
                }
                else
                {
                    if ( a[j]>a[i] )
                    {
                        w[i]++;
                    }
                }
            }
        }
    }
    int win=-1;
    for (int i=0;i<3;i++)
    {
        if ( w[i]==2 ) win=i;
    }
    if (win==-1) cout<<"?"<<endl;
    else if (win==0) cout<<"F"<<endl;
    else if (win==1) cout<<"M"<<endl;
    else if (win==2) cout<<"S"<<endl;
    return 0;
}
