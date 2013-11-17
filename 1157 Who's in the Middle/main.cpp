#include <iostream>
#include <algorithm>
using namespace std;

int cow[10001];

int main()
{
    int n,mid;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin >> cow[i];
        }
        sort(cow,cow+n);
        mid=n/2;
        cout << cow[mid] << endl;
    }
    return 0;
}
