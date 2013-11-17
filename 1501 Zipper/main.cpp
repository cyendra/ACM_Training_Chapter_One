/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


typedef struct{
    int x;
    int y;
}HP;
int T;
bool f[211][211];
bool ok;
char a[211],b[211],c[422];
queue<HP>que;

int main()
{
    scanf("%d",&T);
    for (int loop=1;loop<=T;loop++)
    {
        //cin >> a >> b >> c;
        scanf("%s%s%s",a,b,c);

        if ( strlen(a)+strlen(b)!=strlen(c) )
        {
            cout << "Data set "<<loop<<": no"<<endl;
            continue;
        }

        while (!que.empty())
        {
            que.pop();
        }
        HP p,tmp;
        p.x=0;
        p.y=0;
        que.push(p);
        ok=false;

        while (!que.empty())
        {
            tmp=que.front();
            que.pop();
            if (tmp.x==strlen(a) && tmp.y==strlen(b))
            {
                ok=true;
                break;
            }
            if ( tmp.x>strlen(a) || tmp.y>strlen(b) )
            {
                continue;
            }
            if ( tmp.x<=strlen(a) && a[tmp.x]==c[tmp.x+tmp.y] )
            {
                p.x=tmp.x+1;
                p.y=tmp.y;
                que.push(p);
            }
            if ( tmp.y<=strlen(b) && b[tmp.y]==c[tmp.x+tmp.y] )
            {
                p.x=tmp.x;
                p.y=tmp.y+1;
                que.push(p);
            }
        }

        if (ok==true)
        {
            cout << "Data set "<<loop<<": yes"<<endl;
        }
        else
        {
            cout << "Data set "<<loop<<": no"<<endl;
        }

    }
    return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
string s1, s2, s3;             //˵���˾���ǰi,ǰj��������Ѿ�Ū���˲���Ҫ�ٴ��ظ�
int prove = 0, hash[201][201]; //hash[i][j],��¼����s1ǰi����s2ǰj���ַ��Ƚ��˵�״̬��
void DFS(int count, int n1, int n2)
{
    if(count == s3.size())
    {
        cout << "yes" << endl;
        prove = 1;
        return ;
    }
    if(hash[n1][n2])  //�����ǰ״̬�Ѽ�¼��������
        return ;
    hash[n1][n2] = 1; //��¼��ǰ״̬
    if(!prove && n1 < s1.size() && s3[count] == s1[n1])   //��ס!prove����ֹ������
        DFS(count + 1, n1 + 1, n2);
    if(!prove && n2 < s2.size() && s3[count] == s2[n2])
        DFS(count + 1, n1, n2 + 1);
}
int main()
{
    int i = 1, n;
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2 >> s3;

        cout << "Data set " << i++ << ": ";

        if(s1.size() + s2.size() != s3.size())
        {    cout << "no" << endl;
            continue;
        }
        prove = 0;
        memset(hash, 0, sizeof(hash)); //��סҪ��ʼ��
        DFS(0, 0, 0);
        if(prove == 0)
            cout << "no" << endl;
    }
    return 0;
}
