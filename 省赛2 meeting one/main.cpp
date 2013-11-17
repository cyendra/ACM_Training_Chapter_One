/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <list>
using namespace std;
struct node{
char name[25];
int city,county;
node(char a[],int c,int n){
strcpy(name,a);city=c;county=n;
}
};
int beCity[105];

int main()
{
    int conum,n,cocnt,num,q,ca=1;
    char name[25],op[5];
    while(~scanf("%d",&n))
    {
        map<string,int>my;
        list<node>mylist;
        list<node>::iterator it,tmp1,tmp2;
        cocnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&conum);
                beCity[++cocnt]=i;
                while(conum--)
                {
                scanf("%s",name);
                my[name]=cocnt;
                }
            }
        }
        scanf("%d",&q);
        printf("Scenario #%d\n",ca++);
        while(q--)
        {
            scanf("%s",op);
            if(op[0]=='i')
            {
                scanf("%s",name);
                int id=my[name];
                bool f1=0,f2=0;
                for(it=mylist.begin();it!=mylist.end();++it)
                {
                    if(it->county==id) {f1=1;tmp1=it;}
                    if(it->city==beCity[id]) {f2=1;tmp2=it;}
                }
                //cout<<f1<<" "<<f2<<endl;
                if(f1)
                {
                    ++tmp1;
                    if(tmp1==mylist.end())
                    mylist.push_back(node(name,beCity[id],id));
                    else mylist.insert(tmp1,node(name,beCity[id],id));
                }
                else if(f2){
                    ++tmp2;
                    if(tmp2==mylist.end())
                    mylist.push_back(node(name,beCity[id],id));
                    else mylist.insert(tmp2,node(name,beCity[id],id));
                }
                else  mylist.push_back(node(name,beCity[id],id));
            }
            else
            {
                scanf("%d",&num);
                //printf("out num:%d\n",num);

                while(num--)
                {
                    it=mylist.begin();
                    printf("%s\n",it->name);
                    //tmp1=it;
                    mylist.erase(it);
                    //it=tmp1;
                }
            }
        }
    }
    return 0;
}
*/


#include <iostream>
#include <list>
#include <string>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

struct HENTAI
{
    char name[20];
    int city;
    int county;
    HENTAI(char *a,int b,int c )
    {
        strcpy(name,a);
        city=b;
        county=c;
    }
};

list<HENTAI>lnk;
list<HENTAI>::iterator it,lp1,lp2;

int city[2111];
map<string,int>county;

int n,m,p,q;
char str[20],name[20];
int cod;
int tmp;

int main()
{
    cod=0;
    while (~scanf("%d",&n))
    {
        //初始化
        memset(city,0,sizeof(city));
        lnk.clear();
        county.clear();

        //读入数据
        int cnt=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            while (m--)
            {
                city[++cnt]=i;
                scanf("%d",&p);
                while (p--)
                {
                    scanf("%s",str);
                    county[str]=cnt;
                }
            }
        }

        //输出
        printf("Scenario #%d\n",++cod);

        //处理准备
        cnt=0;
        scanf("%d",&q);
        bool flag;
        while (q--)
        {
            scanf("%s",str);

            //处理添加
            if ( str[0]=='i' )
            {
                scanf("%s",name);
                flag=false;
                tmp=county[name];
                lp1=lnk.end();
                lp2=lnk.end();
                for (it=lnk.begin(); it!=lnk.end(); it++)
                {
                    if (it->county==tmp)
                    {
                        lp1=it;
                    }
                    if (it->city==city[tmp])
                    {
                        lp2=it;
                    }
                }
                if (lp1!=lnk.end())
                {
                    lp1++;
                    if (lp1==lnk.end())
                    {
                        lnk.push_back( HENTAI(name, city[tmp], tmp) );
                    }
                    else lnk.insert( lp1, HENTAI(name, city[tmp], tmp) );
                }
                else if (lp2!=lnk.end())
                {
                    lp2++;
                    if (lp2==lnk.end())
                    {
                        lnk.push_back( HENTAI(name, city[tmp], tmp) );
                    }
                    else lnk.insert( lp2, HENTAI(name, city[tmp], tmp) );
                }
                else
                {
                    lnk.push_back( HENTAI(name, city[tmp], tmp)) ;
                }
            }
            //处理删除
            else if ( str[0]=='o' )
            {
                int num;
                scanf("%d",&num);
                while (num--)
                {
                    printf("%s\n",lnk.begin()->name);
                    lnk.pop_front();
                }
            }
        }
        printf("\n");
    }
    return 0;
}


