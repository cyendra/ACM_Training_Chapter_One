
#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    long long int digit;
    int n,m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        digit=(long long int)(n*log10(n))+1;//n^n��λ�� ������+1
        int left=pow(10.0,(n*log10(n)-digit+1));//n^n/10^(digit-1)�Ľ����������ߵ�����~
        cout<<left<<endl;
    }
    return 0;
}
io
