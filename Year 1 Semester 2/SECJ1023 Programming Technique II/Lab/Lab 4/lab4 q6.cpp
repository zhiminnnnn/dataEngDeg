#include <iostream>
#include <iomanip>
using namespace std;

//Program 4.7
class Product{
	public:
		Product(){
			prodCode = 0;
			price = 0.0;
		}
		int getProdCode(){
			return prodCode;
		}
		void setProdCode(int k){
			prodCode = k;
		}
		double getPrice(){
			return price;
		}
		void setPrice(double p){
			price = p;
		}
		friend ostream &operator<< (ostream&, const Product &);
	private:
		int prodCode;
		double price;
};

ostream &operator<< (ostream& strm, const Product &p){
	strm << fixed << setprecision(2);
	strm << "Product code: " << p.prodCode << endl;
	strm << "Product price: " << p.price << endl;
	return strm;
}

int main(){
	Product ob1;
	ob1.setProdCode(789);
	ob1.setPrice(12.50);
	cout << ob1;
	return 0;
}