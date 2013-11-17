#include <iostream>
#include <cstring>

using namespace std;

char map[111][111];
int la,lb,lc,ld;
int lenx,leny;
int n;
int c[30]= {0};

int main()
{
    cin>>la>>lb>>lc>>ld;
    cin>>n;
    for (int i=0; i<n; i++) cin>>c[i];
    lenx=max(lb,ld);
    leny=la+lc;

    for (int i=1; i<=lenx; i++)
    {
        for (int j=1; j<=leny; j++)
        {
            map[i][j]='.';
        }
    }

    for (int i=1; i<=lb; i++)
    {
        for (int j=1; j<=la; j++)
        {
            map[i][j]='0';
        }
    }

    for (int i=1; i<=ld; i++)
    {
        for (int j=la+1; j<=la+lc; j++)
        {
            map[i][j]='0';
        }
    }

    if ( ((lb>=ld)&&(ld%2==0))||((lb<=ld)&&(lb%2==1)) )
    {
        int p=0;
        int dit=0;
        int i=1;
        int j=1;
        while (p<n)
        {
            if (c[p]<=0)
            {
                p++;
                continue;
            }
            if (map[i][j]!='0')
            {
                i++;
                dit=(dit+1)%2;
                while (map[i][j]!='0')
                {
                    if (dit==0) j++;
                    else j--;
                }
                continue;
            }
            map[i][j]='a'+p;
            c[p]--;
            if (dit==0) j++;
            else j--;
        }
    }
    else
    {
        int p=0;
        int dit=1;
        int i=1;
        int j=la+lc;
        while (p<n)
        {
            if (c[p]<=0)
            {
                p++;
                continue;
            }
            if (map[i][j]!='0')
            {
                i++;
                dit=(dit+1)%2;
                while (map[i][j]!='0')
                {
                    if (dit==0) j++;
                    else j--;
                }
                continue;
            }
            map[i][j]='a'+p;
            c[p]--;
            if (dit==0) j++;
            else j--;
        }
    }


    cout<<"YES"<<endl;
    for (int i=1; i<=lenx; i++)
    {
        for (int j=1; j<=leny; j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }

    return 0;
}



/*

#include <iostream>
#include <cstring>

using namespace std;

char map[111][111];
int la,lb,lc,ld;
int lenx,leny;
int n;
int c[30]= {0};

int main()
{
    cin>>la>>lb>>lc>>ld;
    cin>>n;
    for (int i=0; i<n; i++) cin>>c[i];
    lenx=max(lb,ld);
    leny=la+lc;

    for (int i=1; i<=lenx; i++)
    {
        for (int j=1; j<=leny; j++)
        {
            map[i][j]='.';
        }
    }

    for (int i=1; i<=lb; i++)
    {
        for (int j=1; j<=la; j++)
        {
            map[i][j]='0';
        }
    }

    for (int i=1; i<=ld; i++)
    {
        for (int j=la+1; j<=la+lc; j++)
        {
            map[i][j]='0';
        }
    }




    int p=0;
    int dit=0;
    int i=1;
    int j=1;
    while (p<n)
    {
        if (c[p]<=0)
        {
            p++;
            continue;
        }
        if (map[i][j]!='0')
        {
            i++;
            dit=(dit+1)%2;
            while (map[i][j]!='0')
            {
                if (dit==0) j++;
                else j--;
            }
            continue;
        }
        map[i][j]='a'+p;
        c[p]--;
        if (dit==0) j++;
        else j--;
    }
    cout<<"YES"<<endl;
    for (int i=1; i<=lenx; i++)
    {
        for (int j=1; j<=leny; j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }

    return 0;
}


*/
