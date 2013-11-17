#include <iostream>

using namespace std;
int r1,r2,c1,c2,d1,d2;
int a[2][2];
bool solve()
{
    if (a[0][0]+a[0][1]!=r1) return false;
    if (a[1][0]+a[1][1]!=r2) return false;
    if (a[0][0]+a[1][0]!=c1) return false;
    if (a[0][1]+a[1][1]!=c2) return false;
    if (a[0][0]+a[1][1]!=d1) return false;
    if (a[0][1]+a[1][0]!=d2) return false;
    return true;
}

int main()
{
    bool flag=false;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            if (i==j) continue;
            for (int k=1; k<=9; k++){
                if (k==i||k==j) continue;
                for (int l=1; l<=9; l++){
                    if (l==i||l==j||l==k) continue;
                    a[0][0]=i;
                    a[0][1]=j;
                    a[1][0]=k;
                    a[1][1]=l;
                    if (solve()){
                        flag=true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (flag){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
