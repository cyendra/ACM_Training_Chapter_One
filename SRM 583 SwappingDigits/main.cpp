#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class SwappingDigits{
    private:
    public:
        string minNumber(string num)
        {
            int n=num.length();
            int p;
            for (int i=0;i<n;i++)
            {
                p=i;
                for (int j=n-1;j>i;j--)
                    if (num[j]<num[p]&&(i!=0||num[j]!='0')) p=j;
                if (p!=i){
                    swap(num[i],num[p]);
                    break;
                }
            }
            return num;
        }
};

int main()
{
    string s;
    SwappingDigits f;
    cin>>s;
    cout<<f.minNumber(s)<<endl;
    return 0;
}
