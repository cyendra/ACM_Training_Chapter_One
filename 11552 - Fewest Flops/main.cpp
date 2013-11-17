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

//����h���ַ����е��ظ���ĸɾ������������s[h]��
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

//����l-1���ַ���l��ĵ�i���ַ���λ�ã����������򷵻�-1
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
        n=strlen(str)/k;//��������
        for (int i=0;i<n;i++) judge(i,i*k,(i+1)*k,str);//���鲢�����ظ��ַ�
        //DP  f[l][i][j]��ʾ��l���Ե�i���ַ���ͷ�Ե�j���ַ���βʱǰl�����С����
        for (int l=0;l<n;l++)
            for (int i=0;i<strlen(s[l]);i++)
                for (int j=0;j<strlen(s[l]);j++)
                {
                    f[l][i][j]=INF;//��ʼ��f[l][i][j]
                    if (i!=j||strlen(s[l])==1)//��ͷ�ַ�i���ܵ��ڽ�β�ַ�j����l��ֻ��һ����
                    {
                        if (l==0) f[l][i][j]=strlen(s[l]);//��lΪ��һ�飬���ַ�����Ϊ��С����
                        else
                        {
                            int tmp,ret;
                            ret=fin(l,i);//�ҵ�l-1������s[l][i]��ͬ���ַ�λ��
                            if (ret>=0)//�ҵ��������
                            {
                                tmp=INF;
                                for (int g=0;g<strlen(s[l-1]);g++)//Ѱ����s[l-1][g]Ϊ����ĸ
                                    tmp=min(tmp,f[l-1][g][ret]);//s[l-1][ret]Ϊβ��ĸʱǰl-1�����С����
                                f[l][i][j]=tmp+strlen(s[l])-1;//ǰl-1�����С����+l��Ŀ���-�ظ��Ŀ���1
                            }
                            tmp=INF;
                            for (int p=0;p<strlen(s[l-1]);p++)//ö��l-1������ĸ
                                for (int q=0;q<strlen(s[l-1]);q++)//ö��β��ĸ
                                    tmp=min(tmp,f[l-1][p][q]);//Ѱ����Сֵ
                            f[l][i][j]=min(f[l][i][j],tmp+(int)strlen(s[l]));//ǰl-1�����С����+l��Ŀ���
                        }
                    }
                }
        int ans=INF;
        for (int i=0;i<strlen(s[n-1]);i++)
            for (int j=0;j<strlen(s[n-1]);j++)
                ans=min(ans,f[n-1][i][j]);//Ѱ����Ѵ�
        printf("%d\n",ans);
    }
    return 0;
}
