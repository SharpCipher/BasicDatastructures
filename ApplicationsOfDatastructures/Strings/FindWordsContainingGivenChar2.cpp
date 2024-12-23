#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWordsContaining(vector<string>& words, char x) {
        vector<string> result;
        for(int i=0; i<words.size(); i++){
            for(auto& c : words[i]) {
                if(c == x){
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<string> vect;
    vector<string> res;
    char c;
    string str;
    cout<<"Enter the strings in vector line by line:"<<endl;
    for(int i=0; i<5; ++i){
        getline(cin,str);
        vect.push_back(str);
    }
    cout<<"\nEnter the character to search: \n";
    cin>>c;

    Solution s;
    res = s.findWordsContaining(vect, c);

    cout << "Words containing the character " << c << ":\n";
    for(int i=0; i<res.size(); ++i)
        cout<<res[i]<<'\n';

    return 0;
}