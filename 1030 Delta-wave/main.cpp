#include <iostream>
#include <cmath>
using namespace std;
inline int Row(int num)//��������������
{return static_cast<int>(sqrt(static_cast<double>(num-1)))+1;}
inline int Mid(int row)//��row�е����ĵ���
{return ((row-1)*(row-1)+1+row*row)/2;}
inline bool CanLeft(int num,int row)//�ܲ�������
{return num>((row-1)*(row-1)+1);}
inline bool CanRight(int num,int row)//�ܲ�������
{return num<(row*row);}
inline bool CanDown(int num,int row)//�ܲ�������
{return (num%2==row%2);}
int OffSet(int num,int row) //numƫ��row�����ĵĴ�С
{return num-Mid(row);}
int main()
{
    int M,N,rowM,rowN,diffM,diffN,m,n,steps;
    while(cin>>M>>N)
    {
        if(M>N) swap(M,N); //��֤M<N
        rowM = Row(M);
        rowN = Row(N);
        if(rowM==rowN) //ͬһ����
        {cout<<N-M<<endl;continue;}
        diffN = OffSet(N,rowN);
        m=M;n=N;
        steps = 0;
        while(m!=n)
        {
            rowM = Row(m);
            if(rowM==rowN){steps += abs(m-n);break;}//����ͬһ��
            diffM = OffSet(m,rowM);
            if(CanDown(m,rowM)) {m=Mid(rowM+1)+diffM; ++steps;}
            else if(diffM<diffN) //Ŀ�����ڵ�ǰm���Ҳ�
            {
                if(CanRight(m,rowM)){m+=1;++steps;}
                else {m-=1;++steps;}
            }
            else if(diffM>diffN)//Ŀ�����ڵ�ǰm�����
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
