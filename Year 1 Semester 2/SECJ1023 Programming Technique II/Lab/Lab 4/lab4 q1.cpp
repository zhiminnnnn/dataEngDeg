//Program 4.2
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std; 
class kawan2; 
class kawan1
{
	int value;
	char girlF[10];
	int age;
	void secret() { strcpy(girlF, "Amy"); age = 30; }
	public:
		kawan1(int a) { value = a; secret(); }
		void print() { cout << " " << value << " "; }
		void gossip (kawan2);
		friend class kawan2;
};
class kawan2
{ 
	int value;
	int age;
	char girlF[10];
	void secret() { strcpy(girlF, "Lisa");age=22; }
	public:
		kawan2(int a) { value = a; secret();}
		void print() { cout << " " << value << " "; }
		void gossip (kawan1);
		friend void kawan1::gossip(kawan2);
};
// write the functions here
void kawan1::gossip (kawan2 k2){
	print();
	cout << "gossips on";
	k2.print();
	cout << endl;
	print();
	cout << "says";
	k2.print();
	cout << "girl friend is " << k2.girlF << endl;
}

void kawan2::gossip (kawan1 k1){
	print();
	cout << "gossips on";
	k1.print();
	cout << endl;
	print();
	cout << "says";
	k1.print();
	cout << "age is " << k1.age << endl;
}

int main()
{ 
	kawan1 objek1(100);
	kawan2 objek2(50);
	objek1.gossip(objek2);
	objek2.gossip(objek1);
	return 0;
}