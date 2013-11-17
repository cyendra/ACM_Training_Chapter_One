#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long int64;

void gcd(int64 a , int64 b , int64 &d , int64 &x , int64 &y){
    if(!b){
      d = a;
      x = 1;
      y = 0;
    }
    else{
      gcd(b , a%b , d , y , x);
      y -= x*(a/b);
    }
}

int main(){
   int64 a , b , c , d , x , y;
   while(cin>>a>>b>>c){
        gcd(a , b , d , x , y);
        if(c%d != 0)
          printf("-1\n");
        else{
          int64 tmp = (-c)/d;
          x *= tmp , y *= tmp;
          cout<<x<<" "<<y<<endl;
        }
   }
   return 0;
}

