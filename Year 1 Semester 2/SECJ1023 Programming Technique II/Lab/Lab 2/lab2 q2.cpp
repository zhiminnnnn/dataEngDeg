#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Stock{
	private:
		string code;
		string name;
		double closePrice;
		double currentPrice;
	public:
		string getCode() const{
			return code;
		}
		string getName() const{
			return name;
		}
		void setCode(string code){
			this->code = code;
		}
		void setName(string name){
			this->name = name;
		}
		void setClosePrice(double closePrice){
			this->closePrice = closePrice;
		}
		void setCurrentPrice(double currentPrice){
			this->currentPrice = currentPrice;
		}
		double changePercent(){
			return (currentPrice - closePrice) / closePrice * 100;
		}
		void display(){
			cout << "Close price  : RM" << closePrice << endl;
			cout << "Current price: RM" << currentPrice << endl;
			cout << "Price change percentage: ";
			if(changePercent() >= 0)
				cout << "+" << changePercent() << "%" << endl;
			else
				cout << changePercent() << "%" << endl;
			cout << endl;
		}
};

int main(){
	Stock stock1, stock2;
	
	stock1.setName("Maybank");
	stock1.setCode("MBB");
	stock1.setClosePrice(5500.00);
	stock1.setCurrentPrice(5250.00);
	cout << fixed << setprecision(2);
	cout << "Stock: " << stock1.getName() << " (" << stock1.getCode() << ")" << endl;
	stock1.display();
	
	stock2.setName("CIMB Bank Berhad");
	stock2.setCode("CIMB");
	stock2.setClosePrice(10000.00);
	stock2.setCurrentPrice(15050.00);
	cout << fixed << setprecision(2);
	cout << "Stock: " << stock2.getName() << " (" << stock2.getCode() << ")" << endl;
	stock2.display();
	
	return 0;
}
