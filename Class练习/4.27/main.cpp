#include <iostream>
#include <string>

using namespace std;

class student{
    public:
        student();
        student(int _num,string _name,int _grade);
        void print();
        void set_student(int _num,string _name,int _grade);
    private:
        int num;
        string name;
        int grade;
        static int number;
        static int sumgrade ;
};

int student::number=0;
int student::sumgrade=0;

student::student()
{
    num=0;
    name="NULL";
    grade=0;
}

student::student(int _num,string _name,int _grade)
{
    num=_num;
    name=_name;
    grade=_grade;
    number++;
    sumgrade+=grade;
}
void student::set_student(int _num,string _name,int _grade)
{
    sumgrade-=grade;
    num=_num;
    name=_name;
    grade=_grade;
    sumgrade+=grade;
}
void student::print()
{
    cout<<"学号 "<<num<<endl;
    cout<<"姓名 "<<name<<endl;
    cout<<"成绩 "<<grade<<endl;
    cout<<"学生人数 "<<number<<endl;
    cout<<"平均成绩 "<<double(sumgrade)/double(number)<<endl;
}

int main()
{
    student obj[2]={ {20124563,"cyendra",100},{20120000,"9cw",99} };
    obj[0].print();
    obj[1].print();
    return 0;
}
