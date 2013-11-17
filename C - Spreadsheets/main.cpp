#include <iostream>
#include <cstring>
using namespace std;
char in[2000],out[2000];
bool isnum(char c)
{
    if ( c>='0'&&c<='9' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void decode(int b)
{
    int i=0,m=0;
    while(b>0)
    {
        out[m]=b%26;
        b/=26;
        if(!out[m])out[m]=26,--b;
        ++m;
    }
    strrev(out);
    for(i=0;i<m;++i)out[i]+='A'-1;
    out[m]='\0';
}
int main()
{
    int n,flag,a,b;

    cin>>n;
    while(n--)
    {
        flag=0;
        a=0;
        b=0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        cin>>in;
        for (int i=1;i<strlen(in);i++)
        {
            if (isnum(in[i-1])&&!isnum(in[i]))
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            int p;
            p=1;
            while(isnum(in[p]))
            {
                a=a*10+in[p]-'0';
                p++;
            }
            p++;
            while(isnum(in[p]))
            {
                b=b*10+in[p]-'0';
                p++;
            }
            decode(b);
            cout<<out<<a<<endl;
        }
        else
        {
            a=0;
            b=0;
            for (int i=0;i<strlen(in);i++)
            {
                if (!isnum(in[i]))
                {
                    a=a*26+in[i]-'A'+1;
                }
                else
                {
                    b=b*10+in[i]-'0';
                }
            }
            cout<<"R"<<b<<"C"<<a<<endl;
        }
    }
    return 0;
}
