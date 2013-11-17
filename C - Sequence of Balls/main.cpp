#include <iostream>
#include <cstring>

using namespace std;

char a[4444],b[4444];
int lena,lenb;
int f[4444][4444];
int ca[4444][256];
int cb[4444][256];
int t1,t2,t3,t4;
int pa,pb;

int main()
{
    while (cin>>t1>>t2>>t3>>t4)
    {
        memset(f,0,sizeof(f));
        memset(ca,0,sizeof(ca));
        memset(cb,0,sizeof(cb));
        cin>>(a+1)>>(b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        for (int i=1;i<=lena;i++)
        {
            f[i][0]=t2*i;
            for (int j='a';j<='z';j++)
            {
                ca[i][j]=ca[i-1][j];
            }
            ca[i][a[i]]=i;
        }
        for (int i=1;i<=lenb;i++)
        {
            f[0][i]=t1*i;
            for (int j='a';j<='z';j++)
            {
                cb[i][j]=cb[i-1][j];
            }
            cb[i][b[i]]=i;
        }
        for (int i=1;i<=lena;i++)
        {
            for (int j=1;j<=lenb;j++)
            {
                f[i][j]=min( f[i-1][j]+t2, f[i][j-1]+t1 );
                if (a[i]==b[j])    f[i][j]=min( f[i][j], f[i-1][j-1] );
                else               f[i][j]=min( f[i][j], f[i-1][j-1]+t3 );
                pa=ca[i-1][b[j]];
                pb=cb[j-1][a[i]];
                if (pa!=0&&pb!=0)
                {
                    f[i][j]=min( f[i][j], f[pa-1][pb-1]+t4+(i-pa-1)*t2+(j-pb-1)*t1 );
                }
            }
        }
        cout<<f[lena][lenb]<<endl;
    }
    return 0;
}
