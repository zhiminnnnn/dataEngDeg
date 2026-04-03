#include <iostream>
#include <iomanip>
using namespace std;

class Painting{
	private:
		string artist;
		int yearPainted;
		double auctionPrice;
	public:
		void setArtist(string artist){
			this->artist = artist;
		}
		void setYearPainted(int yearPainted){
			this->yearPainted = yearPainted;
		}
		void setAuctionPrice(double auctionPrice){
			this->auctionPrice = auctionPrice;
		}
		string getArtist(){
			return artist;
		}
		int getYearPainted(){
			return yearPainted;
		}
		double getAuctionPrice(){
			return auctionPrice;
		}
		double auction(){
			return auctionPrice += 500;
		}
		void displayPrice(){
			cout << fixed << setprecision(2);
			cout << "Current auction price = RM " << auction() << endl;
		}
};

int main(){
	Painting p1;
	p1.setArtist("Abraham");
	p1.setYearPainted(1975);
	p1.setAuctionPrice(14500.00);
	
	cout << "Artist name: " << p1.getArtist() << endl;
	cout << "Year painted: " << p1.getYearPainted() << endl;
	cout << fixed << setprecision(2);
	cout << "Starting auction price: RM " << p1.getAuctionPrice() << endl;
	
	for(int i=0; i<5; i++){
		p1.displayPrice();
	}
	return 0;
}
