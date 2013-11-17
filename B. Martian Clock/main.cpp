#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

string s;
char a[1111];
char b[1111];

int getv(char c){
    if (c>='0'&&c<='9') return c-'0';
    if (c>='A'&&c<='Z') return c-'A'+10;
    return -1;
}
vector<int>ans;
int main()
{
    cin>>s;
    int len=s.length();
    int p=s.find(':');
    int la=0,lb=0;
    for (int i=0;i<p;i++){
        a[la++]=s[i];
    }
    a[la]=0;
    for (int i=p+1;i<len;i++){
        b[lb++]=s[i];
    }
    b[lb]=0;
    int hh=0,ss=0;
    bool flag;
    for (int bt=2;bt<=200;bt++){
        hh=0,ss=0;
        flag=true;
        for (int i=0;i<la;i++){
            int num=getv(a[i]);
            if (num>=bt){
                flag=false;
                break;
            }
            hh=hh*bt+num;
        }
        if (!flag) continue;
        for (int i=0;i<lb;i++){
            int num=getv(b[i]);
            if (num>=bt){
                flag=false;
                break;
            }
            ss=ss*bt+num;
        }
        if (!flag) continue;
        if (hh>=0&&hh<24&&ss>=0&&ss<60) ans.push_back(bt);
    }
    if (ans.size()==0) cout<<0<<endl;
    else if (ans.size()>100) cout<<-1<<endl;
    else{
        for (int i=0;i<(int)ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
