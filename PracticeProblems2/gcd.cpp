#include <iostream>
using namespace std;
/*int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}*/

long int gcd_fun(long int a, long int b){
  if(b == 0)
    return a;
  else{
    return gcd_fun(b, a%b);
  }
}
int main() {
  long int a, b;
  cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  cout<<gcd_fun(a, b)<<endl;

  return 0;
}
