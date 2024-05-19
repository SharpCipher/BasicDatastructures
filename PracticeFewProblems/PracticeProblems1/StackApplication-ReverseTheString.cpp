#include<bits/stdc++.h>

using namespace std;

void Reverse(char c[], int n){
  stack<char> S;

  for(int i=0;i<n;i++){  //O(n)
    S.push(c[i]);
  }
  for(int i=0;i<n;i++){ //O(n)
    c[i] = S.top();
    S.pop();
  }
}
int main(){
  char c[51];
  cout<<"Enter a String: "<<endl;
  cin.getline(c, 20);
  Reverse(c, strlen(c));
  cout<<c<<endl;
  return 0;
}

//Space-Complexity is Proportional to n(input): O(n) + Implicit Stack(System Stack) takes O(n)
