// Programming Technique II
// Tutorial 7: Inheritance

#include <iostream>
#include <string>
using namespace std;


// The class Student and Project have been given.
// Do nothing on these classes

class Student
{
  protected:
	string name;
	string matric;

  public:
	Student(string _name = "", string _matric = "") : name(_name), matric(_matric)
	{}

	string getName() const { return name; }
	string getMatric() const { return matric; }
	void setName(string n) { name = n; }
	void setMatric(string m) { matric = m; }

	virtual void input()
	{
		cout << "Enter name => ";
		getline(cin, name);
		cout << "Enter matric => ";
		getline(cin, matric);
	}

	virtual void print() const
	{
		cout << "Name  : " << name << endl;
		cout << "Matric: " << matric << endl;
	}
};

class Project
{
  protected:
	string title;
	string area;

  public:
	Project(string _title = "", string _area = "") : title(_title), area(_area)
	{}

	string getTitle() const { return title; }
	string getArea() const { return area; }

	void setTitle(string t) { title = t; }
	void setArea(string a) { area = a; }
};


class Undergraduate : public Student
{
  protected:
	double cgpa;

  public:
	Undergraduate(string _name = "",
	              string _matric = "",
				  double _cgpa = 0.0) : Student(_name, _matric)
	{
		name = _name;
	    matric = _matric;
	    cgpa = _cgpa;
	}

	double getCGPA() const { return cgpa; }
	void setCGPA(double c) { cgpa = c; }

	void input()
	{
		Student::input();
		cout << "Enter CGPA: ";
		cin >> cgpa;
	}

	void print() const
	{
		Student::print();
		cout << "CGPA: " << cgpa << endl;
	}
};


// Task 4: Complete the implementation of the class Postgraduate

class Postgraduate : public Student, public Project
{
  public:
	Postgraduate(string _name = "",
	              string _matric = "",
				  string prjTitle = "",
				  string prjArea = "") : Student(_name, _matric), Project(prjTitle, prjArea)
	{
		name = _name;
	    matric = _matric;
	    title = prjTitle;
	    area = prjArea;
	}

	string getProjectTitle() const
	{
		return title;
	}


	string getProjectArea() const
	{
		return area;
	}

	void setProject(string _title, string _area)
	{
		title = _title;
		area = _area;
	}

	void input()
	{
		Student::input();
		cout << "Enter project title => ";
		getline(cin, title);
		cout << "Enter project area => ";
		getline(cin, area);
	}

	void print() const
	{
		Student::print();
		cout << "Project title: " << title << endl;
		cout << "Project area : " << area << endl;
	}

};

int menu()
{
	cout << "=============[ Menu ]=============" << endl;
	cout << "1. Add an undergraduate student" << endl;
	cout << "2. Add a postgraduate student" << endl;
	cout << "3. Display all students" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "Choose an operation [1,2,3 or 9] => ";

	int choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

//-------------------------------------------------------
// The main function
//-------------------------------------------------------

int main()
{
	// Task 5: Create two arrays to hold lists of undergraduate and postgraduate students, respectively.
	//        Tips: You also need to declare variables to hold the number of undergraduate and postgraduate
	//        students, respectively.
	
	const int max_u = 100;
	const int max_p = 100;
	
	Undergraduate u[max_u];
	Postgraduate p[max_p];
	
	int count_u = 0;
	int count_p = 0;

	int c = menu();

	while (c != 9)
	{
		switch (c)
		{
		case 1:
		    // Task 6: Read data for an undergraduate student and add it to the relevant array.
			cout << endl << "Adding a undergraduate student: " << endl << endl;
			u[count_u].input();
			count_u ++;
			cout << endl;
			break;

		case 2:
			// Task 7: Read data for a postgraduate student and add it to the relevant array.
			cout << endl << "Adding a postgraduate student: " << endl << endl;
			p[count_p].input();
			count_p ++;
			cout << endl;
			break;

		case 3:
			// Task 8: Diplay the list of undergraduate and postgraduate students.

			cout << endl << "The list of undergraduate students:" << endl << endl;
			for(int i=0; i<count_u; i++){
				cout << "No. : " << i + 1 << endl;
				u[i].print();
				cout << endl;
			}

			cout << endl << "The list of postgraduate students:" << endl << endl;
			for(int i=0; i<count_p; i++){
				cout << "No. : " << i + 1 << endl;
				p[i].print();
				cout << endl;
			}

			break;
		}

		c = menu();
	}

	return 0;
}
