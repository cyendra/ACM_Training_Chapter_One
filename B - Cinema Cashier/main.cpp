#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int N,K;
int M[1010];
bool map[110][110];
int mx,my;
int x,y;

bool ok;
int tmp;
int ri,rj;

int main()
{
    int min;
    cin >> N >> K;
    for (int i=1; i<=N; i++)
    {
        cin >> M[i];
    }
    mx=(K+1)/2;
    my=(K+1)/2;
    memset(map,0,sizeof(map));
    for (int cp=1; cp<=N; cp++)
    {
        min=9999999;
        for (int i=1; i<=K; i++)
        {
            for (int j=1; j<=K; j++)
            {
                if (j+M[cp]-1>K) break;
                ok=true;
                for (int t=j; t<=j+M[cp]-1; t++)
                {
                    if ( map[i][t]==true )
                    {
                        j=t;
                        ok=false;
                        break;
                    }
                }
                if ( ok==true )
                {
                    tmp=0;
                    if ( j+M[cp]-1<=my )
                    {
                        tmp=(2*my-2*j-M[cp]+1)*M[cp]/2+abs(i-mx)*M[cp];
                    }
                    else if ( j>=my )
                    {
                        tmp=(2*j-2*my+M[cp]-1)*M[cp]/2+abs(i-mx)*M[cp];
                    }
                    else
                    {
                        tmp=(my-j)*(my-j+1)/2+(j+M[cp]-1-my)*(j+M[cp]-my)/2+abs(i-mx)*M[cp];
                    }
                    if (tmp<min)
                    {
                        min=tmp;
                        ri=i;
                        rj=j;
                    }
                }
            }
        }
        if (min==9999999)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << ri<< " "<< rj << " "<< rj+M[cp]-1 << endl;
            for (int fk=rj;fk<=rj+M[cp]-1;fk++)
            {
                map[ri][fk]=true;
            }
        }
    }
    return 0;
}

/*
View Code

#include<stdio.h>
#include<math.h>
#include<string.h>

int ll[1009];
bool map[109][109];

int main()
{
    int n,len;
    memset(map,0,sizeof(map));
    scanf("%d%d",&n,&len);

    int i2=(len+1)/2;
    int j2=(len+1)/2;

    int i,j;

    for(i=1;i<=n;i++)
    {
        scanf("%d",&ll[i]);
    }

    int k,p;

    for(k=1;k<=n;k++)
    {
        int min=99999999;
        int ri,rj;
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len;j++)
            {
                if(j+ll[k]-1>len) break;

                int ok=0;
                for(p=0;p<ll[k];p++)
                {
                    if(map[i][j+p]==1)
                    {
                        j=j+p;
                        ok=1;
                        break;
                    }
                }
                if(ok==0)
                {
                    int all=0;
                    if(j+ll[k]-1<=j2)
                    {
                        all=(2*j2-2*j-ll[k]+1)*ll[k]/2+abs(i-i2)*ll[k];
                    }
                    else if(j>=j2)
                    {
                        all=(2*j-2*j2+ll[k]-1)*ll[k]/2+abs(i-i2)*ll[k];
                    }
                    else
                    {
                        all=(j2-j)*(j2-j+1)/2+(j+ll[k]-1-j2)*(j+ll[k]-j2)/2+abs(i-i2)*ll[k];
                    }

                    if(min>all)
                    {
                        min=all;
                        ri=i;
                        rj=j;
                    }
                }
            }
        }

        if(min==99999999)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d %d\n",ri,rj,rj+ll[k]-1);
            for(p=0;p<ll[k];p++)
            {
                map[ri][rj+p]=1;
            }
        }
    }
}
*/