/*

                for (it=lnk.begin(); it!=lnk.end(); it++)
                {
                    if ( it->county==tmp )
                    {
                        it++;

                        flag=true;
                        break;

                    }


                }
                if (!flag)
                {
                    for (it=lnk.begin(); it!=lnk.end(); it++)
                    {
                        if ( it->city==city[tmp] )
                        {
                            it++;
                            if (it==lnk.end())
                            {
                                lnk.push_back( HENTAI(name, city[tmp], tmp) );
                            }
                            else lnk.insert( it, HENTAI(name, city[tmp], tmp) );
                            flag=true;
                            break;
                        }
                    }
                }
                if (!flag)
                {

                    flag=true;
                }
            }
*/

/*
#include<iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

map<string,int>hashName;

struct P
{
	int city;
	int county;
	string name;
}ps[10005];

struct NodeName
{
	int thisName;
	int nextName;
	int lastName;
}nodeName[100005];

int n,m,p,q;

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	int ttt=0;
	int K=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Scenario #%d\n",K++);
		//if(ttt++!=0)cout<<endl;
		int num=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&p);
				for(int k=1;k<=p;k++)
				{
					ps[num].city=i;
					ps[num].county=i*m+j;
					cin>>ps[num].name;
					hashName[ps[num].name]=num++;
				}
			}
		}
		scanf("%d",&q);

		int now,all,end;
		now=end=all=1;
		end=0;
		for(int i=0;i<q;i++)
		{
			string op;
			cin>>op;
			if(op=="in")
			{
				string name;
				cin>>name;
				int id = hashName[name];
				//cout << id<<endl;
				//cout<<ps[id].name<<endl;
				nodeName[all].lastName = nodeName[all].nextName = 0;
				nodeName[all++].thisName = id;

				int j;
				j=end;
				if(j==0)
				{
					//cout<<"4444"<<endl;
					now = all-1;
					end = all-1;
				}
				else
				{
					int tt=j;
					bool b1=false;
					bool b2=false;
					for(;;)
					{

						if(ps[nodeName[j].thisName].county==ps[nodeName[all-1].thisName].county)
						{
							//cout<<"222"<<endl;
							b1=true;
							break;
						}
						if(ps[nodeName[j].thisName].city==ps[nodeName[all-1].thisName].city)
						{
							//cout<<"222"<<endl;
							b2=true;
						}
						if(nodeName[j].lastName==0&&b2==false)
						{
							//cout<<"333"<<endl;
							nodeName[end].nextName = all-1;
							nodeName[all-1].lastName = end;
							end = all-1;
							break;
						}
						if(j==0)break;
						j = nodeName[j].lastName;
					}
					j=tt;
					if(b1)
					{
						while(1)
						{
							if(ps[nodeName[j].thisName].county==ps[nodeName[all-1].thisName].county)
							{
								if(j!=end)
								{
									nodeName[nodeName[j].nextName].lastName = all-1;
								}
								else
								{
									end = all-1;
								}
								nodeName[all-1].nextName=nodeName[j].nextName;
								nodeName[j].nextName = all-1;
								nodeName[all-1].lastName = j;
								break;
							}
							j = nodeName[j].lastName;
						}
					}
					else if(b2)
					{
						while(1)
						{
							if(ps[nodeName[j].thisName].city==ps[nodeName[all-1].thisName].city)
							{
								if(j!=end)
								{
									nodeName[nodeName[j].nextName].lastName = all-1;
								}
								else
								{
									end = all-1;
								}
								nodeName[all-1].nextName=nodeName[j].nextName;
								nodeName[j].nextName = all-1;
								nodeName[all-1].lastName = j;
								break;
							}
							j = nodeName[j].lastName;
						}
					}
				}

			}
			else
			{
				int num;
				scanf("%d",&num);
				for(int j=1;j<=num;j++)
				{
				//	cout<<now<<endl;
					cout<<ps[nodeName[now].thisName].name<<endl;
					nodeName[nodeName[now].nextName].lastName=0;
					now = nodeName[now].nextName;
					if(now==0)end=0;
				}
			}
		}
		printf("\n");
	}
}
*/
