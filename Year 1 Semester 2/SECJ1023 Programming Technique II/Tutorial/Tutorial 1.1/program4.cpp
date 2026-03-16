// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 4: Date conversion 1
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int d, m, y;  // Day, Month, Year
    string month;

    cout << "Enter your DOB (dd mm yy) => ";
    cin >> d >> m >> y;
    
    switch (m){
    	case 1:
    		month = "Jan";
    		break;
    	case 2:
    		month = "Feb";
    		break;
    	case 3:
    		month = "Mar";
    		break;
    	case 4:
    		month = "Apr";
    		break;
    	case 5:
    		month = "May";
    		break;
    	case 6:
    		month = "Jun";
    		break;
    	case 7:
    		month = "Jul";
    		break;
    	case 8:
    		month = "Aug";
    		break;
    	case 9:
    		month = "Sep";
    		break;
    	case 10:
    		month = "Oct";
    		break;
    	case 11:
    		month = "Nov";
    		break;
    	case 12:
    		month = "Dec";
    		break;
    	default:
    		cout << "Invalid month. " << endl;
	}

    cout << endl;
    cout << "Your Date of Birth is " << month << " " << d << ", 20" << y << endl;

    system("pause");

    return 0;
}

