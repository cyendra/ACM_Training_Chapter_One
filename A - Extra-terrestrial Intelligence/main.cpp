#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string,int>mp1;
map<int,string>mp2;

string str;
int n,m;

int main()
{
    cin>>str;
    cin>>m;
    m=m%12;
    mp1["January"]=1;
    mp1["February"]=2;
    mp1["March"]=3;
    mp1["April"]=4;
    mp1["May"]=5;
    mp1["June"]=6;
    mp1["July"]=7;
    mp1["August"]=8;
    mp1["September"]=9;
    mp1["October"]=10;
    mp1["November"]=11;
    mp1["December"]=0;
    n=mp1[str];
    n=(n+m)%12;
    mp2[0]="December";
    mp2[1]="January";
    mp2[2]="February";
    mp2[3]="March";
    mp2[4]="April";
    mp2[5]="May";
    mp2[6]="June";
    mp2[7]="July";
    mp2[8]="August";
    mp2[9]="September";
    mp2[10]="October";
    mp2[11]="November";
    str=mp2[n];
    cout<<str<<endl;
    return 0;
}
