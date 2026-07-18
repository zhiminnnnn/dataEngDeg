#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//? class Course is fully given
class Course
{
private:
    string name;
    int credit;

public:
    Course(string _name = "", int _credit = 1) : name(_name), credit(_credit) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    int getCredit() const { return credit; }
    void setCredit(int value) { credit = value; }
    void print() const
    {
        cout << "Course: " << name << "   Credit=" << credit << endl;
    }
};

//? the class Student is partially given
class Student
{
private:
    string name, matric;
    vector<Course *> courses;

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    void setMatric(string value) { matric = value; }

    //! Task 1
    void enrollToCourse(Course *c){
    	courses.push_back(c);
	}

    //! Task 2
    int getEnrolledCount() const{
    	return courses.size();
	}

    //! Task 3
    int getTotalCredit() const{
    	int sum=0;
    	for(int i=0; i<courses.size(); i++){
    		sum += courses.at(i)->getCredit();
		}
		return sum;
	}

    //! Task 4
    void printCourses() const{
    	cout << "List of courses enrolled" << endl;
    	cout << "------------------------" << endl;
    	for(int i=0; i<courses.size(); i++){
    		courses.at(i)->print();
		}
	}
    void printSummary() const
    {
        cout << "Name:" << name << endl;
        cout << "Matric:" << matric << endl;
        cout << "Number of courses enrolled:" << getEnrolledCount() << endl;
        cout << "Total credit carried:" << getTotalCredit() << endl;
    }
};

int main()
{
    //! Task 5: create list of courses using vector
	vector <Course> courses(10);
	courses.at(0) = Course("Programming Technique I", 3);
	courses.at(1) = Course("Programming Technique II", 3);
	courses.at(2) = Course("Operating Systems", 3);
	courses.at(3) = Course("Web Programming", 3);
	courses.at(4) = Course("Digital Logic I", 3);
	courses.at(5) = Course("Object-Oriented Programming", 4);
	courses.at(6) = Course("Application Development", 4);
	courses.at(7) = Course("Final Year Project I", 2);
	courses.at(8) = Course("Software Engineering", 3);
	courses.at(9) = Course("Graduate Success Attributes", 2);
	
    //! Task6: create the list of students using map and enroll the student to the courses.
    map <string, Student> students;
    students["A16EC4041"] = Student("Mario Max", "A16EC4041");
    students["A16EC4045"] = Student("Wilma Mumduya", "A16EC4045");
    students["A18EC4056"] = Student("Anna Sthesia", "A18EC4056");
    students["A16EC9043"] = Student("Paul Molive", "A16EC9043");
    students["A19EC4002"] = Student("Anna Mull", "A19EC4002");
    students["A16EC4032"] = Student("Gail Forcewind", "A16EC4032");
    students["A16EC3002"] = Student("Paige Turner", "A16EC3002");
    students["A17EC3003"] = Student("Bob Frapples", "A17EC3003");
    students["A17EC4043"] = Student("Robin Banks", "A17EC4043");
    students["A18EC4044"] = Student("Jimmy Changa", "A18EC4044");
    
    students["A16EC4041"].enrollToCourse(&courses[0]);
    students["A16EC4041"].enrollToCourse(&courses[1]);
    students["A16EC4041"].enrollToCourse(&courses[2]);
    
    students["A16EC4045"].enrollToCourse(&courses[1]);
    students["A16EC4045"].enrollToCourse(&courses[2]);
    students["A16EC4045"].enrollToCourse(&courses[3]);
    
    students["A18EC4056"].enrollToCourse(&courses[2]);
    students["A18EC4056"].enrollToCourse(&courses[3]);
    students["A18EC4056"].enrollToCourse(&courses[4]);
    
    students["A16EC9043"].enrollToCourse(&courses[3]);
    students["A16EC9043"].enrollToCourse(&courses[4]);
    students["A16EC9043"].enrollToCourse(&courses[5]);
    
    students["A19EC4002"].enrollToCourse(&courses[4]);
    students["A19EC4002"].enrollToCourse(&courses[5]);
    students["A19EC4002"].enrollToCourse(&courses[6]);
    
    students["A16EC4032"].enrollToCourse(&courses[5]);
    students["A16EC4032"].enrollToCourse(&courses[6]);
    students["A16EC4032"].enrollToCourse(&courses[7]);
    
    students["A16EC4045"].enrollToCourse(&courses[6]);
    students["A16EC4045"].enrollToCourse(&courses[7]);
    students["A16EC4045"].enrollToCourse(&courses[8]);
    
    students["A17EC3003"].enrollToCourse(&courses[7]);
    students["A17EC3003"].enrollToCourse(&courses[8]);
    students["A17EC3003"].enrollToCourse(&courses[9]);
    
    students["A17EC4043"].enrollToCourse(&courses[0]);
    students["A17EC4043"].enrollToCourse(&courses[8]);
    students["A17EC4043"].enrollToCourse(&courses[9]);
    
    students["A18EC4044"].enrollToCourse(&courses[3]);
    students["A18EC4044"].enrollToCourse(&courses[4]);
    students["A18EC4044"].enrollToCourse(&courses[5]);

    //! Task7: Search for a student and display its information
    string m;
    try{
	    cout << "Enter the matric number=> ";
	    cin >> m;
	    students.at(m);
		cout << "\nInformation of found student" << endl;
		cout << "============================" << endl;
		students.at(m).printSummary();
		students.at(m).printCourses();	
	}
	catch(out_of_range &e){
		cout << "The student is not found" << endl;
	}

    return 0;
}