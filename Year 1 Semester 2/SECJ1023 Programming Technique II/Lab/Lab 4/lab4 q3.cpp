#include <iostream>
using namespace std;

//Program 4.6
class Length{ 
	private:
		int len_inches;
	public:
		Length (int feet=0, int inches=0)
		{ len_inches=12*feet+inches;}
		int getFeet(){ return len_inches/12;}
		int getInches(){return len_inches%12;}
		friend bool operator<(Length , Length );
		friend bool operator==(Length a, Length b);
};

bool operator< (Length a, Length b){
	if (a.len_inches < b.len_inches)
		return true;
	else
		return false;
}

bool operator== (Length a, Length b){
	if (a.len_inches == b.len_inches)
		return true;
	else
		return false;
}

int main(){
	Length lens[4];
	lens[0] = Length(1, 2);
	lens[1] = Length(4, 3);
	lens[2] = Length(5, 6);
	lens[3] = Length(8, 7);
	for(int i=0; i<4; i++){
		for(int j=i+1; j<4; j++){
			if(lens[i] == lens[j])
				cout << "Same length at indexes " << i << " and " << j << endl;
		}
	}
	int min = lens[0].getFeet(), max = lens[0].getFeet(), minIn = 0, maxIn = 0;
	for(int i=0; i<4; i++){
		if(lens[i] < lens[minIn]){
			min = lens[i].getFeet();
			minIn = i;
		}
		else if(lens[maxIn] < lens[i]){
			max = lens[i].getFeet();
			maxIn = i;
		}
	}
	
	cout << "Shortest length in feet is " << min << " feet at index " << minIn << endl;
	cout << "Longest length in feet is " << max << " feet at index " << maxIn << endl;
	return 0;
}