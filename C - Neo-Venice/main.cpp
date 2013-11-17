#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    double t,s,x;
    double ans;
    while (~scanf("%d%lf%lf",&n,&t,&s)){
        for (int i=0;i<n;i++){
            cin>>x;
            ans=(t-(x-s))/2.0+s+(x-s);
            printf("%0.6f\n",ans);
        }
    }
    return 0;
}
