#include <iostream>
#include <iomanip>
using namespace std;

class Mechanic{
	private:	
		string name;
		int id, hr;
		double sal, rate;
	
	public:
		Mechanic(string name, int id, int hr, double rate){
			this->name = name;
			this->id = id;
			this->hr = hr;
			this->rate = rate;
		}
		
		double calculateSalary(){
			sal = hr * rate;
			return sal;
		}
		
		void display(){
			cout << fixed << setprecision(2);
			cout << "Name         : " << name << endl;
			cout << "Staff ID     : " << id << endl;
			cout << "Hours worked : " << hr << endl;
			cout << "Rate per hour: RM" << rate << endl;
			cout << "Salary       : RM" << calculateSalary() << endl;
		}
		
		friend double calculateEPF(const Mechanic);
};

double calculateEPF(const Mechanic m){
	double epf = 0.05 * m.sal;
	return epf;
}

int main(){
	Mechanic m("Cheng Zhi Min", 123, 8, 10.5);
	m.display();
	cout << "EPF          : RM" << calculateEPF(m);
	return 0;
}