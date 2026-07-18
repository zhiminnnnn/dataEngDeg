#include <iostream>
using namespace std;

//Program 7.1
class Faculty{
	protected:
		string facName;
		string buildingNo;
	public:
		Faculty(string, string);
};

Faculty::Faculty(string facName, string buildingNo){
	this->facName=facName;
	this->buildingNo=buildingNo;
}

class Student{
	protected:
		string name;
 	public:
		Student(string name){
			this->name=name;
		}
};

class TeachingAssistant : public Faculty, public Student{
	private:
		string course;
	public:
		TeachingAssistant(string c, string f, string b, string n)
		: Faculty(f, b), Student(n){
			course = c;
		}
}; 