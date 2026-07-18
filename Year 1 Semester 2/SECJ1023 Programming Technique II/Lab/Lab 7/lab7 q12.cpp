#include <iostream>
using namespace std;

const int MAX = 3;

class Passenger{
	protected:
		string name;
		int age;
	public:
		Passenger(string n="", int a=0){
			name = n;
			age = a;
		}
		void printDetails(){
			cout << "Name: " << name << "\tAge: " << age << endl;
		}
};

class Kids : public Passenger{
	private:
		string parentName;
	public:
		Kids(string p="", int a=0, string n="") : Passenger(n, a){
			parentName = p;
		}
		void printDetails(){
			cout << "Name:\t" << name << "\tAge:\t" << age
				 << "\tParents Name:\t" << parentName << endl;
		}
};

class Adults : public Passenger{
	private:
		string job;
	public:
		Adults(string j="", int a=0, string n="") : Passenger(n, a){
			job = j;
		}
		void printDetails(){
			cout << "Name:\t" << name << "\tAge:\t" << age
				 << "\tJob Title\t" << job << endl;
		}
};

class Time{
	private:
		int hour;
		int minute;
	public:
		Time(int h=0, int m=0){
			hour = h;
			minute = m;
		}
		int getHour(){
			return hour;
		}
		int getMinute(){
			return minute;
		}
};

class Flight{
	private:
		string id;
		string destination;
		Time *depart;
		Time *arrival;
		Passenger *passengerList;
		int count = 0;
	public:
		Flight(string i="", string des="", Time *dep=NULL, Time *a=NULL){
			id = i;
			destination = des;
			depart = dep;
			arrival = a;
			passengerList = new Passenger [MAX];
		}
		void addPassenger(Passenger p){
			passengerList[count++] = p;
		}
		void printInfo(){
			cout << "Flight No:\t" << id << endl;
			cout << "Destination:\t" << destination << endl;
			cout << "Departure:\t" << depart->getHour() << ":" << depart->getMinute() << endl;
			cout << "Arrival:\t" << arrival->getHour() << ":" << arrival->getMinute() << endl << endl; 
		}
};

int main(){
	Time depart(8, 10);
	Time arrive(9, 0);
	Flight f("NAS7921", "Johor Bahru", &depart, &arrive);
	Kids p3("Ali", 3, "Azmi");
	Adults p1("Lecturer", 34, "Ali");
	Adults p2("Student", 25, "Goh");
	f.addPassenger(p1);
	f.addPassenger(p2);
	f.addPassenger(p3);
	f.printInfo();
	cout << "Passengers Details:" << endl;
	p1.printDetails();
	p2.printDetails();
	p3.printDetails();
	return 0;
}