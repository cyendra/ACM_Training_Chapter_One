/*
    学生信息管理系统 v1.12
    东北林业大学 孙常峰
    博客: http://blog.csdn.net/cyendra
*/

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

/*各种常量*/
const int MAX_INFO=10000;
const int MAX_FILE_NAME=100;
/*结构StuInfo定义了学生信息*/
struct StuInfo
{
    int number;     //学号
    char name[20];  //姓名字符不超过20
    int sex;        //性别 0-男 1-女 2-其它
    int math;		//成绩-高数
    int english;	//成绩-英语
    int cpp;		//成绩-C++
    int physics;	//成绩-大物
    int circuit;	//成绩-电路
    int average;	//平均成绩
    int total;		//总成绩
    int rank;		//名次
    StuInfo* next;
    StuInfo* pre;
    //void swap(StuInfo tmp);
    void cpyto(StuInfo& tmp);
    void adjust();
    void output();
    friend std::istream& operator>>(std::istream& in, StuInfo& dat);
    friend std::ostream& operator<<(std::ostream& out, StuInfo& dat);
};
void StuInfo::cpyto(StuInfo& tmp)
{
    strcpy(tmp.name,name);
    tmp.number=number;
    tmp.sex=sex;
    tmp.math=math;
    tmp.english=english;
    tmp.physics=physics;
    tmp.cpp=cpp;
    tmp.circuit=circuit;
    tmp.total=total;
    tmp.average=average;
    tmp.rank=rank;
}
void swap_info(StuInfo& a,StuInfo& b)
{
    StuInfo tmp;
    a.cpyto(tmp);
    b.cpyto(a);
    tmp.cpyto(b);
}

void StuInfo::adjust()
{
    total=math+english+cpp+physics+circuit;
    average=total/5;
}
void StuInfo::output()
{
    std::cout<<"学号："<<number<<endl;
    std::cout<<"姓名："<<name<<endl;
    std::cout<<"性别："<<sex<<endl;
    std::cout<<"高数成绩："<<math<<endl;
    std::cout<<"英语成绩："<<english<<endl;
    std::cout<<"C++成绩："<<cpp<<endl;
    std::cout<<"大物成绩："<<physics<<endl;
    std::cout<<"电路成绩："<<circuit<<endl;
    std::cout<<"平均成绩："<<average<<endl;
    std::cout<<"总成绩："<<total<<endl;
    std::cout<<"名次："<<rank<<endl;
    std::cout<<"-----"<<endl<<endl;
}
std::istream& operator>>(std::istream& in, StuInfo& dat)
{
    in>>dat.number;
    in>>dat.name;
    in>>dat.sex;
    in>>dat.math;
    in>>dat.english;
    in>>dat.cpp;
    in>>dat.physics;
    in>>dat.circuit;
    in>>dat.average;
    in>>dat.total;
    in>>dat.rank;
    return in;
}

std::ostream& operator<<(std::ostream& out, StuInfo& dat)
{
    out<<dat.number<<endl;
    out<<dat.name<<endl;
    out<<dat.sex<<endl;
    out<<dat.math<<endl;
    out<<dat.english<<endl;
    out<<dat.cpp<<endl;
    out<<dat.physics<<endl;
    out<<dat.circuit<<endl;
    out<<dat.average<<endl;
    out<<dat.total<<endl;
    out<<dat.rank<<endl;
    return out;
}
/*函数声明*/
bool index();
void create_file();
bool load_file();
void save_file();
void show_data();
void add_data();
void adjust_list();
void reset_data();
void change_data(StuInfo* it);
void search_data();
void delete_data();
void sort_data();
void anykey();
void bad_sort(int* bg,int* ed);
int b_search(int key,int a[],int n);
/*
    链表
*/
class Cbadlist{
    private:
        int dat_size;
    public:
        Cbadlist();
        int size();
        StuInfo* begin();
        StuInfo* end();
        StuInfo head,tail;
        void clear();
        void sort(bool (*cmp)(const StuInfo& a,const StuInfo& b));
        void push_back(StuInfo& dat);
        void erase(StuInfo* it);
};

void Cbadlist::sort(bool (*cmp)(const StuInfo& a,const StuInfo& b))
{
    StuInfo* i;
    StuInfo* j;
    StuInfo* p;
    for (i=begin();i!=end();i=i->next)
    {
        p=i;
        for (j=i->next;j!=end();j=j->next)
        {
            if ( (*cmp)( (*p), (*(j)) ) ) p=j;
        }
        if (p!=i) swap_info( (*p),(*(i)) );
    }
}

void Cbadlist::clear()
{
    StuInfo* p=begin();
    while (dat_size!=0)
    {
        delete p;
        dat_size--;
    }
}

