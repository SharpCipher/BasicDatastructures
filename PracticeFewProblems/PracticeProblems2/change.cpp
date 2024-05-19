/*The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.

Input Format. The input consists of a single integer 𝑚.
Constraints. 1 ≤ 𝑚 ≤ 10 3 .
Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
*/

#include <iostream>

int total_count = 0;

int get_change(int m) {
  //write your code here
  int d;
  if(m <= 4)
    total_count = m;

  else if(m == 10 || m == 5){
    total_count = 1;
  }

  else if(m > 5 && m < 10){
      total_count = (m%5)+1;

  }

  else{
    
    int t = m;
    m = m/10;
    d = t%10;

    if(d < 5){
      total_count = m + d;
    }
    else if(d > 5){
      total_count = m + d%5 + 1;
    }
    else if(d == 5){
      total_count = m + 1;
    }
    
  }

  return total_count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
