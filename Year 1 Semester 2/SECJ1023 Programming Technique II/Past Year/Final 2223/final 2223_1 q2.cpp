#include <iostream>
#include <string>
using namespace std;

class Address{
	private:
		string city;
	public:
		Address(string city = ""){
			this->city = city;
		}
		void setCity(string city){
			this->city = city;
		}
		string getCity(){
			return city;
		}
};

class Person{
	protected:
		string name;
		Address ad;
	public:
		Person(string name = "", string c = ""){
			this->name = name;
			ad.setCity(c);
		}
		string getName(){
			return name;
		}
		string getAddress(){
			return ad.getCity();
		}
};

class Advisor : public Person{
	private:
		string faculty;
	public:
		Advisor(string faculty = "", string name = "", string c = "") : Person(name, c){
			this->faculty = faculty;
		}
		string getFaculty(){
			return faculty;
		}
};

class Student : public Person{
	private:
		string program;
		Advisor *ad;
	public:
		Student(string program = "", string name = "", string c = "") : Person(name, c){
			this->program = program;
			ad = NULL;
		}
		void setAdvisor(Advisor *a){
			ad = a;
		}
		Advisor *getAdvisor(){
			return ad;
		}
		string getCity(){
			return getAddress();
		}
		string getAdvisorName(){
			return ad->getName();
		}
		string getAdvisorCity(){
			return ad->getAddress();
		}
		string getFaculty(){
			return ad->getFaculty();
		}
};

int main(){
	Student s("", "Ali", "Skudai");
	s.setAdvisor(new Advisor("FC", "Dr. Abu", "Johor Bharu"));
	cout << s.getName() << endl;
	cout << s.getCity() << endl;
	cout << s.getAdvisorName() << endl;
	cout << s.getAdvisorCity() << endl;
	cout << s.getFaculty() << endl;
	return 0;
}
