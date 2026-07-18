//Program 3.3
#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
		string name;
	public:
 		Student(){ //1
			name = "";
		}
 		Student(string aName){ //2
			name = aName;
		} 
		~Student(){ //3
			cout << "The object has been destroyed" << endl;
		}
 
		string getName() const{ //4
			return name;
		}
		void setName(string aName){ //5
			name = aName;
		}
	};
int main()
{
 	Student student("Siti Aminah"); //6
 	Student s1("Ramlee Puteh"); //7
 	Student s2("Ahmad Mahmood");
 	Student s3;
 
 	cout << "Student's name: " << s2.getName() << endl; //8
 	s3.setName("Mustafa Kamal"); //9
 	s2.setName(s1.getName()); //10
 	return 0;
}