#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,m;
typedef struct{
    char name[11];
    int tm[13];
    int rd[13];
    int ac;
    int grade;
}STU;

STU a[1000];
/*
bool cmp(STU a,STU b)
{
    if (a.ac>b.ac)
    {
        return true;
    }
    else if (a.ac<b.ac)
    {
        return false;
    }
    else if (a.grade<b.grade)
    {
        return true;
    }
    else if (a.grade>b.grade)
    {
        return false;
    }
    else
    {
        return strcmp(a.name,b.name);
    }
}
*/
int cmp(const void *a, const void *b)
{
    if ((*(STU *)a).ac != (*(STU *)b).ac)
        return (*(STU *)a).ac - (*(STU *)b).ac;
    else if ((*(STU *)b).grade != (*(STU *)a).grade)
        return (*(STU *)b).grade - (*(STU *)a).grade;
    else
        return strcmp((*(STU *)b).name, (*(STU *)a).name);
}



int main()
{
    char rs[100];
    scanf("%d%d",&n,&m);
    int loop=0;
    int result;
    int x,y;
    while (scanf("%s",a[loop].name)!=EOF)
    {
        a[loop].ac=0;
        a[loop].grade=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",rs);
            result=sscanf(rs,"%d(%d)",&x,&y);
            if (result==2)
            {
                a[loop].tm[i]=x;
                a[loop].rd[i]=y;
            }
            else
            {
                a[loop].tm[i]=x;
                a[loop].rd[i]=0;
            }
            if (a[loop].tm[i]>0)
            {
                a[loop].grade+=abs(a[loop].tm[i])+m*a[loop].rd[i];
            }

            if (a[loop].tm[i]>0)
            {
                a[loop].ac+=1;
            }
        }
        loop++;
    }
    qsort(a,loop,sizeof(STU),cmp);
    for (int i=loop-1;i>=0;i--)
    {
        printf("%-10s %2d %4d\n",a[i].name,a[i].ac,a[i].grade);
    }
    return 0;
}
