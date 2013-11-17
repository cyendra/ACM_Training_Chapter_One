#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps=1e-6;
const double G=9.8;
double solve(int v,int d){
    double tmp=(G*d)/(v*v);
    if(fabs(tmp-1.000000)<eps){
        tmp=1.000000;
    }
    double res=asin(tmp);
    double pi=acos(-1.0);
    res=res*180/pi;
    return res;
}

int T;
int v,d;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&v,&d);
        printf("Case #%d: %.7f\n",cas,solve(v,d)/2);
    }
    return 0;
}
