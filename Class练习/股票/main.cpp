#include <iostream>

using namespace std;

class shen_stock{
    public:
        shen_stock(int a,int b,int c);
        friend int sum(shen_stock & shen);
        friend shang_stock;
        int count();
    private:
        int general;
        int st;
        int pt;
};

int shen_stock::count()
{
    int sumshen=this.general+this.st+this.pt;
    int sumshang=s
}

shen_stock::shen_stock(int a,int b,int c)
{
    general=a;
    st=b;
    pt=c;
}

int sum(shen_stock & shen)
{
    return shen.general+shen.st+shen.pt;
}


class shang_stock{
    public:
        shang_stock(int a,int b,int c);
        friend int sum(shang_stock & shang);
        friend shen_stock;
    private:
        int general;
        int st;
        int pt;
};

shang_stock::shang_stock(int a,int b,int c)
{
    general=a;
    st=b;
    pt=c;
}

int sum(shang_stock & shang)
{
    return shang.general+shang.st+shang.pt;
}

int main()
{

    return 0;
}
