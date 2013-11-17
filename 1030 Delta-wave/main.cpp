#include <iostream>
#include <cmath>
using namespace std;
inline int Row(int num)//根据数字求行数
{return static_cast<int>(sqrt(static_cast<double>(num-1)))+1;}
inline int Mid(int row)//第row行的中心的数
{return ((row-1)*(row-1)+1+row*row)/2;}
inline bool CanLeft(int num,int row)//能不能往左
{return num>((row-1)*(row-1)+1);}
inline bool CanRight(int num,int row)//能不能往右
{return num<(row*row);}
inline bool CanDown(int num,int row)//能不能往下
{return (num%2==row%2);}
int OffSet(int num,int row) //num偏离row行中心的大小
{return num-Mid(row);}
int main()
{
    int M,N,rowM,rowN,diffM,diffN,m,n,steps;
    while(cin>>M>>N)
    {
        if(M>N) swap(M,N); //保证M<N
        rowM = Row(M);
        rowN = Row(N);
        if(rowM==rowN) //同一行了
        {cout<<N-M<<endl;continue;}
        diffN = OffSet(N,rowN);
        m=M;n=N;
        steps = 0;
        while(m!=n)
        {
            rowM = Row(m);
            if(rowM==rowN){steps += abs(m-n);break;}//到达同一行
            diffM = OffSet(m,rowM);
            if(CanDown(m,rowM)) {m=Mid(rowM+1)+diffM; ++steps;}
            else if(diffM<diffN) //目的数在当前m的右侧
            {
                if(CanRight(m,rowM)){m+=1;++steps;}
                else {m-=1;++steps;}
            }
            else if(diffM>diffN)//目的数在当前m的左侧
            {
                if(CanLeft(m,rowM)){m-=1;++steps;}
                else {m+=1;++steps;}
            }
            else//diffM==diffN
            {
                if(CanRight(m,rowM)){m+=1;++steps;}
                else {m-=1;++steps;}
            }
        }
        cout<<steps<<endl;
    }
    return 0;
}
