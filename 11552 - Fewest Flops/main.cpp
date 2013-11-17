#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF=1e9;
const int maxn=1111;
const int maxc=33;

int f[maxn][maxc][maxc];
char s[maxn][maxn];

//将第h组字符串中的重复字母删除并存入数组s[h]中
void judge(int h,int i,int j,char* str)
{
    bool hash[maxc]={0};
    int ln=0;
    for (int k=i;k<j;k++)
        if (!hash[str[k]-'a']){
            hash[str[k]-'a']=true;
            s[h][ln++]=str[k];
        }
    s[h][ln]='\0';
}

//查找l-1组字符中l组的第i个字符的位置，若不含有则返回-1
int fin(int l,int i)
{
    for (int j=0;j<strlen(s[l-1]);j++)
        if (s[l][i]==s[l-1][j]) return j;
    return -1;
}

int main()
{
    int T,k,n;
    char str[maxn];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%s",&k,str);
        n=strlen(str)/k;//计算组数
        for (int i=0;i<n;i++) judge(i,i*k,(i+1)*k,str);//分组并消除重复字符
        //DP  f[l][i][j]表示第l组以第i个字符开头以第j个字符结尾时前l组的最小块数
        for (int l=0;l<n;l++)
            for (int i=0;i<strlen(s[l]);i++)
                for (int j=0;j<strlen(s[l]);j++)
                {
                    f[l][i][j]=INF;//初始化f[l][i][j]
                    if (i!=j||strlen(s[l])==1)//开头字符i不能等于结尾字符j除非l组只有一个块
                    {
                        if (l==0) f[l][i][j]=strlen(s[l]);//若l为第一组，则字符数即为最小块数
                        else
                        {
                            int tmp,ret;
                            ret=fin(l,i);//找到l-1组中与s[l][i]相同的字符位置
                            if (ret>=0)//找到的情况下
                            {
                                tmp=INF;
                                for (int g=0;g<strlen(s[l-1]);g++)//寻找以s[l-1][g]为首字母
                                    tmp=min(tmp,f[l-1][g][ret]);//s[l-1][ret]为尾字母时前l-1组的最小块数
                                f[l][i][j]=tmp+strlen(s[l])-1;//前l-1组的最小块数+l组的块数-重复的块数1
                            }
                            tmp=INF;
                            for (int p=0;p<strlen(s[l-1]);p++)//枚举l-1组首字母
                                for (int q=0;q<strlen(s[l-1]);q++)//枚举尾字母
                                    tmp=min(tmp,f[l-1][p][q]);//寻找最小值
                            f[l][i][j]=min(f[l][i][j],tmp+(int)strlen(s[l]));//前l-1组的最小块数+l组的块数
                        }
                    }
                }
        int ans=INF;
        for (int i=0;i<strlen(s[n-1]);i++)
            for (int j=0;j<strlen(s[n-1]);j++)
                ans=min(ans,f[n-1][i][j]);//寻找最佳答案
        printf("%d\n",ans);
    }
    return 0;
}
