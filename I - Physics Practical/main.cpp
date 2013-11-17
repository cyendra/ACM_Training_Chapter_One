//#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

queue<int>que;

int n;
int a[111111]={0};

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int tmp=0;
    int ans=0;
    while (!que.empty()) que.pop();
    for (int i=0;i<n;i++)
    {
        que.push(a[i]);
        if (!que.empty())
        {
            if (que.front()*2<que.back())
            {
                que.pop();
            }
        }
        if (que.size()>ans) ans=que.size();
    }
    cout<<n-ans<<endl;
    return 0;
}