StuInfo* Cbadlist::begin()
{
    return head.next;
}
StuInfo* Cbadlist::end()
{
    return &tail;
}

void Cbadlist::push_back(StuInfo& dat)
{
    StuInfo* p=new StuInfo;
    dat.cpyto(*p);
    tail.pre->next=p;
    p->next=&tail;
    p->pre=tail.pre;
    tail.pre=p;
    dat_size++;
}

void Cbadlist::erase(StuInfo* it)
{
    it->pre->next=it->next;
    it->next->pre=it->pre;
    dat_size--;
    delete it;
}

int Cbadlist::size()
{
    return dat_size;
}

Cbadlist::Cbadlist()
{
    dat_size=0;
    head.next=&tail;
    tail.pre=&head;
}

/*学生信息链表*/
Cbadlist stulist;
StuInfo* it;

/*文件输入输出*/
ofstream fout;
ifstream fin;
/*文件修改标记*/
bool savedTag;
/*当前文件名*/
char filename[MAX_FILE_NAME];

bool cmp_num_up(const StuInfo& a,const StuInfo& b)
{
    return a.number<b.number;
}
bool cmp_num_down(const StuInfo& a,const StuInfo& b)
{
    return a.number>b.number;
}
bool cmp_name_up(const StuInfo& a,const StuInfo& b)
{
    return strcmp(a.name,b.name)<0;
}
bool cmp_name_down(const StuInfo& a,const StuInfo& b)
{
    return strcmp(a.name,b.name)>0;
}
bool cmp_rank_up(const StuInfo& a,const StuInfo& b)
{
    return a.rank<b.rank;
}
bool cmp_rank_down(const StuInfo& a,const StuInfo& b)
{
    return a.rank>b.rank;
}

void bad_sort(int* bg,int* ed)
{
    int n=ed-bg;
    int id,mx;
    for (int i=0;i<n;i++)
    {
        id=i;
        mx=bg[i];
        for (int j=i+1;j<n;j++)
        {
            if (bg[j]>mx)
            {
                mx=bg[j];
                id=j;
            }
        }
        swap(bg[id],bg[i]);
    }
}


void anykey()
{
    cout<<">>>";
    system( "pause ");
}

void sort_data()
{
    cout<<"对信息进行排序"<<endl;
    cout<<"1-按学号升序 2-按学号降序"<<endl;
    cout<<"3-按名称升序 4-按名称降序"<<endl;
    cout<<"5-按名次升序 6-按名次降序"<<endl;
    cout<<"0-返回"<<endl;
    cout<<"请输入排序方式：";
    int id;
    cin>>id;
    if (id==1) stulist.sort(cmp_num_up);
    else if (id==2) stulist.sort(cmp_num_down);
    else if (id==3) stulist.sort(cmp_name_up);
    else if (id==4) stulist.sort(cmp_name_down);
    else if (id==5) stulist.sort(cmp_rank_up);
    else if (id==6) stulist.sort(cmp_rank_down);
    else return;
    savedTag=false;
}

void change_data(StuInfo* it)
{
    int id;
    int grade;
    while (1)
    {
        cout<<"1-学号 2-姓名 3-性别"<<endl;
        cout<<"4-高数成绩 5-英语成绩 6-C++成绩"<<endl;
        cout<<"7-大物成绩 8-电路成绩 0-返回"<<endl;
        cout<<"请选择要修改的信息：";
        cin>>id;
        switch (id)
        {
            case 1:
                int num;
                cout<<"请输入新学号：";
                cin>>num;
                it->number=num;
                savedTag=false;
                break;
            case 2:
                char name[20];
                cout<<"请输入新名字：";
                cin>>name;
                strcpy(it->name,name);
                savedTag=false;
                break;
            case 3:
                int sex;
                cout<<"请输入新性别(1-男 2-女 3-其它)：";
                cin>>sex;
                it->sex=sex;
                savedTag=false;
                break;
            case 4:
                cout<<"请输入新高数成绩：";
                cin>>grade;
                it->math=grade;
                savedTag=false;
                break;
            case 5:
                cout<<"请输入新英语成绩：";
                cin>>grade;
                it->english=grade;
                savedTag=false;
                break;
            case 6:
                cout<<"请输入新C++成绩：";
                cin>>grade;
                it->cpp=grade;
                savedTag=false;
                break;
            case 7:
                cout<<"请输入新大物成绩：";
                cin>>grade;
                it->physics=grade;
                savedTag=false;
                break;
            case 8:
                cout<<"请输入新电路成绩：";
                cin>>grade;
                it->circuit=grade;
                savedTag=false;
                break;
            case 0:
                return;
            default:
                cout<<"代码不正确请重新输入"<<endl;
                break;
        }
        it->adjust();
        adjust_list();
    }
}

