// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 6: Find the covariance between two lists of numbers
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>
#include <fstream>

using namespace std;

// ! readArrayFromFile:
// ? This function reads the list of numbers from a text file specified by the "fileName"
// ? and stores the read numbers into the parameter list.
// ? It also returns the size of the list (i.e, the how many numbers read)
// ?
// ! Example usage:
// int size;
// double array[20];
// size = readArrayFromFile("myNumberFile.txt", array);

int readArrayFromFile(const char *fileName, double list[])
{
    ifstream fin;
    int count = 0; //The size of the list
    int number;    //The current number read from the file

    fin.open(fileName);

    while (fin >> number)
    {
        list[count] = number;
        count++;
    }
    fin.close();

    return count;

    fin.open(fileName);
}

int main()
{
    char fileName1[20];
    char fileName2[20];

    double list1[10];  // ? To hold the list of numbers read from the first file
    double list2[10];  // ? To hold the list of numbers read from the second file
    int size;          // ? How many numbers read

    cout << "Enter file #1 => ";
    cin >> fileName1;

    cout << "Enter file #2 => ";
    cin >> fileName2;
    
    size = readArrayFromFile(fileName1, list1);
    size = readArrayFromFile(fileName2, list2);
    
    double sum_x = 0;
    double sum_y = 0;
    
    for(int i=0; i<size; i++){
    	sum_x += list1[i];
    	sum_y += list2[i];
	}
	
    double xbar = sum_x / size;
    double ybar = sum_y / size;
    
    double sum = 0;
    
    for(int i=0; i<size; i++){
    	sum += (list1[i] - xbar) * (list2[i] - ybar);
	}
	
	double c = sum / size;

    cout << endl;
    cout << "Covariance = " << c << endl;

    system("pause");

    return 0;
}
