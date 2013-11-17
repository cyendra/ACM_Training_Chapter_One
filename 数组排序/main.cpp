#include <iostream>

using namespace std;
int run(const int *a,int n);
int run(const int *a,int n){
    int b[111],c[111];
    int ans=0;
    for (int i=0;i<n;i++){
        b[i+1]=a[i];
    }
    for (int i=1;i<=n;i++){
        c[b[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (b[i]!=i){
            int t=c[i];
            int q=b[i];
            swap(b[i],b[c[i]]);
            c[i]=i;
            c[q]=t;
            ans++;
        }
    }
    return ans;
}
int main()
{
    int a[111],n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    cout<<run(a,n)<<endl;

    return 0;
}
