#include <iostream>
#include <string>

using namespace std;

int w,l;
string msg;
string dict[700];
int f[1111]; //f[i]表示从i到l所删除的字符数

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
            f[i]=f[i+1]+1;//最坏的情况
            for (int j=0;j<w;j++)//枚举单词
            {
                int len=dict[j].length();
                if ( len<=l-i && dict[j][0]==msg[i] )
                {
                    int pm=i;//msg的指针
                    int pd=0;//单词的指针
                    while (pm<l)
                    {
                        if ( dict[j][pd]==msg[pm] )
                        {
                            pd++;
                        }
                        pm++;
                        if ( pd==len ) //msg和单词可以匹配时
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
