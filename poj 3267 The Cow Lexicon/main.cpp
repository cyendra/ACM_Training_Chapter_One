#include <iostream>
#include <string>

using namespace std;

int w,l;
string msg;
string dict[700];
int f[1111]; //f[i]��ʾ��i��l��ɾ�����ַ���

int main()
{
    while (cin>>w>>l)
    {
        cin>>msg;
        for (int i=0;i<w;i++)
        {
            cin>>dict[i];
        }
        f[l]=0;
        for (int i=l-1;i>=0;i--)
        {
            f[i]=f[i+1]+1;//������
            for (int j=0;j<w;j++)//ö�ٵ���
            {
                int len=dict[j].length();
                if ( len<=l-i && dict[j][0]==msg[i] )
                {
                    int pm=i;//msg��ָ��
                    int pd=0;//���ʵ�ָ��
                    while (pm<l)
                    {
                        if ( dict[j][pd]==msg[pm] )
                        {
                            pd++;
                        }
                        pm++;
                        if ( pd==len ) //msg�͵��ʿ���ƥ��ʱ
                        {
                            f[i]=min( f[i] , f[pm]+(pm-i)-len );
                            break;
                        }
                    }
                }
            }
        }
        cout<<f[0]<<endl;
    }
    return 0;
}