void delete_data()
{
    if (stulist.size()==0)
    {
        cout<<"没有记录"<<endl;
        return;
    }
    bool found;
    while (1)
    {
        found=false;
        cout<<"删除记录"<<endl;
        cout<<"1-按学号删除 2-按姓名删除 3-按名次删除 0-返回"<<endl;
        cout<<"请输入指令代码：";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"请输入学号：";
            cin>>num;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->number==num)
                {
                    found=true;
                    it->output();
                    cout<<"是否要删除该条信息？（1-是 2-否）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要删除该条信息？（1-是 2-下一条信息 0-否）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        stulist.erase(it);
                        savedTag=false;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else if (id==2)
        {
            char name[20];
            cout<<"请输入姓名：";
            cin>>name;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (strcmp(it->name,name)==0)
                {
                    found=true;
                    it->output();
                    cout<<"是否要删除该条信息？（1-是 2-否）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要删除该条信息？（1-是 2-下一条信息 0-否）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        stulist.erase(it);
                        savedTag=false;
                        break;
                    }
                    else if (id==0)
                    {
                        break;
                    }
                }
            }
        }
        else if (id==3)
        {
            int rank;
            cout<<"请输入名次：";
            cin>>rank;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->rank==rank)
                {
                    found=true;
                    it->output();
                    cout<<"是否要删除该条信息？（1-是 2-下一条信息 0-否）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要删除该条信息？（1-是 2-下一条信息 0-否）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        stulist.erase(it);
                        savedTag=false;
                        break;
                    }
                    else if (id==0)
                    {
                        break;;
                    }
                }
            }
        }
        else
        {
            cout<<"代码不正确请重新输入"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"删除的信息并不存在"<<endl;
        }
        adjust_list();
    }
}

void search_data()
{
    bool found;
    while (1)
    {
        found=false;
        cout<<"查询信息"<<endl;
        cout<<"1-按学号查询 2-按姓名查询 3-按名次查询 0-返回"<<endl;
        cout<<"请输入指令代码：";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"请输入学号：";
            cin>>num;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->number==num)
                {
                    found=true;
                    it->output();
                }
            }
        }
        else if (id==2)
        {
            char name[20];
            cout<<"请输入姓名：";
            cin>>name;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (strcmp(it->name,name)==0)
                {
                    found=true;
                    it->output();
                }
            }
        }
        else if (id==3)
        {
            int rank;
            cout<<"请输入名次：";
            cin>>rank;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->rank==rank)
                {
                    found=true;
                    it->output();
                }
            }
        }
        else
        {
            cout<<"代码不正确请重新输入"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"查询的信息并不存在"<<endl;
        }
    }
}

void reset_data()
{
    if (stulist.size()==0)
    {
        cout<<"没有记录"<<endl;
        return;
    }
    bool found;
    while (1)
    {
        found=false;
        cout<<"修改记录"<<endl;
        cout<<"1-按学号查询 2-按姓名查询 3-按名次查询 0-返回"<<endl;
        cout<<"请输入指令代码：";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"请输入学号：";
            cin>>num;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->number==num)
                {
                    found=true;
                    it->output();
                    cout<<"是否要修改该条信息？（1-是 2-下一条信息 0-返回）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要修改该条信息？（1-是 2-下一条信息 0-返回）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        change_data(it);
                        break;
                    }
                    else if (id==0)
                    {
                        break;
                    }
                }
            }
        }
        else if (id==2)
        {
            char name[20];
            cout<<"请输入姓名：";
            cin>>name;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (strcmp(it->name,name)==0)
                {
                    found=true;
                    it->output();
                    cout<<"是否要修改该条信息？（1-是 0-返回）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要修改该条信息？（1-是 2-下一条信息 0-返回）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        change_data(it);
                        break;
                    }
                    else if (id==0)
                    {
                        break;
                    }
                }
            }
        }
        else if (id==3)
        {
            int rank;
            cout<<"请输入名次：";
            cin>>rank;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->rank==rank)
                {
                    found=true;
                    it->output();
                    cout<<"是否要修改该条信息？（1-是 0-返回）：";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"代码错误请重新输入！"<<endl;
                            cout<<"是否要修改该条信息？（1-是 2-下一条信息 0-返回）：";
                        }
                        else break;
                    }
                    if (id==1)
                    {
                        change_data(it);
                        break;
                    }
                    else if (id==0)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            cout<<"代码不正确请重新输入"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"修改的信息并不存在"<<endl;
        }
        adjust_list();
    }
}

int b_search(int key,int a[],int n)
{
    int l=0,r=n-1;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (a[m]==key) return m;
        if (a[m]>key) l=m+1;
        else r=m-1;
    }
    return -1;
}


