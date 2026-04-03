#include <iostream>
#include <iomanip>
using namespace std;

class Mechanic{
	string name;
	int id, hours;
	double salary, rate;
	
	public:
		Mechanic(string name, int id, int hours, double rate){
			this->name = name;
			this->id = id;
			this->hours = hours;
			this->rate = rate;
		}
		double calculateSalary(){
			salary = hours * rate;
			return salary;
		}
		void display(){
			cout << fixed << setprecision(2);
			cout << "Name         : " << name << endl;
			cout << "Staff ID     : " << id << endl;
			cout << "Hours worked : " << hours << endl;
			cout << "Rate per hour: RM" << rate << endl;
			cout << "Salary       : RM" << calculateSalary() << endl;
		}
		
		friend double calculateEPF(Mechanic);
};

double calculateEPF(Mechanic obj){
	return 0.05 * obj.salary;
}

int main(){
	Mechanic m("Cheng Zhi Min", 123, 9, 9.5);
	m.display();
	cout << "EPF          : RM" << calculateEPF(m);
	return 0;
}