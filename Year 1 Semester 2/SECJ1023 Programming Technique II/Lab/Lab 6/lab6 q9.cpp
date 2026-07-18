#include <iostream>
using namespace std;

class Cat{
	private:
		string name;
		int age;
		int yearAdopt;
	public:
		Cat(string n="", int a=0, int y=0){
			name = n;
			age = a;
			yearAdopt = y;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		int calcNumOfYear(){
			return yearAdopt;
		}
};

class Person{
	private:
		string name;
		string address;
		int count = 3;
		Cat *myCat;
	public:
		Person(string n="", string a=""){
			name = n;
			address = a;
			myCat = new Cat [count];
		}
		void adopt(Cat *cat){
			for(int i=0; i<count; i++){
				myCat[i] = cat[i];
			}
		}
		void print(){
			cout << "Person Name            : " << name << endl;
			cout << "Person Address         : " << address << endl;
			cout << "Number of Cats Adopted : " << count << endl << endl;
			for(int i=0; i<count; i++){
				cout << "Cat " << i+1 << " Name                    : " << myCat[i].getName() << endl;
				cout << "Cat " << i+1 << " Age                     : " << myCat[i].getAge() << endl;
				cout << "Cat " << i+1 << " Number of Years Adopted : " << myCat[i].calcNumOfYear() << endl << endl;
			}
		}
};

int main(){
	Person p("Person Name", "Person Address");
	Cat c[3] = {Cat("Cat Name 1", 1, 2), Cat("Cat Name 2", 2, 4), Cat("Cat Name 1", 3, 6)};
	p.adopt(c);
	p.print();
	return 0;
}