void adjust_list()
{
    int sum[MAX_INFO]={0};
    int p=0;
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        sum[p++]=it->total;
    }
    bad_sort(sum,sum+p);
    int n=1;
    for (int i=1;i<p;i++)
    {
        if (sum[i]!=sum[i-1]) sum[n++]=sum[i];
    }
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        it->rank=b_search(it->total,sum,n)+1;
    }
}

void add_data()
{
    StuInfo dat;
    cout<<"添加新的学生信息"<<endl;
    cout<<"学号：";
    cin>>dat.number;
    cout<<"姓名：";
    cin>>dat.name;
    cout<<"性别：(0-男 1-女 2-其它)：";
    cin>>dat.sex;
    cout<<"高数成绩：";
    cin>>dat.math;
    cout<<"英语成绩：";
    cin>>dat.english;
    cout<<"C++成绩：";
    cin>>dat.cpp;
    cout<<"大物成绩：";
    cin>>dat.physics;
    cout<<"电路成绩：";
    cin>>dat.circuit;
    dat.adjust();
    stulist.push_back(dat);
    adjust_list();
    cout<<"学生"<<dat.name<<"的信息登陆完毕"<<endl;
    savedTag=false;
}

void show_data()
{
    if (stulist.size()==0)
    {
        cout<<"数据库中无学生信息"<<endl;
        return;
    }
    cout<<"学生人数："<<stulist.size()<<endl;
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        it->output();
    }
    cout<<"学生信息展示完毕"<<endl;
}

void save_file()
{
    int id;
    do
    {
        cout<<"1、保存  2、另存为  0、返回"<<endl;
        cout<<"请输入模式代码：";
        cin>>id;
        if (id!=1&&id!=2&&id!=0) cout<<"代码错误！请重新输入"<<endl;
    }while (id!=1&&id!=2&&id!=0);
    if (id==0) return;
    if (id==2||filename[0]=='\0')
    {
        cout<<"请输入保存文件名：";
        cin>>filename;
    }
    fout.open(filename,ios_base::out|ios_base::trunc);
    fout<<stulist.size()<<endl;
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        fout<<(*it);
    }
    fout.close();
    cout<<"文件保存完毕"<<endl;
    savedTag=true;
}

bool load_file()
{
    cout<<"从纪录文件读取学生信息"<<endl;
    cout<<"请输入要读取的文件名：";
    cin>>filename;
    stulist.clear();
    fin.open(filename,ios_base::in);
    if (fin.fail()){
        memset(filename,0,sizeof(filename));
        return false;
    }
    int n;
    fin>>n;
    while (n--)
    {
        StuInfo tmp;
        fin>>tmp;
        stulist.push_back(tmp);
    }
    fin.close();
    cout<<"学生信息读取完毕"<<endl;
    savedTag=true;
    return true;
}

void create_file()
{
    cout<<"新建学生信息文件"<<endl;
    cout<<"请输入文件名";
    cin>>filename;
    fout.open(filename,ios_base::out|ios_base::trunc);
    fout.close();
    cout<<"学生信息文件"<<filename<<"创建完毕"<<endl;
}

bool index()
{
    int id;
    cout<<"1、增加学生信息\n2、修改学生信息\n"
        "3、显示学生信息\n4、查询学生信息\n"
        "5、删除学生信息\n6、对学生信息进行排序\n"
        "7、保存学生信息至纪录文件\n8、从纪录文件读取学生信息\n"
        "9、新建学生信息文件\n10、运行结束\n";
    if (filename[0]=='\0') cout<<"当前没有打开的学生信息文件"<<endl;
    else
    {
        cout<<"当前打开的学生信息文件为"<<filename<<endl;
        if (!savedTag) cout<<"当前信息未保存"<<endl;
    }
    cout<<"请输入指令代码: ";
    cin>>id;
    system("cls");
    switch (id)
    {
    case 1:
        add_data();
        break;
    case 2:
        reset_data();
        break;
    case 3:
        show_data();
        break;
    case 4:
        search_data();
        break;
    case 5:
        delete_data();
        break;
    case 6:
        sort_data();
        break;
    case 7:
        save_file();
        break;
    case 8:
        if ( !load_file() ) cout<<"错误：文件并不存在！"<<endl;
        break;
    case 9:
        create_file();
        break;
    case 10:
        return false;
    default:
        cout<<"错误的指令，请重新输入"<<endl;
    }
    return true;
}

int main()
{
    memset(filename,0,sizeof(filename));
    savedTag=true;
    while (1)
    {
        if (!index()) break;
        anykey();
        system("cls");
    }
    return 0;
}
