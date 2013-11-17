#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int a1,a2,a3,a4;
char s[2111111];
char tmp[2111111];
char ad4[2111111];
char ad7[2111111];
int l4,l7;
int len,cnt;
bool solve(){
    len=0;
    if (abs(a3-a4)>1) return false;
    if (a3==0&&a4==0&&a1*a2!=0) return false;
    int c4=0,c7=0;
    if (a3>a4){
        for (int i=0;i<a3;i++){
            s[len++]='4';
            s[len++]='7';
            c4++,c7++;
        }
    }
    else if (a3<a4){
        for (int i=0;i<a4;i++){
            s[len++]='7';
            s[len++]='4';
            c4++,c7++;
        }
    }
    else{
        if (a1<=a3){
            for (int i=0;i<a4;i++){
                s[len++]='7';
                s[len++]='4';
                c4++,c7++;
            }
            s[len++]='7';
            c7++;
        }
        else{
            for (int i=0;i<a3;i++){
                s[len++]='4';
                s[len++]='7';
                c4++,c7++;
            }
            s[len++]='4';
            c4++;
        }
    }
    a1=a1-(c4);
    a2=a2-(c7);
    if (a1<0||a2<0) return false;
    l4=l7=0;
    for (int i=0;i<a1;i++) ad4[l4++]='4';
    for (int i=0;i<a2;i++) ad7[l7++]='7';
    ad4[l4]=0;
    ad7[l7]=0;
    if (a3==0&&a4==0){
        if (a1>0) strcpy(s,ad4);
        else if (a2>0) strcpy(s,ad7);
        return true;
    }
    cnt=0;
    //cerr<<"text "<<s<<endl;
    if (a1>0){
        for (int i=0;i<len;i++){
            tmp[cnt++]=s[i];
            if (s[i]=='4'){
                for (int j=0;j<l4;j++){
                    tmp[cnt++]=ad4[j];
                }
                for (int j=i+1;j<len;j++){
                    tmp[cnt++]=s[j];
                }
                break;
            }
        }
        tmp[cnt]=0;
        //strcpy(s,tmp);
        for (int i=0;i<=cnt;i++) s[i]=tmp[i];
        s[cnt]=0;
        len=cnt;
    }
    cnt=0;
    if (a2>0){
        int p=0;
        for (p=len-1;p>=0;p--){
            if (s[p]=='7') break;
        }
        //cerr<<"p="<<p<<endl;
        //cerr<<"ad7 "<<ad7<<endl;
        //cerr<<s<<endl;
        for (int i=0;i<len;i++){
            tmp[cnt++]=s[i];
            //cerr<<tmp[cnt-1]<<endl;
            if (i==p){
                //cerr<<"move!"<<endl;
                for (int j=0;j<l7;j++){
                    tmp[cnt++]=ad7[j];
                    //cerr<<tmp[cnt-1]<<endl;
                }
                for (int j=i+1;j<len;j++){
                    tmp[cnt++]=s[j];
                }
                break;
            }
        }
        tmp[cnt]=0;
        //cerr<<"templa "<<tmp<<endl;
        for (int i=0;i<=cnt;i++) s[i]=tmp[i];
        //strcpy(s,tmp);
        s[cnt]=0;
        len=cnt;
    }
    return true;
}

int main()
{
    cin>>a1>>a2>>a3>>a4;
    if (!solve()) cout<<-1<<endl;
    else cout<<s<<endl;
    return 0;
}

