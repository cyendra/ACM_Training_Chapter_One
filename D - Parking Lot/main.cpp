#include <iostream>
#include <cstring>

using namespace std;

struct CAR{
    int bg;//���������
    int len;//���ĳ���
    int num;//����
};

CAR a[111];

int carnum;

int l,b,f;// l-ͣ�������� b-f-ͣ������
int n;
int type,code;
bool flag;

int main()
{
    memset(a,0,sizeof(a));
    cin>>l>>b>>f;
    cin>>n;
    carnum=1;
    a[1].bg=l+f;//���һ���������Ϊ���
    a[0].bg=-b;//��ʼ����0������ʹ��1������ͣ��0λ��
    for (int i=1;i<=n;i++)
    {
        cin>>type>>code;//����ָ������type��ֵcode
        if (type==1)//ͣ�������
        {
            flag=true;//δ�ɹ�ͣ�����
            for (int j=0;j<carnum;j++)//��ͷö�ٳ���λ��
            {
                if ( a[j+1].bg-(a[j].bg+a[j].len)>=f+b+code )//��j�������j+1����֮���������³���Ϊcode�ĳ�
                {
                    for (int k=carnum;k>=j+1;k--)
                    {
                        a[k+1]=a[k];//��j+1��carnum�ĳ�ȫ�������һλ
                    }
                    carnum++;//������+1
                    j++;//�µĳ���ͣ��λ��j
                    a[j].bg=a[j-1].bg+a[j-1].len+b;//�����ܵĿ�ǰͣ
                    a[j].len=code;//����Ϊcode
                    a[j].num=i;//���Ϊi?
                    cout<<a[j].bg<<endl;//������
                    flag=false;//ͣ���ɹ�
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
