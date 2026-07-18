#include <iostream>
#include <array>
using namespace std;

int main(){
	array <double, 5> scores;
	double val;
	double sum = 0;
	double max = scores.at(0);
	cout << "Enter 5 scores: " << endl;
	for(int i=0; i<5; i++){
		cout << "Score " << i+1 << ": ";
		cin >> val;
		scores.at(i) = val;
		sum += val;
		if(val > max) max = val;
	}
	cout << "Scores entered: ";
	for(int i=0; i<4; i++){
		cout << scores.at(i) << ", ";
	}
	cout << scores.back() << endl;
	cout << "Average score: " << sum / 5 << endl;
	cout << "Highest score: " << max << endl;
	return 0;
}