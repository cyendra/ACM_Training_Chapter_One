#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int day12[13]={ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int lday12[13]={ 0,31,29,31,30,31,30,31,31,30,31,30,31 };

class IDNumberVerification{
    private:
        int tonum(string s){
            int ret=0;
            int len=s.length();
            for (int i=0;i<len;i++) ret=ret*10+s[i]-'0';
            return ret;
        }
        int cmpday(int y1,int m1,int d1,int y2,int m2,int d2){
            if (y1==y1&&m1==m2&&d1==d2) return 0;
            if (y1>y2) return 1;
            if (y1==y2&&m1>m2) return 1;
            if (y1==y2&&m1==m2&&d1>d2) return 1;
            return -1;
        }
        bool isleap(int year){
            if ( (year%4==0&&year%100!=0)||(year%400==0) ) return true;
            return false;
        }
        bool isdate(int y,int m,int d){
            if (y<1900||y>2011) return false;
            if (m>12||m<1) return false;
            if (d<1) return false;
            if (!isleap(y)){
                if (d>day12[m]) return false;
            }
            else if (d>lday12[m]) return false;
            return true;
        }
        bool getx(string id){
            long long a=0;
            long long bit=1;
            for (int i=17;i>=0;i--){
                if (id[i]=='X') a+=10*bit;
                else a+=(id[i]-'0')*bit;
                bit*=2;
            }
            if (a%11==1) return true;
            return false;
        }
    public:
        string verify(string id, vector<string> regionCodes)
        {
            bool find;
            string male="Male";
            string female="Female";
            string invalid="Invalid";
            string region=id.substr(0,6);
            string birthday=id.substr(6,8);
            string sequential=id.substr(14,3);
            string checksum=id.substr(17,1);
            int year=tonum(birthday.substr(0,4));
            int month=tonum(birthday.substr(4,2));
            int day=tonum(birthday.substr(6,2));
            find=false;
            int siz=regionCodes.size();
            for (int i=0;i<siz;i++)
                if (regionCodes[i]==region){
                    find=true;
                    break;
                }
            if (!find) return invalid;
            if (!isdate(year,month,day)) return invalid;
            if (cmpday(year,month,day,1900,1,1)<0||
                cmpday(year,month,day,2011,12,31)>0) return invalid;
            if (!getx(id)) return invalid;
            if (sequential=="000") return invalid;
            if (tonum(sequential)&1) return male;
            else return female;
        }
};

int main()
{
    string id,s;
    vector<string> ss;
    cin>>id;
    int n;
    cin>>n;
    while (n--)
    {
        cin>>s;
        ss.push_back(s);
    }
    IDNumberVerification solver;
    cout<<solver.verify(id,ss)<<endl;
    return 0;
}


