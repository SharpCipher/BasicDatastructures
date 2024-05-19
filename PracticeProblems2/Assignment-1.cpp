/*

You are given a text file, named “students.txt” that contains students’ records. Each line
contains information of a single student in the form of <Student Name, Roll No,
Department>.

Read the records from the file into an array of structures.

Successfull Run with the following Data:

Smith   Jack
Harry   Hisk
Kay     Jacob
Dos     hed
Noa     Tom
Joe     Peni
Vin     San
Jes     Dan
Zi      Lee
Angi    Dev
Donald  David
Davis   Lal
Alvis   Sen
Jack    Jill
Messy   Lionel

Code Written By: Bhanuprakash Eagala
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){


	const int No_of_Lines = 25;

	struct Records{
		string studentName;
		string rollNumber;
		string Department;

	}record[No_of_Lines];

	ifstream in("StudentData.txt");

	if(!in){
		cerr<<"File can't be opened!"<<endl;
		system("PAUSE");
		exit(1);
	}
	int i = 0;

	while(!in.eof() && (i < No_of_Lines)){
		in >> record[i].studentName >> record[i].rollNumber >> record[i].Department;
		++i;
	}
	for(int j=0; j<i; j++){
		cout<<record[j].studentName<<" ";
		cout<<record[j].rollNumber<<" ";
		cout<<record[j].Department<<" ";
	}
	cout<<endl;

	return 0;
}