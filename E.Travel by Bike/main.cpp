#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;
char startday[7][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int day[7]={8,8,8,8,8,4,4};//48
double dead[7];
const double eps=1e-12;
const double dps=1e-8;
int main()
{
    char start[10];
    double s,L;
    while (~scanf("%s%lf%lf",start,&L,&s)){
        double weeks=s*48.0;
        for (int i=0;i<7;i++) dead[i]=s*day[i];
        //int tmp=L/weeks+dps;
//        while (L>weeks){
//            L-=double(tmp)*weeks;
//        }
        int now=0;
        for (int i=0;i<7;i++){
            if (strcmp(startday[i],start)==0){
                now=i;
                break;
            }
        }
        while (now<7){
            L-=dead[now];
            if (L<eps) break;
            now++;
        }

        if (L<eps){
            printf("%s\n",startday[now]);
            continue;
        }

        int tmp=L/weeks+dps;
        L-=(double)tmp*(weeks);

        if (L<eps){
            printf("%s\n",startday[6]);
            continue;
        }

        for (int i=0;i<7;i++){
            L-=dead[i];
            if (L<eps){
                now=i;
                break;
            }
        }
        printf("%s\n",startday[now]);
    }
    return 0;
}

/*
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    string a[7]= {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    double l,l1,l2,s;
    string temp;
    int n;
    while(cin>>temp>>l>>s)
    {
        for(int i=0; i<7; i++)
            if(temp==a[i])
            {
                n=i;
                break;
            }
        int ans=0;
        l1=8.0*s,l2=4.0*s;
        for(int i=n; i<7; i++)
        {
            if(i==5||i==6)
                l-=l2;
            else
                l-=l1;
            if(l<1e-12)
            {
                ans=i;
                break;
            }
        }
        if(l<1e-12)
        {
            cout<<a[ans]<<endl;
            continue;
        }
        int b=l/(48.0*s)+1e-8;
        l-=(double)b*(48.0*s);
        if(l<1e-12)
        {
            cout<<a[6]<<endl;
            continue;
        }
        for(int i=0; i<7; i++)

            if(i==5||i==6) l-=l2;
            else l-=l1;
            if(l<1e-12)
            {
                ans=i;
                break;
            }
        }
        cout<<a[ans]<<endl;
    }
    return 0;
}
*/
