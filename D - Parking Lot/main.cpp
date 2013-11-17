#include <iostream>
#include <cstring>

using namespace std;

struct CAR{
    int bg;//汽车的起点
    int len;//车的长度
    int num;//车号
};

CAR a[111];

int carnum;

int l,b,f;// l-停车场长度 b-f-停车限制
int n;
int type,code;
bool flag;

int main()
{
    memset(a,0,sizeof(a));
    cin>>l>>b>>f;
    cin>>n;
    carnum=1;
    a[1].bg=l+f;//最后一辆车的起点为最后
    a[0].bg=-b;//初始化第0辆车，使第1辆车能停在0位置
    for (int i=1;i<=n;i++)
    {
        cin>>type>>code;//读入指令种类type和值code
        if (type==1)//停车的情况
        {
            flag=true;//未成功停车标记
            for (int j=0;j<carnum;j++)//从头枚举车量位置
            {
                if ( a[j+1].bg-(a[j].bg+a[j].len)>=f+b+code )//第j辆车与第j+1辆车之间能容纳下长度为code的车
                {
                    for (int k=carnum;k>=j+1;k--)
                    {
                        a[k+1]=a[k];//将j+1至carnum的车全部向后移一位
                    }
                    carnum++;//车辆数+1
                    j++;//新的车将停在位置j
                    a[j].bg=a[j-1].bg+a[j-1].len+b;//尽可能的靠前停
                    a[j].len=code;//车长为code
                    a[j].num=i;//编号为i?
                    cout<<a[j].bg<<endl;//输出起点
                    flag=false;//停车成功
                    break;
                }
            }
            if (flag) cout<<"-1"<<endl;
        }
        else if (type==2)
        {
            for (int j=1;j<carnum;j++)
            {
                if ( a[j].num==code )
                {
                    for (int k=j;k<carnum;k++)
                    {
                        a[k]=a[k+1];
                    }
                    carnum--;
                    break;
                }
            }
        }
    }
    return 0;
}
