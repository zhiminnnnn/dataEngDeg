#include <iostream>
using namespace std;

class Line{
	private:
		int m, c;
	public:
		Line(){
			m = 0;
			c = 0;
		}
		Line(int m, int c){
			this->m = m;
			this->c = c;
		}
		Line(int x1, int y1, int x2, int y2){
			m = (y2-y1)/(x2-x1);
			c = y1 - m*x1;
		}
		~Line(){
			cout << "The object is being destroyed." << endl;
		}
		int getM(){
			return m;
		}
		int getC(){
			return c;
		}
		void setM(int m){
			this->m = m;
		}
		void setC(int c){
			this->c = c;
		}
		void printEquation(){
			if (c==0)
				cout << "Eq.\ty=" << m << "x" << endl;
			else if(c<0)
				cout << "Eq.\ty=" << m << "x" << c << endl;
			else
				cout << "Eq.\ty=" << m << "x+" << c << endl;
		}
};

int main(){
	Line line1(2, -5);
	line1.printEquation();
	
	Line line2(0, 0, 2, 8);
	line2.printEquation();
	
	Line line3;
	int m, c;
	cout << "Enter the slope and y-intercept of the line, m c => ";
	cin >> m >> c;
	line3.setM(m);
	line3.setC(c);
	line3.printEquation();
	return 0;
}
