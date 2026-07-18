#include<iostream>
using namespace std;

// Task 1: Complete the definition of class Box.

class Box{
	private:
		double w, l, h;
	public:
		Box(double w = 0, double l = 0, double h = 0){
			this->w = w;
			this->l = l;
			this->h = h;
		}
		void setW(double w){
			this->w = w;
		}
		void setL(double l){
			this->l = l;
		}
		void setH(double h){
			this->h = h;
		}
		double getW(){
			return w;
		}
		double getL(){
			return l;
		}
		double getH(){
			return h;
		}
		double calcVol(){
			return w * l * h;
		}
};

// Task 2: The following function is partialy given. The function is meant to print the dimension and volume of a box.
//          Complete the code of the function.

void printBox(Box b){
	cout << "Dimension = " << b.getW() << " x "
						   << b.getL() << " x "
						   << b.getH() << endl;
	cout << "Volume    = " << b.calcVol() << endl << endl;
}

int main()
{
	// Task 3: Create an array to hold 5 boxes and initliize the first two boxes with specified dimensions.
	Box b[5];
	b[0].setW(10);
	b[0].setL(10);
	b[0].setH(10);
	b[1].setW(20);
	b[1].setL(20);
	b[1].setH(20);
	
	// Task 4: Using a loop, set the dimensions the remaining boxes with data entered from the keyboard
	double w, l, h;
	for(int i=2; i<5; i++){
		cout << "Enter box dimensions (w l h) => ";
		cin >> w >> l >> h;
		b[i].setW(w);
		b[i].setL(l);
		b[i].setH(h);
	}
	cout << endl;
	
	// Task 5: Using an appropriate function and another loop, print all the boxes.
	for(int i=0; i<5; i++){
		printBox(b[i]);
	}
	
	// Task 6: Calculate and print the total volume of all boxes.
	double sum = 0;
	for(int i=0; i<5; i++){
		sum += b[i].calcVol();
	}
	cout << "Total volume = " << sum;
	
	return 0;
}
