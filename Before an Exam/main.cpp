#include <iostream>

using namespace std;

int maxtime[250],mintime[250];
int day,sumtime;
int num[250];
int now;
int nowmax,p;

int main()
{
    cin >> day >> sumtime;
    now=0;
    nowmax=0;
    for (int i=0;i<day;i++)
    {
        cin >> mintime[i] >> maxtime[i];
        now+=mintime[i];
        nowmax+=maxtime[i];
        num[i]=mintime[i];
    }
    if ( now>sumtime || nowmax<sumtime )
    {
        cout << "NO" << endl;
    }
    else
    {
        p=0;
        while ( p<day && now<sumtime )
        {
            if ( num[p]>=maxtime[p] )
            {
                p++;
            }
            else
            {
                now++;
                num[p]++;
            }
        }
        cout << "YES" << endl;
        cout << num[0];
        for (int i=1;i<day;i++)
        {
            cout << " " << num[i];
        }
        cout <<endl;
    }

    return 0;
}
