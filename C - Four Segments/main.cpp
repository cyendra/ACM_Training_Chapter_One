#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef struct{
    int x;
    int y;
}POINT;

typedef struct{
    POINT v1,v2;
}RT;

RT a[5];

int xmin,xmax,ymin,ymax;

set <int> st;
set <int>::iterator it;

int _min(int a,int b,int c)
{
    return min(a,min(b,c));
}
int _max(int a,int b,int c)
{
    return max(a,max(b,c));
}


int main()
{
        cin >> a[0].x1 >> a[0].y1 >> a[0].x2 >> a[0].y2;
        st.insert(a[0].x1);
        st.insert(a[0].x2);
        st.insert(a[0].y1);
        st.insert(a[0].y2);
        xmin=min(a[0].x1,a[0].x2);
        xmax=max(a[0].x1,a[0].x2);
        ymin=min(a[0].y1,a[0].y2);
        ymax=max(a[0].y1,a[0].y2);

    for (int i=1;i<4;i++)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        st.insert(a[i].x1);
        st.insert(a[i].x2);
        st.insert(a[i].y1);
        st.insert(a[i].y2);
        xmin=_min(xmin,a[i].x1,a[i].x2);
        xmax=_max(xmax,a[i].x1,a[i].x2);
        ymin=_min(ymin,a[i].y1,a[i].y2);
        ymax=_max(ymax,a[i].y1,a[i].y2);
    }
    cout << xmin << xmax << ymin << ymax << endl;
    if (st.size()!=4)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (xmin==xmax||ymin==ymax)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout <<"YES"<<endl;
    return 0;
}
