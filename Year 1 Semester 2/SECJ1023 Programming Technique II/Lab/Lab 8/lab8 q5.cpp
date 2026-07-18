#include <iostream>
using namespace std;

class Transport{
	protected:
		string name;
		string year;
	public:
		Transport(string name="", string year=""){
			this->name = name;
			this->year = year;
		}
		void setName(string name){
			this->name = name;
		}
		void setYear(string year){
			this->year = year;
		}
		string getName(){
			return name;
		}
		string getYear(){
			return year;
		}
		virtual void print(){
			cout << "Transport's Name: " << name << endl;
			cout << "Year Built      : " << year << endl;
		}
};

class Car : public Transport{
	private:
		int max;
	public:
		Car(int max=0, string name="", string year="") : Transport(name, year){
			this->max = max;
		}
		void setMax(int max){
			this->max = max;
		}
		int getMax(){
			return max;
		}
		void print(){
			cout << "Car's Name                  : " << name << endl;
			cout << "Maximum Number of Passengers: " << max << endl;
		}
};

class Motor : public Transport{
	private:
		int max;
	public:
		Motor(int max=0, string name="", string year="") : Transport(name, year){
			this->max = max;
		}
		void setMax(int max){
			this->max = max;
		}
		int getMax(){
			return max;
		}
		void print(){
			cout << "Motor's Name                : " << name << endl;
			cout << "Maximum Number of Passengers: " << max << endl;
		}
};

int main(){
	Transport *trans = new Transport("Transport Name", "2006");
	Car *car = new Car(10, "Car Name", "2007");
	Motor *motor = new Motor(20, "Motor Name", "2008");
	Transport *arr[3] = {trans, car, motor};
	for(int i=0; i<3; i++){
		arr[i]->print();
	}
	return 0;
}