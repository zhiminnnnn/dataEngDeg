#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Instructor
{
private:
    string firstName;
    string lastName;
    string office; // Office Room Number e.g., N28A-L303

public:
    Instructor(string firstName, string lastName, string office)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->office = office;
    }

    void print() const
    {
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Office number: " << office << endl;
    }
};

class TextBook
{
private:
    string title;     // Book title
    string author;    // Author name
    string publisher; // Publisher name
public:
    TextBook(string title, string author, string publisher)
    {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
    }

    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class Course
{
private:
    string name;
    Instructor *instructor;
    TextBook *textBook;

public:
    Course(string name)
    {
        this->name = name;
        instructor = NULL;
        textBook = NULL;
    }

    void setInstructor(Instructor *i) { instructor = i; }
    void setTextBook(TextBook *b) { textBook = b; }

    void print() const
    {
        cout << "Course name: " << name << endl;
        cout << "Instructor Information:" << endl;
        if (instructor) instructor->print();
        cout << endl;

        cout << "\nTextbook Information:" << endl;
        if (textBook) textBook->print();
    }
};

template <class T>
class Array{
	private:
		vector <T*> items;
	public:
		void add(T* newItem){
			items.push_back(newItem);
		}
		T *getItem(int index){
			return items.at(index);
		}
		void print(){
			for(int i=0; i<items.size(); i++){
				items.at(i)->print();
				cout << endl;
			}
		}
};

int main()
{
    // Data for the instructors and textbooks:
    //
    // "Ahmad", "Kamal", "N28-L305"
    // "Mellisa", "Wong", "D06-105"
    // "Ali", "Hassan";
    //
    // "Object-Oriented Programming Approach Using C++", "Gilberg", "Springer Publication"
    // "Introduction to Functional Programming with TypeScript", "Samantha", "Oxford Press"
    Array <Instructor> i;
    Array <TextBook> t;
    i.add(new Instructor("Ahmad", "Kamal", "N28-L305"));
    i.add(new Instructor("Mellisa", "Wong", "D06-105"));
    i.add(new Instructor("Ali", "Hassan", "N28A-L501"));
    t.add(new TextBook("Object-Oriented Programming Approach Using C++", "Gilberg", "Springer Publication"));
    t.add(new TextBook("Introduction to Functional Programming with TypeScript", "Samantha", "Oxford Press"));
    Course c("Programming Technique II");
	c.setInstructor(i.getItem(1));
	c.setTextBook(t.getItem(1)); 
    cout << "LIST OF INSTRUCTORS:" << endl << endl;
    i.print();
    cout << "-------------------------------------------------------"<< endl;
    cout << "LIST OF TEXTBOOKS:" << endl << endl;
    t.print();
    cout << "-------------------------------------------------------"<< endl << endl;
    cout << "COURSE INFORMATION:" << endl << endl;
	c.print();
    cin.get();
    return 0;
}