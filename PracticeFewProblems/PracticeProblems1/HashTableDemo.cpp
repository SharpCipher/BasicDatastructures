#include <iostream>

using namespace std;

int Frequency[26];

int hashFunction(char c){
	return (c-'a');			
}

void countFreq(string s){
	for(int i=0; i<s.length(); i++){
		int index = hashFunction(s[i]); //returns the index where this value/char goes into the hash table
		Frequency[index]++;
	}
	for(int i=0; i<26; i++){
		cout << (char)(i+'a') <<" "<< Frequency[i] << endl;
	}
}

int main(){
	
	string s;
	getline(cin,s);
	countFreq(s);
	
	return 0;
}
