#include <iostream>
#include <iomanip>
using namespace std;
const double eps=1e-8;
struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
};
point operator-(point A,point B){
    return point(A.x-B.x,A.y-B.y);
}
double cross(point A,point B){
    return A.x*B.y-A.y*B.x;
}
double area(point A,point B,point C){
    return cross(B-A,C-B)*0.5;
}
inline void chmax(double &A, double B) {
    if (B - A > eps)
        A = B;
}
int main()
{
    point p[333];
    int n;
    double ans=0;
    double tmp;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            double Area1=-1,Area2=-1;
            for (int k=0;k<n;k++){
                if (i!=k&&j!=k){
                    tmp=area(p[i],p[j],p[k]);
                    if (tmp>0) chmax(Area1,tmp);
                    else chmax(Area2,-tmp);
                }
            }
            if (Area1>=0&&Area2>=0) ans=max(ans,Area1+Area2);
        }
    }
    cout<<fixed;
    cout<<setprecision(6);
    cout<<ans<<endl;
    return 0;
}
