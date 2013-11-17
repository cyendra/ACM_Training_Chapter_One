#include <iostream>

using namespace std;

char arr[4][4];

int main()
{
    int a,b;
    int wina,winb;
    a=b=wina=winb=0;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin>>arr[i][j];
            if ( arr[i][j]=='X' )a++;
            if ( arr[i][j]=='0' )b++;
        }
    }
    if ( a<b||a-b>1 )
    {
        cout<<"illegal"<<endl;
    }
    else
    {
        for (int i=0;i<3;i++)
        {
            if ( arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2] )
            {
                if ( arr[i][0]=='X' ) wina++;
                if ( arr[i][0]=='0' ) winb++;
            }
            if ( arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i] )
            {
                if ( arr[0][i]=='X' ) wina++;
                if ( arr[0][i]=='0' ) winb++;
            }
        }
        if ( arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2] )
        {
            if ( arr[0][0]=='X' ) wina++;
            if ( arr[0][0]=='0' ) winb++;
        }
        if ( arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0] )
        {
            if ( arr[1][1]=='X' ) wina++;
            if ( arr[1][1]=='0' ) winb++;
        }
        if ( wina>=1&&winb>=1 )
        {
            cout<<"illegal"<<endl;
        }
        else if ( (wina==1||wina==2) &&winb==0 )
        {
            if (a>b)
            {
                cout<<"the first player won"<<endl;
            }
            else
            {
                cout<<"illegal"<<endl;
            }
        }
        else if ( wina==0&&(winb==1||winb==2) )
        {
            if (a==b)
            {
                cout<<"the second player won"<<endl;
            }
            else
            {
                cout<<"illegal"<<endl;
            }
        }
        else if ( wina==0&&winb==0 )
        {
            if (a+b==9)
            {
                cout<<"draw"<<endl;
            }
            else if ( a==b )
            {
                cout<<"first"<<endl;
            }
            else
            {
                cout<<"second"<<endl;
            }
        }
    }
    return 0;
}
