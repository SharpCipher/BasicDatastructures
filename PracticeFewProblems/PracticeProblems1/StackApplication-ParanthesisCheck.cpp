#include<bits/stdc++.h>

using namespace std;

bool checkBalancedParanthesis(string ptr){

  int n = ptr.length();
  stack<char> S;

  for(int i=0;i<n;i++){
    if(ptr[i] == '(' || ptr[i] == '{' || ptr[i] == '['){
      S.push(ptr[i]);
    }
    else if( (ptr[i] == ')' && S.top() == '(') || (ptr[i] == '}' && S.top() == '{') || (ptr[i] == ']' && S.top() == '[') ){
        if(!S.empty()){
          S.pop();
        }
    }
  }
  if(S.empty())
  {
    return true;
  }
  else{
    return false;
  }
}
int main(){
  string ptr;
  getline(cin, ptr);
  if(!ptr.empty()) //String/Expression is not empty
    cout<<checkBalancedParanthesis(ptr)<<endl;
  return 0;
}
