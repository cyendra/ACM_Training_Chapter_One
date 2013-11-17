#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n1[100],n2[100];
int p1,p2;

long long int na,nb,bta,btb;

int mint,mini;

bool cmp(int a,int b)
{
    return a>b;
}

string str;

int main()
{
    cin >> na;
    cin >> str;
    if (str.length()>1 && str[0]=='0' )
    {
        cout << "WRONG_ANSWER" << endl;
        return 0;
    }
    nb=0;
    for (int i=0;i<str.length();i++)
    {
        nb=nb*10+( str[i]-'0' );
    }
    //cout <<str<<endl;
    //cout <<nb<<endl;
    if (na==0 && nb==0)
    {
        cout << "OK" << endl;
        return 0;
    }

    bta=na;
    p1=0;
    while (na!=0)
    {
        n1[p1]=na%10;
        na=na/10;
        p1++;
    }

    btb=nb;
    p2=0;
    while (nb!=0)
    {
        n2[p2]=nb%10;
        nb=nb/10;
        p2++;
    }

    //cout << p1 << p2 << endl;
    if (p1!=p2)
    {
        cout << "WRONG_ANSWER" << endl;
        return 0;
    }
    if (p1==1)
    {
        if (bta==btb)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "WRONG_ANSWER" << endl;
        }
        return 0;
    }

    mint=9999;
    mini=0;

    for (int i=0;i<p1;i++)
    {
        if (n1[i]<mint && n1[i]!=0 )
        {
            mint=n1[i];
            mini=i;
        }
    }
    int t;
    t=n1[p1-1];
    n1[p1-1]=n1[mini];
    n1[mini]=t;
    sort(n1,n1+p1-1,cmp);

    bool ok=true;



    for (int i=0;i<p1;i++)
    {
        if (n1[i]!=n2[i])
        {
            ok=false;
            break;
        }
    }
    if (ok==true)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "WRONG_ANSWER" << endl;
    }
    return 0;
}
