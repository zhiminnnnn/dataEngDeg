// Problem 2

#include <iostream>
#include <string>
using namespace std;

class Advisor
{
private:
    string name;
    string staffId;
    string department;

public:
    Advisor(string _name = "", string _staffId = "", string _department = "")
        : name(_name), staffId(_staffId), department(_department) {}
    string getName() const { return name; }
    string getStaffId() const { return staffId; }
    string getDepartment() const { return department; }
};

class Student
{
private:
    string name;
    string matric;
    Advisor *adv;

public:
    Student(string _name = "", string _matric = "", Advisor *a = NULL)
        : name(_name), matric(_matric) {
		adv = a;
	}  
    string getName() const { return name; }
    string getMatric() const { return matric; }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;

        // Only print advisor info if the student has been assigned one.
        if(adv != NULL){
        	cout << "Advisor: " << endl;
        	cout << "   Name       : " << adv->getName() <<  endl;
        	cout << "   Staff ID   : " << adv->getStaffId() << endl;
        	cout << "   Department : " << adv->getDepartment() << endl;
        	cout << endl << endl;
		}
    }
};

int main()
{
    //! Create an advisor object and three students object
    //!  assign the advisor to only to two students.

    Advisor adv("Advisor", "StaffID", "Department");
    Student stud1("Stud1", "A25CS0050", &adv);
    Student stud2("Stud2", "A25CS0051", &adv);
    Student stud3("Stud3", "A25CS0052");

    stud1.print();
    stud2.print();
    stud3.print();

    return 0;
}