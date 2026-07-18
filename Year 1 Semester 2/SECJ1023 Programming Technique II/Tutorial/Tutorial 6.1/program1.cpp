// Problem 1

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string area;
    string city;
    string state;
    string postCode;

public:
    Address(string _area = "", string _city = "",
            string _state = "", string _postCode = "")
        : area(_area), city(_city),
          state(_state), postCode(_postCode) {}

    string getArea() const { return area; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getPostCode() const { return postCode; }
};

class Student
{
private:
    string name;
    string matric;
    Address *address;

public:
    Student(string _name = "", string _matric = "", Address *a = NULL)
        : name(_name), matric(_matric) {
		address = a;
	}
    
    string getName() const { return name; }
    string getMatric() const { return matric; }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;
        cout << "Address: " << endl;
        cout << "   Area     : " << address->getArea() << endl;
        cout << "   City     : " << address->getCity() << endl;
        cout << "   State    : " << address->getState() << endl;
        cout << "   Post Code: " << address->getPostCode() << endl;
    }
};

int main()
{
    //! Create an object of Student with an address
    Address addr("area", "city", "state", "postcode");
    Student stud("Cheng", "A25CS0050", &addr);

    stud.print();

    return 0;
}