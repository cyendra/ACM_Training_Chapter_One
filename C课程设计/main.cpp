/*
    ѧ����Ϣ����ϵͳ v1.12
    ������ҵ��ѧ �ﳣ��
    ����: http://blog.csdn.net/cyendra
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

/*���ֳ���*/
const int MAX_INFO=10000;
const int MAX_FILE_NAME=100;
/*�ṹStuInfo������ѧ����Ϣ*/
struct StuInfo
{
    int number;     //ѧ��
    char name[20];  //�����ַ�������20
    int sex;        //�Ա� 0-�� 1-Ů 2-����
    int math;		//�ɼ�-����
    int english;	//�ɼ�-Ӣ��
    int cpp;		//�ɼ�-C++
    int physics;	//�ɼ�-����
    int circuit;	//�ɼ�-��·
    int average;	//ƽ���ɼ�
    int total;		//�ܳɼ�
    int rank;		//����
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
    std::cout<<"ѧ�ţ�"<<number<<endl;
    std::cout<<"������"<<name<<endl;
    std::cout<<"�Ա�"<<sex<<endl;
    std::cout<<"�����ɼ���"<<math<<endl;
    std::cout<<"Ӣ��ɼ���"<<english<<endl;
    std::cout<<"C++�ɼ���"<<cpp<<endl;
    std::cout<<"����ɼ���"<<physics<<endl;
    std::cout<<"��·�ɼ���"<<circuit<<endl;
    std::cout<<"ƽ���ɼ���"<<average<<endl;
    std::cout<<"�ܳɼ���"<<total<<endl;
    std::cout<<"���Σ�"<<rank<<endl;
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
/*��������*/
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
    ����
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

/*ѧ����Ϣ����*/
Cbadlist stulist;
StuInfo* it;

/*�ļ��������*/
ofstream fout;
ifstream fin;
/*�ļ��޸ı��*/
bool savedTag;
/*��ǰ�ļ���*/
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
    cout<<"����Ϣ��������"<<endl;
    cout<<"1-��ѧ������ 2-��ѧ�Ž���"<<endl;
    cout<<"3-���������� 4-�����ƽ���"<<endl;
    cout<<"5-���������� 6-�����ν���"<<endl;
    cout<<"0-����"<<endl;
    cout<<"����������ʽ��";
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
        cout<<"1-ѧ�� 2-���� 3-�Ա�"<<endl;
        cout<<"4-�����ɼ� 5-Ӣ��ɼ� 6-C++�ɼ�"<<endl;
        cout<<"7-����ɼ� 8-��·�ɼ� 0-����"<<endl;
        cout<<"��ѡ��Ҫ�޸ĵ���Ϣ��";
        cin>>id;
        switch (id)
        {
            case 1:
                int num;
                cout<<"��������ѧ�ţ�";
                cin>>num;
                it->number=num;
                savedTag=false;
                break;
            case 2:
                char name[20];
                cout<<"�����������֣�";
                cin>>name;
                strcpy(it->name,name);
                savedTag=false;
                break;
            case 3:
                int sex;
                cout<<"���������Ա�(1-�� 2-Ů 3-����)��";
                cin>>sex;
                it->sex=sex;
                savedTag=false;
                break;
            case 4:
                cout<<"�������¸����ɼ���";
                cin>>grade;
                it->math=grade;
                savedTag=false;
                break;
            case 5:
                cout<<"��������Ӣ��ɼ���";
                cin>>grade;
                it->english=grade;
                savedTag=false;
                break;
            case 6:
                cout<<"��������C++�ɼ���";
                cin>>grade;
                it->cpp=grade;
                savedTag=false;
                break;
            case 7:
                cout<<"�������´���ɼ���";
                cin>>grade;
                it->physics=grade;
                savedTag=false;
                break;
            case 8:
                cout<<"�������µ�·�ɼ���";
                cin>>grade;
                it->circuit=grade;
                savedTag=false;
                break;
            case 0:
                return;
            default:
                cout<<"���벻��ȷ����������"<<endl;
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
        cout<<"û�м�¼"<<endl;
        return;
    }
    bool found;
    while (1)
    {
        found=false;
        cout<<"ɾ����¼"<<endl;
        cout<<"1-��ѧ��ɾ�� 2-������ɾ�� 3-������ɾ�� 0-����"<<endl;
        cout<<"������ָ����룺";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"������ѧ�ţ�";
            cin>>num;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->number==num)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-�񣩣�";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-��һ����Ϣ 0-�񣩣�";
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
            cout<<"������������";
            cin>>name;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (strcmp(it->name,name)==0)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-�񣩣�";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-��һ����Ϣ 0-�񣩣�";
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
            cout<<"���������Σ�";
            cin>>rank;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->rank==rank)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-��һ����Ϣ 0-�񣩣�";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫɾ��������Ϣ����1-�� 2-��һ����Ϣ 0-�񣩣�";
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
            cout<<"���벻��ȷ����������"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"ɾ������Ϣ��������"<<endl;
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
        cout<<"��ѯ��Ϣ"<<endl;
        cout<<"1-��ѧ�Ų�ѯ 2-��������ѯ 3-�����β�ѯ 0-����"<<endl;
        cout<<"������ָ����룺";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"������ѧ�ţ�";
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
            cout<<"������������";
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
            cout<<"���������Σ�";
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
            cout<<"���벻��ȷ����������"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"��ѯ����Ϣ��������"<<endl;
        }
    }
}

