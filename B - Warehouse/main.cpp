//#include <iostream>

#include<fstream>

#include <cstring>
#include <string>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

const string nil="";
string a[44][44];
int n,m,k;
int x,y;
string s;
bool flag;
string id;

int main()
{
    cin>>n>>m>>k;
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            a[i][j]=nil;
        }
    }
    for (int lp=1; lp<=k; lp++)
    {
        cin>>id;
        if (id[0]=='+')
        {
            cin>>x>>y>>s;
            flag=false;
            for (int j=y; j<=m; j++)
            {
                if ( a[x][j]==nil )
                {
                    flag=true;
                    a[x][j]=s;
                    break;
                }
                if (flag) break;
            }
            for (int i=x+1; i<=n; i++)
            {
                if (flag) break;
                for (int j=1; j<=m; j++)
                {
                    if (flag) break;
                    if ( a[i][j]==nil )
                    {
                        flag=true;
                        a[i][j]=s;
                        break;
                    }
                }
            }
        }
        else if (id[0]=='-')
        {
            flag=false;
            cin>>s;
            for (int i=1; i<=n; i++)
            {
                if (flag) break;
                for (int j=1; j<=m; j++)
                {
                    if (flag) break;
                    if ( a[i][j]==s )
                    {
                        a[i][j] =nil;
                        cout<<i<<" "<<j<<endl;
                        flag=true;
                        break;
                    }
                }
            }
            if (!flag)
            {
                cout<<"-1 -1"<<endl;
            }
        }
    }
    return 0;
}


/*
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k1;
    string a[31*31],st;
    cin>>n>>m>>k1;
    int i,j;
    for (int i1=0; i1<k1; i1++)
    {
        cin>>st;
        if (st[0]=='+')
        {
            cin>>i>>j>>st;
            for (int k=(i-1)*m+j-1; k<n*m ; k++) if (a[k]=="")
                {
                    a[k]=st;
                    break;
                }
        }
        else
        {
            cin>>st;
            int f=0;
            for (int k=0; k<n*m ; k++)
                if (a[k]==st)
                {
                    i=k/m+1;
                    j=k%m+1;
                    cout <<i<<' '<<j<<endl;
                    a[k]="";
                    f=1;
                    break;
                }
            if (f==0) cout<<"-1 -1"<<endl;
        }

    }
    return 0;
}
*/
