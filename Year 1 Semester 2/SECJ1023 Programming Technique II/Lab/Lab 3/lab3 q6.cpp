#include <iostream>
#include <iomanip>
using namespace std;

class Product{
	private:
		int code;
		double price;
	public:
		Product(){
			code = 0;
			price = 0;
		}
		Product(int code, double price){
			this->code = code;
			this->price = price;
		}
		~Product(){}
		void setCode(int code){
			this->code = code;
		}
		void setPrice(double price){
			this->price = price;
		}
		int getCode(){
			return code;
		}
		double getPrice(){
			return price;
		}
};

int main(){
	Product p[100];
	int n, c;
	double pr, sum;
	cout << "How many products to enter? ";
	cin >> n;
	cout << endl;
	for(int i=0; i<n; i++){
		cout << "Enter the information of product #" << i+1 << endl;
		cout << "Product Code: ";
		cin >> c;
		cout << "Price: ";
		cin >> pr;
		cout << endl;
		p[i].setCode(c);
		p[i].setPrice(pr);
	}
	
	p[3] = Product(100, 1.00);
	
	cout << "No" << "\tProduct Code" << "\tPrice" << endl << endl;
	for(int i=0; i<n; i++){
		cout << fixed << setprecision(2);
		cout << i+1 << "\t" << p[i].getCode() << "\t\t" << p[i].getPrice() << endl;
		sum += p[i].getPrice();
	}
	
	cout << endl;
	cout << "Average Price: RM " << sum/n << endl;
	
	return 0;
}