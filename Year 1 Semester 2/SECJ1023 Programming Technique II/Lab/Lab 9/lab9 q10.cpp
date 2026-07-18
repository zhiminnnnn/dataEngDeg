#include <iostream>
using namespace std;

template <class T>
class Temp{
	private:
		T *items;
		int count;
	public:
		Temp(){
			items = new T [100];
			count = 0;
		}
		~Temp(){
			delete [] items;
		}
		void addNew(T element){
			items[count++] = element;
		}
		int getNum(){
			return count;
		}
		T *getPtr(){
			return items;
		}
};

int main(){
	Temp <int> dataInt;
	Temp <string> dataStr;
	dataInt.addNew(2);
	dataInt.addNew(4);
	dataInt.addNew(6);
	dataInt.addNew(8);
	dataStr.addNew("one");
	dataStr.addNew("three");
	dataStr.addNew("five");
	int *ptrInt;
	ptrInt = dataInt.getPtr();
	string *ptrStr;
	ptrStr = dataStr.getPtr();
	cout << dataInt.getNum() << endl;
	cout << dataStr.getNum() << endl;
	for(int i=0; i<dataInt.getNum(); i++){
		cout << ptrInt[i] << endl;
	}
	for(int i=0; i<dataStr.getNum(); i++){
		cout << ptrStr[i] << endl;
	}
	return 0;
}