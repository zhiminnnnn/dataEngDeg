// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 3: Find the sum of a list of numbers
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>

using namespace std;

int main()
{
    int m, n;

    cout << "Enter the starting number  => ";
    cin >> m;

    cout << "Enter the ending number  => ";
    cin >> n;
    
    int sum = 0;
    
    if(m<=n){
    	for(int i=m; i<=n; i++){
    		sum += i;
		}
	}
	else{
		for(int i=n; i<=m; i++){
    		sum += i;
		}
	}

    cout << endl;
    cout << "The sum is " << sum << endl;

    system("pause");

    return 0;
}

