#include <iostream>
#include <cstdio>
using namespace std;

int p[50000],rank[50000],eat[50000],dead[50000];
int main()
{
    int n,k,x,y,sum,px,py,d,kind;
    scanf("%d%d",&n,&k);
    sum=0;
    for (int i=0;i<=n;i++)
    {
        p[i]=0;
        eat[i]=0;
        dead[i]=0;
        rank[i]=1;
    }
    for (int i=0;i<k;i++)
    {
        scanf("%d%d%d",&d,&x,&y);
        //------------------------------------------
        if (d==1)
        {
            //����Ƿ���
            if ((x>n)or(y>n))
            {
                sum++;
                continue;
            }
            //����Ƿ��Լ����Լ�
            if (x==y)
            {
                continue;
            }
            //Ѱ��xy���ڵ�
            px=x;
            py=y;
            while (p[px]!=0)
            {
                px=p[px];
            }
            while (p[py]!=0)
            {
                py=p[py];
            }
            //����Ƿ���ȷ
           /* if (px==py)
            {
                continue;
            }
           */
            //����Ƿ��߼�����
            if ((eat[px]!=0)and(py==eat[px]))
            {
                sum++;
                continue;
            }
            if ((eat[py]!=0)and(px==eat[py]))
            {
                sum++;
                continue;
            }
            if ((dead[px]!=0)and(py==dead[px]))
            {
                sum++;
                continue;
            }
            if ((dead[py]!=0)and(px==dead[py]))
            {
                sum++;
                continue;
            }
            //���޴���ϲ�xy����
            p[py]=px;
            if (eat[px]!=0)
            {
                p[eat[py]]=eat[px];
            }
            else
            {
                eat[px]=eat[py];
            }
            if (dead[px]!=0)
            {
                p[dead[py]]=dead[px];
            }
            else
            {
                dead[px]=dead[py];
            }

        }
        //++++++++++++++++++++++=
        if (d==2)
        {
            //����Ƿ��Լ����Լ�
            if (x==y)
            {
                sum++;
                continue;
            }
            //Ѱ�Ҹ��ڵ�
            px=x;
            py=y;
            while (p[px]!=0)
            {
                px=p[px];
            }
            while (p[py]!=0)
            {
                py=p[py];
            }
            //����Ƿ���ȷ
            /*
            if ((eat[px]==py)and(dead[py]==px))
            {
                continue;
            }
            */
            //����Ƿ��߼�����
            if ((eat[py]!=0)and(x==eat[py]))
            {
                sum++;
                continue;
            }
            if ((px!=0)and(px==py))
            {
                sum++;
                continue;
            }
            if ((dead[px]!=0)and(dead[px]==py))
            {
                sum++;
                continue;
            }
            //�ϲ�����
            if (eat[px]==0)
            {
                eat[px]=py;
            }
            else
            {
                p[py]=eat[px];
            }
            if (dead[py]==0)
            {
                dead[py]=px;
            }
            else
            {
                p[px]=dead[py];
            }
            if (dead[px]==0)
            {
                dead[px]=eat[py];
            }
            else
            {
                p[eat[py]]=dead[px];
            }
        }
        //------------------------------------------
    }
    printf("%d",sum);
    return 0;
}
