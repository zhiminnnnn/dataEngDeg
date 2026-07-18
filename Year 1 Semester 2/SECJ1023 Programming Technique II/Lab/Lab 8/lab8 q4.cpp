//Program 8.5
#include<iostream>
using namespace std;
#define PI 3.1415

class Object3D {
	public:
		Object3D(){}
		virtual void print() const {}
		virtual double getVolume()const {return 0;}
};

class Sphere : public Object3D {
	protected:
		double r;
	public:
		Sphere(double _r=0){
			setRadius(_r);
		}
		void setRadius(double _r){
			r = _r;
		}
		double getRadius() const {
			return r;
		}
		void print() const {
			cout << "Sphere: r=" << r << endl;
		}
		double getVolume() const {
			return 4.0 / 3.0 * PI * r * r * r;
		}
};

class Cylinder : public Object3D {
	protected:
		double r,h;
	public:
		Cylinder(double _r=0, double _h=0){
			setRadius(_r);
			setHeight(_h);
		}
		void setRadius(double _r){
			r = _r;
		}
		void setHeight(double _h){
			h = _h;
		}
		double getRadius() const {
			return r;
		}
		double getHeight() const {
			return h;
		}
		void print() const{
			cout << "Cylinder: r=" << r << ", h=" << h << endl;
		} 
		double getVolume() const {
			return PI * r * r * h;
		}
};

class Cuboid : public Object3D {
	protected:
	 	double w,l,h;
	public:
	 	Cuboid(double _w=0, double _l=0, double _h=0){
			setWidth(_w);
		 	setLength(_l);
		 	setHeight(_h);
	 	} 
	 
		void setWidth(double _w){
			w = _w;
		}
		void setLength(double _l){
			l = _l;
		}
		void setHeight(double _h){
			h = _h;
		}
		double getWidth() const {
			return w;
		}
		double getLength() const {
			return l;
		}
		double getHeight() const {
			return h;
		}
		void print() const {
			cout << "Cuboid: dimension = " 
		 		 << w << " x " << l << " x " << h << endl;
		}
	 	double getVolume() const {
	 		return w * l * h;
		}
};
int main()
{ 
	// Task 5: Create an array of pointers of Object3D. 
	// Task 6: Fill in the array with different types of 
	// objects, for example cuboids, spheres and cylinders.
	// Put all the objects in the same array.
	// Task 7: Print the information of all objects along with 
	// their volume
	
	Cuboid obj1(10, 20, 30);
	Cylinder obj2(20, 20);
	Sphere obj3(10);
	Cylinder obj4(2, 5);
	Sphere obj5(3);
	
	Object3D *arr[5] = {&obj1, &obj2, &obj3, &obj4, &obj5};
	
	for (int i=0; i<5; i++){
		cout << "Object #" << (i+1) << endl;
		arr[i]->print();
		cout << "Volume= " << arr[i]->getVolume() << endl;
		cout << endl;
	}
	 
	double totalVolume = 0;
	
	for(int i=0; i<5; i++){
		totalVolume += arr[i]->getVolume();
	}
	 
	cout << "Total volume = " << totalVolume << endl;
	return 0;
}