#include <iostream>
#include <string>

using namespace std;

/*
char str[100100];
char rev[100100];
char as[200];
char bs[200];
*/

string str,rev,as,bs;

bool ab,ba;
int a,b;

int main()
{
    cin >> str;
    cin >> as;
    cin >> bs;
    ab=false;
    ba=false;
    a=str.find(as);
    b=str.rfind(bs);
    if ( a<b && a!=-1 && b!=-1 && a+as.length()<=b  ) ab=true;

    //cout<< a << " "<<b<< " " << a+as.length()<< endl;

    rev=str;
    for (int i=0;i<rev.length();i++)
    {
        rev[i]=str[ str.length()-i-1 ];
    }

    a=rev.find(as);
    b=rev.rfind(bs);
    if ( a<b && a!=-1 && b!=-1 && a+as.length()<=b  ) ba=true;


    //cout << rev << endl;
/*
    a=str.rfind(as);1
    b=str.find(bs);
    if ( a>b && a!=-1 && b!=-1 && b+bs.length()<=a ) ba=true;
*/
    //cout<< a << " "<<b<< " " <<  b+bs.length() <<endl;

    if ( ab==true && ba==true )
    {
        cout << "both" << endl;
    }
    else if ( ab==true && ba!=true )
    {
        cout << "forward" << endl;
    }
    else if ( ab!=true && ba==true )
    {
        cout << "backward" << endl;
    }
    else if ( ab!=true && ba!=true )
    {
        cout << "fantasy" << endl;
    }

    return 0;
}
