#include <iostream>
#include <cmath>
using namespace std;

class Particle{
	private:
		double x, y, z, r;
	public:
		Particle(){
			x = 0;
			y = 0;
			z = 0;
			r = 0;
		}
		void read(){
			cout << "Center: ";
			cin >> x >> y >> z;
			cout << "Radius: ";
			cin >> r;
		}
		void print(){
			cout << "Center: (" << x << "," << y << "," << z << ")" << endl;
			cout << "Radius: " << r << endl;
		}
		double operator- (const Particle &p){
			Particle temp;
			temp.x = pow(p.x - x, 2);
			temp.y = pow(p.y - y, 2);
			temp.z = pow(p.z - z, 2);
			return sqrt(temp.z + temp.z + temp.z);
		}		
		friend bool collision(Particle p1, Particle p2){
			if((p1 - p2) <= (p1.r + p2.r))
				return true;
			else return false;
		}
};

int main(){
	Particle p1, p2;
	cout << "Enter data for the first particle: " << endl;
	p1.read();
	cout << "\nEnter data for the second particle: " << endl;
	p2.read();
	if(collision(p1, p2)){
		cout << "\nThe particles are colliding." << endl << endl;
		cout << "First particle: " << endl;
		p1.print();
		cout << "\nSecond particle: " << endl;
		p2.print();
	}
	else
		cout << "\nNo collision detected.";
	return 0;
}