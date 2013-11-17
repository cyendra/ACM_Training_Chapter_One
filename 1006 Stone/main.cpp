#include <iostream>

using namespace std;
int n,m;
int main()
{
    while (cin>>n>>m){
        if (n==0&&m==0) break;
        if (n-1==m+1){
            //cout<<"Tang"<<endl;
            cout<<"Jiang"<<endl;
        }
        else if ((n-1)%(m+1)==0){
            //cout<<""
            cout<<"Jiang"<<endl;
        }
        else{
            cout<<"Tang"<<endl;
        }
    }
    return 0;
}
