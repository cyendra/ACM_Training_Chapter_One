#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

typedef struct {
    string team_name;
    int gold;
    int silver;
    int copper;
}TEAM_DAY;

struct SCHOOL_DAY{
    string school_name;
    int gold;
    int silver;
    int copper;
    int team_num;
    map<string,int> find_team;
    TEAM_DAY team[200];
}school[200];

typedef struct{
    //string city_name;
    int gold;
    int silver;
    int copper;
}CITY_LIFE;

map<string,CITY_LIFE>city;
int t;
int n;
int school_num,city_num;
map<string,int> find_school;
string s1,s2,s3,s4;

int main()
{
    scanf("%d",&t);
    for (int loop=0;loop<t;loop++)
    {
        scanf("%d",&n);
        school_num=0;
        city_num=0;
        for (int i=0;i<n;i++)
        {
            cin >> s1 >> s2 >> s3 >>s4;
            //处理学校
            if (find_school[s1]==0)
            {
                find_school[s1]=school_num;
                school_num++;
                school[ find_school[s1] ].school_name=s1;
                school[ find_school[s1] ].gold=0;
                school[ find_school[s1] ].silver=0;
                school[ find_school[s1] ].copper=0;
                school[ find_school[s1] ].team_num=0;
            }
            else
            {
                school[ find_school[s1] ].school_name=s1;
            }
            if (s3=="gold")
            {
                school[ find_school[s1] ].gold++;
            }
            if (s3=="silver")
            {
                school[ find_school[s1] ].silver++;
            }
            if (s3=="copper")
            {
                school[ find_school[s1] ].copper++;
            }
            //处理队伍
            if (school[ find_school[s1] ].find_team[s2]==0)
            {
                school[ find_school[s1] ].find_team[s2]=school[ find_school[s1] ].team_num;
                school[ find_school[s1] ].team_num++;
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].team_name=s2;
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].gold=0;
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].silver=0;
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].copper=0;
            }
            else
            {
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].team_name=s2;
            }
            if (s3=="gold")
            {
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].gold++;
            }
            if (s3=="silver")
            {
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].silver++;
            }
            if (s3=="copper")
            {
                school[ find_school[s1] ].team[ school[ find_school[s1] ].find_team[s2] ].copper++;
            }
            //处理城市
            if (s3=="gold")
            {
                city[s4].gold++;
            }
            if (s3=="silver")
            {
                city[s4].silver++;
            }
            if (s3=="copper")
            {
                city[s4].copper++;
            }
        }
        //检验
        for (int i=0;i<school_num;i++)
        {
            cout << school[i].school_name<<endl;
        }
    }
    return 0;
}