void reset_data()
{
    if (stulist.size()==0)
    {
        cout<<"û�м�¼"<<endl;
        return;
    }
    bool found;
    while (1)
    {
        found=false;
        cout<<"�޸ļ�¼"<<endl;
        cout<<"1-��ѧ�Ų�ѯ 2-��������ѯ 3-�����β�ѯ 0-����"<<endl;
        cout<<"������ָ����룺";
        int id;
        cin>>id;
        if (id==0) break;
        else if (id==1)
        {
            int num;
            cout<<"������ѧ�ţ�";
            cin>>num;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->number==num)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 2-��һ����Ϣ 0-���أ���";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 2-��һ����Ϣ 0-���أ���";
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
            cout<<"������������";
            cin>>name;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (strcmp(it->name,name)==0)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 0-���أ���";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 2-��һ����Ϣ 0-���أ���";
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
            cout<<"���������Σ�";
            cin>>rank;
            for (it=stulist.begin();it!=stulist.end();it=it->next)
            {
                if (it->rank==rank)
                {
                    found=true;
                    it->output();
                    cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 0-���أ���";
                    int id;
                    while (cin>>id)
                    {
                        if (id!=1&&id!=2&&id!=0)
                        {
                            cout<<"����������������룡"<<endl;
                            cout<<"�Ƿ�Ҫ�޸ĸ�����Ϣ����1-�� 2-��һ����Ϣ 0-���أ���";
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
            cout<<"���벻��ȷ����������"<<endl;
            continue;
        }
        if (!found)
        {
            cout<<"�޸ĵ���Ϣ��������"<<endl;
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
    cout<<"����µ�ѧ����Ϣ"<<endl;
    cout<<"ѧ�ţ�";
    cin>>dat.number;
    cout<<"������";
    cin>>dat.name;
    cout<<"�Ա�(0-�� 1-Ů 2-����)��";
    cin>>dat.sex;
    cout<<"�����ɼ���";
    cin>>dat.math;
    cout<<"Ӣ��ɼ���";
    cin>>dat.english;
    cout<<"C++�ɼ���";
    cin>>dat.cpp;
    cout<<"����ɼ���";
    cin>>dat.physics;
    cout<<"��·�ɼ���";
    cin>>dat.circuit;
    dat.adjust();
    stulist.push_back(dat);
    adjust_list();
    cout<<"ѧ��"<<dat.name<<"����Ϣ��½���"<<endl;
    savedTag=false;
}

void show_data()
{
    if (stulist.size()==0)
    {
        cout<<"���ݿ�����ѧ����Ϣ"<<endl;
        return;
    }
    cout<<"ѧ��������"<<stulist.size()<<endl;
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        it->output();
    }
    cout<<"ѧ����Ϣչʾ���"<<endl;
}

void save_file()
{
    int id;
    do
    {
        cout<<"1������  2�����Ϊ  0������"<<endl;
        cout<<"������ģʽ���룺";
        cin>>id;
        if (id!=1&&id!=2&&id!=0) cout<<"�����������������"<<endl;
    }while (id!=1&&id!=2&&id!=0);
    if (id==0) return;
    if (id==2||filename[0]=='\0')
    {
        cout<<"�����뱣���ļ�����";
        cin>>filename;
    }
    fout.open(filename,ios_base::out|ios_base::trunc);
    fout<<stulist.size()<<endl;
    for (it=stulist.begin();it!=stulist.end();it=it->next)
    {
        fout<<(*it);
    }
    fout.close();
    cout<<"�ļ��������"<<endl;
    savedTag=true;
}

bool load_file()
{
    cout<<"�Ӽ�¼�ļ���ȡѧ����Ϣ"<<endl;
    cout<<"������Ҫ��ȡ���ļ�����";
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
    cout<<"ѧ����Ϣ��ȡ���"<<endl;
    savedTag=true;
    return true;
}

void create_file()
{
    cout<<"�½�ѧ����Ϣ�ļ�"<<endl;
    cout<<"�������ļ���";
    cin>>filename;
    fout.open(filename,ios_base::out|ios_base::trunc);
    fout.close();
    cout<<"ѧ����Ϣ�ļ�"<<filename<<"�������"<<endl;
}

bool index()
{
    int id;
    cout<<"1������ѧ����Ϣ\n2���޸�ѧ����Ϣ\n"
        "3����ʾѧ����Ϣ\n4����ѯѧ����Ϣ\n"
        "5��ɾ��ѧ����Ϣ\n6����ѧ����Ϣ��������\n"
        "7������ѧ����Ϣ����¼�ļ�\n8���Ӽ�¼�ļ���ȡѧ����Ϣ\n"
        "9���½�ѧ����Ϣ�ļ�\n10�����н���\n";
    if (filename[0]=='\0') cout<<"��ǰû�д򿪵�ѧ����Ϣ�ļ�"<<endl;
    else
    {
        cout<<"��ǰ�򿪵�ѧ����Ϣ�ļ�Ϊ"<<filename<<endl;
        if (!savedTag) cout<<"��ǰ��Ϣδ����"<<endl;
    }
    cout<<"������ָ�����: ";
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
        if ( !load_file() ) cout<<"�����ļ��������ڣ�"<<endl;
        break;
    case 9:
        create_file();
        break;
    case 10:
        return false;
    default:
        cout<<"�����ָ�����������"<<endl;
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
