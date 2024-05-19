#include<iostream>
using namespace std;
int gcd(long int a, long int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main() {
   long int a,b;
   cin>>a>>b;
   cout<< (a*b)/gcd(a, b);
   return 0;
}