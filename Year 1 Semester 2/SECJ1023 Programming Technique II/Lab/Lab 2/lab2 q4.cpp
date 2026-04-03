#include <iostream>
#include <iomanip>
using namespace std;

class Chemical{
	private:
		string name, symbol;
		int atomicNumber;
		double atomicWeight;
	public:
		string getName(){
			return name;
		}
		void setName(string name){
			this->name = name;
		}
		string getSymbol(){
			return symbol;
		}
		void setSymbol(string symbol){
			this->symbol = symbol;
		}
		int getAtomicNumber(){
			return atomicNumber;
		}
		void setAtomicNumber(int atomicNumber){
			this->atomicNumber = atomicNumber;
		}
		double getAtomicWeight(){
			return atomicWeight;
		}
		void setAtomicWeight(double atomicWeight){
			this->atomicWeight = atomicWeight;
		}
		void readInput(){
			cout << "Please enter the requested information to create a new chemical object." << endl;
			cout << "Enter the chemical's name: ";
			cin >> name;
			cout << "Enter the chemical's symbol: ";
			cin >> symbol;
			cout << "Enter the chemical's atomic number: ";
			cin >> atomicNumber;
			cout << "Enter the chemical's atomic weight: ";
			cin >> atomicWeight;
		}
};

int main(){
	Chemical c1, c2;
	c1.readInput();
	cout << "You just entered information for " << c1.getName() << "." << endl << endl;
	cout << "And here are its details: "
		 << c1.getName() << " ["
		 << c1.getSymbol() << ", #"
		 << c1.getAtomicNumber() << ", "
		 << c1.getAtomicWeight() << "]" << endl;

	c2.setName("Sodium");
	c2.setSymbol("Na");
	c2.setAtomicNumber(11);
	c2.setAtomicWeight(22.98977);
	
	cout << fixed << setprecision(5);

	cout << "Here is another chemical: "
		 << c2.getName() << " ["
		 << c2.getSymbol() << ", #"
		 << c2.getAtomicNumber() << ", "
		 << c2.getAtomicWeight() << "]" << endl;
}
