// NAME: 
// MATRIC NO.:
// SECTION:

// SECJ1023 PROGRAMMING TECHNIQUE 2
// FINAL EXAM (PRACTICAL) 2024/2025-02
// QUESTION 1 (a-f)

/*
(a)(i)	Developer and Employee: 
Relationship: Inheritance

(a)(ii)	Manager and Team:
Relationship: No

(a)(iii) Company and Employee: 
Relationship: Composition

(a)(iv)	Team and Employee: 
Relationship: Aggregation
*/

#include <iostream>
using namespace std;

// Base class - Partially given
class Employee {
public:
    // (b)(i) virtual void work() const
    virtual void work() const{
    	cout << "Employee working" << endl;
	}
    // (b)(ii) virtual ~Employee()
    virtual ~Employee(){}
};

// Derived classes - Fully given
class Developer : public Employee {
public:
    void work() const {
        cout << "Developer writing code\n";
    }
};

// Derived classes - Fully given
class Manager : public Employee {
public:
    void work() const {
        cout << "Manager in meeting\n";
    }
};

// Company owns its employees (1:1 relationship) - Partially given
class Company {
private:
    Employee* employee;  
public:
    // (c)(i) Company(Employee *)
	Company(Employee *e=NULL){
		employee = e;
	}
    // (c)(ii) ~Company()
    ~Company(){}
    // (c)(iii) void dailyOperation() const
	void dailyOperation() const{
		cout << "Company operation: ";
		employee->work();
	}
};
// Team uses employees - Partially given
class Team {
private:
    Employee* members[3];  // Fixed-size array
    int count = 0;
public:
    // (d)(i) void addMember(Employee *)
	void addMember(Employee *m){
		if(count >= 3) throw "[!] Limit: Maximum 3 members only.";
		else members[count++] = m;
	}
    // (d)(ii) void teamMeeting() const
	void teamMeeting() const{
		for(int i=0; i<count; i++){
			members[i]->work();
		}
	}
};

// main() - Partially given
int main() {
    // Relationship 1
    Employee* employees[2];
    employees[0] = new Developer();
    employees[1] = new Manager();
    for (int i = 0; i < 2; i++) {
        // (e)(i) invokes the work() function for each Employee in the array
		employees[i]->work();
    }
    // Relationship 2
    // (e)(ii) create Company object and pass the dynamically allocated Developer object
	Company company(employees[0]);
    // (e)(ii) invokes the dailyOperation() function
	company.dailyOperation();
    // Relationship 3
    Team projectTeam;
    try{
    	// (e)(iii) invoke the addMember() function and pass the dynamically allocated Developer object 
		projectTeam.addMember(employees[0]);
    	// (e)(iii) invoke the addMember() function and pass the dynamically allocated Manager object
		projectTeam.addMember(employees[1]);
		// (e)(iii) invoke the teamMeeting() function
    	projectTeam.teamMeeting();
	    // destroy objects
    	for (int i = 0; i < 2; i++) {
        	delete employees[i];
    	}
	}
    catch (const char* msg){
    	cout << msg;
	}
    return 0;
}

// (f) Ensure your program produces exactly the following output, without any compilation or runtime errors:
//			Developer writing code
//			Manager in meeting
//			Company operation: Developer writing code
//			Developer writing code
//			Manager in meeting