#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct People{
    string name;
    int taxi;
    int pizza;
    int girl;
    People(){}
    People(string _name,int a,int b,int c){
        name=_name;
        taxi=a;
        pizza=b;
        girl=c;
    }
};

vector<People>vec;
vector<string>ansT,ansP,ansG;
const int idx[10]={ 0,1,3,4,6,7 };
int check(string s){
    bool flag=true;
    for (int i=0;i<6-1;i++){
        if (s[idx[i]]!=s[idx[i+1]]){
            flag=false;
            break;
        }
    }
    if (flag) return 1;
    flag=true;
    for (int i=0;i<6-1;i++){
        if (s[idx[i]]<=s[idx[i+1]]){
            flag=false;
            break;
        }
    }
    if (flag) return 2;
    return 3;
}

int main()
{
    int n;
    int mx_taxi=0,mx_pizza=0,mx_girl=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int s;
        int taxi=0,pizza=0,girl=0;
        string name;
        cin>>s>>name;
        for (int k=0;k<s;k++){
            string num;
            cin>>num;
            int res=check(num);
            if (res==1) taxi++;
            else if (res==2) pizza++;
            else if (res==3) girl++;
        }
        if (taxi>mx_taxi) mx_taxi=taxi;
        if (pizza>mx_pizza) mx_pizza=pizza;
        if (girl>mx_girl) mx_girl=girl;
        //cerr<<name<<" "<<taxi<<" "<<pizza<<" "<<girl<<endl;
        vec.push_back(People(name,taxi,pizza,girl));
    }
    for (int i=0;i<(int)vec.size();i++){
        if (vec[i].taxi==mx_taxi) ansT.push_back(vec[i].name);
        if (vec[i].pizza==mx_pizza) ansP.push_back(vec[i].name);
        if (vec[i].girl==mx_girl) ansG.push_back(vec[i].name);
    }
    cout<<"If you want to call a taxi, you should call:";
    for (int i=0;i<(int)ansT.size();i++){
        cout<<" "<<ansT[i];
        if (i!=(int)ansT.size()-1) cout<<",";
        else cout<<"."<<endl;
    }
    cout<<"If you want to order a pizza, you should call:";
    for (int i=0;i<(int)ansP.size();i++){
        cout<<" "<<ansP[i];
        if (i!=(int)ansP.size()-1) cout<<",";
        else cout<<"."<<endl;
    }
    cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
    for (int i=0;i<(int)ansG.size();i++){
        cout<<" "<<ansG[i];
        if (i!=(int)ansG.size()-1) cout<<",";
        else cout<<"."<<endl;
    }
    return 0;
}
