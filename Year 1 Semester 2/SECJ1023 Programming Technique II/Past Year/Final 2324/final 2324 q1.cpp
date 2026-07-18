// Programming Technique II (SECSJ1023)
// Semester 2, 2023/2024

// Final Exam (Practical - Question 1)

// Student's Name:.....................
// Matric Number:.....................


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Department
{
private:
    string name;
    string faculty;
public:
    Department() { name = faculty = ""; }
    string getName() const { return name; }
    void setName(string n) { name = n; }
    string getFaculty() const { return faculty; }
    void setFaculty(string f) { faculty = f; }
};

class Person
{
protected:
    string name;
    Department dep;

public:
    string getName() const { return name; }
    // ! Task d(i) - constructor
    Person(string n="", string d="", string f=""){
    	name = n;
    	dep.setName(d);
    	dep.setFaculty(f);
	}
    //! Task d(ii) - getDepartment
    Department getDepartment(){
    	return dep;
	}
};

class Lecturer : public Person
{
protected:
    string position;
public:
    string getPosition() const { return position; }
    // ! Task e(i) - constructor
    Lecturer(string n="", string d="", string f="", string p="") : Person(n, d, f){
    	position = p;
	}
    // ! Task e(ii) - getFaculty
    string getFaculty(){
    	return dep.getFaculty();
	}
};

class Course
{
private:
    string code;
    Lecturer *lect;

public:
    void setCode(string c) { code = c; }
    string getCode() const { return code; }
    // ! Task f(i) - constructor
    Course(string c=""){
    	code = c;
    	lect = NULL;
	}
    // ! Task f(ii) - setLecturer
    void setLecturer(Lecturer *l){
    	lect = l;
	}
    // ! Task f(iii) - hasLecturer
    bool hasLecturer(){
    	if(lect == NULL) return false;
    	return true;
	}
    // ! Task f(iv) - getLecturerName
    string getLecturerName(){
    	if(lect == NULL) return "";
    	return lect->getName();
	}
};

class TeachingAssistant : public Person
{
protected:
    int maxHour;
    Course *course;

public:
    double getMaxClaim() const { return maxHour * 8.0; }
    TeachingAssistant(string n) {
    	name=n;
        maxHour=80 ;
    }
};

string courseCodeToName(string code);

int main()
{
    //!Task g: rewrite the main function using vector instead of regular array, including iteration
	try{
		const int count = 4;
		vector <Course> courses;
		courses.push_back(Course("SECJ1013"));
		courses.push_back(Course("SECJ1023"));
		courses.push_back(Course("SECJ3623"));
		courses.push_back(Course("SECV3032"));
		
		for (int i = 0; i < count; i++){
			cout << courses.at(i).getCode() << " " << courseCodeToName(courses.at(i).getCode()) << endl;
		}	
	}
	catch(out_of_range &e){
		cout << "\nCode not found. Error: " << e.what();
	}
    return 0;
};


//!Task h: rewrite the method using map
string courseCodeToName(string code)
{
	map <string, string> course;
	course.insert({"SECJ1013", "Programming Technique I"});
	course.insert({"SECJ1023", "Programming Technique II"});
	course.insert({"SECJ3623", "Mobile Application Programming"});
	return course.at(code);
}