#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


string str;
int a[10]={0,0,0,0,0,0};
bool cmp(int a,int b)
{
    return a>b;
}
map<char,int>mp;
int main()
{
    int ans;
    mp['R']=0;
    mp['O']=1;
    mp['Y']=2;
    mp['G']=3;
    mp['B']=4;
    mp['V']=5;
    cin>>str;
    for (int i=0;i<6;i++)
    {
        a[ mp[ str[i] ] ]++;
    }
    sort(a,a+6,cmp);
    if ( a[0]>=5 )
    {
        ans=1;
    }
    else if ( a[0]==4 )
    {
        ans=2;
    }
    else if ( a[0]==3 )
    {
        if ( a[1]==3 )
        {
            ans=2;
        }
        else if ( a[1]==2 )
        {
            ans=3;
        }
        else if (a[1]==1)
        {
            ans=5;
        }
    }
    else if ( a[0]==2 )
    {
        if ( a[1]==2 )
        {
            if ( a[2]==2 )
            {
                ans=6;
            }
            else if ( a[2]==1 )
            {
                ans=8;
            }
        }
        else if ( a[1]==1 )
        {
            ans=15;
        }
    }
    else if (a[0]==1 )
    {
        ans=30;
    }
    cout<<ans<<endl;
    return 0;
}
