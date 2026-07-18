#include <iostream>
using namespace std;

class Student{
	private:
		string studName;
		int studId;
};

class Professor{
	private:
		int numOfTeaching;
		string profName;
	public:
		Professor(string p=""){
			profName = p;
			numOfTeaching = 0;
		}
		string display(){
			return profName;
		}
		~Professor(){}
};

class College{
	private:
		string name;
		Professor *prof;
		Student stud;
	public:
		College(string n="", Professor *p = NULL){
			name = n;
			prof = p;
		}
		~College(){}
};