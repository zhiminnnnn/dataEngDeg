// Programming Technique II (SECJ1023)
// ? Revision and Level Test of Procedural Programming
// ! Program 3b: Calculate statistics (largest, sum and mean) of data

//? Collaborative Coding Group Members:
// Name 1:
// Name 2:
// Name 3:
// Name 4:

#include <iostream>

using namespace std;

//! Define three functions: largest, sum, mean
double largest(int size, double arr[]){
	double max = arr[0];
	for(int i=1; i<size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

double sum(int size, double arr[]){
	double sum = 0;
	for(int i=0; i<size; i++){
		sum += arr[i];
	}
	return sum;
}

double mean(int size, double arr[]){
	return sum(size, arr)/size;
}


int main()
{
    int n;

    cout << "How many numbers do you want to enter?  => ";
    cin >> n;
    
    double *arr = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number #" << i+1 << "  => ";
		cin >> arr[i];
    }

    cout << endl;
    
    cout << "Largest :  " << largest(n, arr) << endl;
    cout << "Sum     :  " << sum(n, arr) << endl;
    cout << "Mean    :  " << mean(n, arr) << endl;
    cout << endl;

    system("pause");

    return 0;
}
