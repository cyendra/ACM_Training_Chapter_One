#include <iostream>

using namespace std;

char str[100];
int pl[100];
int wl[100];

int main()
{
    int T,n;
    int lnum,len,rnum,p;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>pl[i];
        }
        lnum=0;
        len=0;
        for (int i=0;i<n;i++)
        {
            while (pl[i]>lnum)
            {
                str[len++]='(';
                lnum++;
            }
            str[len++]=')';
        }
        str[len]='\0';
        rnum=lnum=p=0;
        for (int i=0;i<len;i++)
        {
            if (str[i]==')')
            {
                lnum=rnum=0;
                for (int j=i-1;j>=0;j--)
                {
                    if (str[j]==')')
                    {
                        rnum++;
                    }
                    else if (str[j]=='(')
                    {
                        lnum++;
                        if (rnum==0)
                        {
                            break;
                        }
                        else
                        {
                            rnum--;
                        }
                    }
                }
                wl[p++]=lnum;
            }
        }
        for (int i=0;i<p-1;i++)
        {
            cout<<wl[i]<<" ";
        }
        cout<<wl[p-1]<<endl;
    }
    return 0;
}
