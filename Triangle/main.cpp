#include <iostream>
#include <cstdio>
using namespace std;

int check(int x,int y,int z)
{
    if ( x+y>z && y+z>x && z+x>y )
    {
        return 1;
    }
    else if ( x+y==z || y+z==x || z+x==y )
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a[4];
    int ans;
    ans=0;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    for (int x=0;x<4;x++)
    {
        for (int y=0;y<4;y++)
        {
            for (int z=0;z<4;z++)
            {
                if ( x!=y && y!=z && z!=x )
                {
                    if ( check(a[x],a[y],a[z])==1 )
                    {
                        ans=1;
                    }
                    if ( check(a[x],a[y],a[z])==2 && ans==0 )
                    {
                        ans=2;
                    }

                }
            }
        }
    }
    if (ans==0)
    {
        printf("IMPOSSIBLE\n");
    }
    else if (ans==1)
    {
        printf("TRIANGLE\n");
    }
    else if (ans==2)
    {
        printf("SEGMENT\n");
    }
    return 0;
}
