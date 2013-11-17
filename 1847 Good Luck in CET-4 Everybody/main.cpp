#include <iostream>
#include <cstring>

using namespace std;

int list[11]={1,2,4,8,16,32,64,128,256,512,1024};
int SG[1010]={0};
int k[1010]={0};

void mex();

void mex()
{
    for (int i=0;i<=1000;i++)
    {
        memset(k,0,sizeof(k));
        for (int j=0;j<=10;j++)
        {
            if (list[j]>i) break;
            k[SG[i-list[j]]]=1;
        }
        int j=0;
        while (k[j]) j++;
        SG[i]=j;
    }

}

int main()
{
    int n;
    mex();
    while (cin>>n)
    {
        if (SG[n]==0)
        {
            cout<<"Cici"<<endl;
        }
        else
        {
            cout<<"Kiki"<<endl;
        }
    }
    return 0;
}
