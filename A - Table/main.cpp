#include <iostream>

using namespace std;

int n,m,k;

int main()
{
    cin>>n>>m>>k;
    cout<<(k-1)/n+(k-1)%n*m+1<<endl;

    return 0;
}


/*

 scan [gets stdin] {%d %d %d} n m k
puts [expr ($k-1)/$n + ($k-1)%$n*$m+1]
*/
