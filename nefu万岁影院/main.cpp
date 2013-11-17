#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int x, y;
}node;
node num[102];

int cmp(node a,node b)
{
    return a.y<b.y;
}

int main()
{
    int n,e,sum;
    while(cin>>n)
    {
        if (n==-1) break;
        for(int i = 0; i<n; i++)
            cin>>num[i].x>>num[i].y;
        sort(num,num+n,cmp);
        e = 0;
        sum = 0;
        for(int i = 0; i<n; i++)
        {
            if(num[i].x>=e)//这个节目的开始时间大于等于上一个节目的结束时间
            {
                e = num[i].y;
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
