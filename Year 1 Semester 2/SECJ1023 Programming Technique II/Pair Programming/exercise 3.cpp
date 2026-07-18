// ============================================================
// SECJ1023 - Programming Technique II
// Exercise 3: Inheritance
// Semester 2, 2025/2026
// ============================================================
// Pair Information:
// Member 1 (Name) :  CHENG ZHI MIN
// Member 1 (Matric No.) : A25CS0050
// Member 2 (Name) : NG XUAN YEE
// Member 2 (Matric No.) : A25CS0291
// ------------------------------------------------------------
// Role Declaration:
// Task 1 - Driver: NG XUAN YEE     Navigator: CHENG ZHI MIN
// Task 2 - Driver: CHENG ZHI MIN   Navigator: NG XUAN YEE
// Task 3 - Driver: CHENG ZHI MIN   Navigator: NG XUAN YEE
// Task 4 - Driver: NG XUAN YEE     Navigator: CHENG ZHI MIN
// Task 5 - Driver: NG XUAN YEE     Navigator: CHENG ZHI MIN
// ------------------------------------------------------------
// Both members confirm: the above information is accurate
// and reflects our actual pair programming session.
// ============================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

const int MAX_FF = 2;
const int MAX_MEDIC = 2;
const int MAX_PMF = 1;

class Person{
    protected:
        string name;
        string icNumber;
        string phone;
    
    public:
        void setPerson(string, string, string);
        string getName() const;
        string getIcNumber() const;
        string getPhone() const;
        void displayInfo() const;
};

class Firefighter : virtual public Person{
    private:
        string stationCode;
        int yearsActive;
    
    public:
        void setFirefighter(string, int);
        string getStationCode() const;
        int getYearsActive() const;
        void displayInfo() const;
        string getExperienceLevel() const;
};

class Medic : virtual public Person{
    private:
        string medicalLicenseNo;
        string specialisation;

    public:
        void setMedic(string, string);
        string getMedicalLicenseNo() const;
        string getSpecialisation() const;        
        void displayInfo() const;
};

class ParamedicFirefighter : public Firefighter, public Medic{
    private:
        string badgeID;
        bool isDeployed;
    
    public:
        void setParamedic(string, bool);
        string getBadgeID() const;
        bool getIsDeployed() const;
        void displayInfo() const;
};

void Person::setPerson(string n, string ic, string ph){
    if(n.empty()){
        cout << "Invalid name. Name cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    if(ic.size() != 12){
        cout << "Invalid IC. IC must be exactly 12 digits." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    for(int i=0; i<ic.size(); i++){
        if(!isdigit(ic[i])){
            cout << "Invalid IC. IC must be exactly 12 digits." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
    }
    if(ph.empty()){
        cout << "Invalid phone. Phone number cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    name = n;
    icNumber = ic;
    phone = ph;
}

void Firefighter::setFirefighter(string code, int years){
    if(code.empty()){
        cout << "Invalid station code. Cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    if(years < 0||years > 40){
        cout << "Invalid years active. Must be between 0 and 40." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    stationCode = code;
    yearsActive = years;
}

void Medic::setMedic(string licNo, string spec){
    if(licNo.empty()){
        cout << "Invalid license number. Cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    if(spec.empty()){
        cout << "Invalid specialisation. Cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    medicalLicenseNo = licNo;
    specialisation = spec;
}

void ParamedicFirefighter::setParamedic(string badge, bool deployed){
    if(badge.empty()){
        cout << "Invalid badge ID. Cannot be empty." << endl;
        cout << "Program terminated." << endl;
        exit(1);
    }
    badgeID = badge;
    isDeployed = deployed;
}

string Person::getName() const { return name; }
string Person::getIcNumber() const { return icNumber; }
string Person::getPhone() const { return phone; }

string Firefighter::getStationCode() const { return stationCode; }
int Firefighter::getYearsActive() const { return yearsActive; }
string Firefighter::getExperienceLevel() const{
    if(yearsActive >= 0 && yearsActive <= 5) return "Junior";
    if(yearsActive >= 6 && yearsActive <= 15) return "Experienced";
    return "Senior";
}

string Medic::getMedicalLicenseNo() const { return medicalLicenseNo; }
string Medic::getSpecialisation() const { return specialisation; }

string ParamedicFirefighter::getBadgeID() const { return badgeID; }
bool ParamedicFirefighter::getIsDeployed() const { return isDeployed; }

void Person::displayInfo() const{
    cout << "Name           : " << name << endl;
    cout << "IC Number      : " << icNumber << endl;
    cout << "Phone          : " << phone << endl;
}

void Firefighter::displayInfo() const{
    Person::displayInfo();
    cout << "Station Code   : " << stationCode << endl;
    cout << "Years Active   : " << yearsActive << endl;
    cout << "Experience     : " << getExperienceLevel() << endl;
}

void Medic::displayInfo() const {
    Person::displayInfo();
    cout << "License No     : " << medicalLicenseNo << endl;
    cout << "Specialisation : " << specialisation << endl;
}

void ParamedicFirefighter::displayInfo() const{
    Person::displayInfo();
    cout << "Station Code   : " << getStationCode() << endl;
    cout << "Years Active   : " << getYearsActive() << endl;
    cout << "Experience     : " << getExperienceLevel() << endl;
    
    cout << "License No     : " << getMedicalLicenseNo() << endl;
    cout << "Specialisation : " << getSpecialisation() << endl;
    
    cout << "Badge ID       : " << badgeID << endl;

    if(isDeployed == true) cout << "Status         : Deployed" << endl;
    else cout << "Status         : On Standby" << endl;
}

int main(){
    Firefighter ff[MAX_FF];
    Medic med[MAX_MEDIC];
    ParamedicFirefighter pmf[MAX_PMF];

    string name, ic, ph, code, licNo, spec, badge;
    int years;
    int input;

    for(int i=0; i<MAX_FF; i++){
    	
        cout << "Enter Firefighter " << i + 1 << " name : ";
        getline(cin, name);
        if(name.empty()){
            cout << "Invalid name. Name cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
        
        cout << "Enter Firefighter " << i + 1 << " IC number : ";
        getline(cin, ic);
        if(ic.size() != 12){
            cout << "Invalid IC. IC must be exactly 12 digits." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
        for(int i=0; i<ic.size(); i++){
            if(!isdigit(ic[i])){
                cout << "Invalid IC. IC must be exactly 12 digits." << endl;
                cout << "Program terminated." << endl;
                exit(1);
            }
        }
        
        cout << "Enter Firefighter " << i + 1 <<" phone : ";
        getline(cin,ph);
        if(ph.empty()){
            cout << "Invalid phone. Phone number cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout<<"Enter Firefighter " << i + 1 <<" station code : ";
        getline(cin, code);
        if(code.empty()){
            cout << "Invalid station code. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Firefighter "<< i + 1 <<" years active : ";
        cin >> years;
        cin.ignore();
        if(years < 0 || years > 40){
            cout << "Invalid years active. Must be between 0 and 40." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
        ff[i].setPerson(name, ic, ph);
        ff[i].setFirefighter(code, years);
    }

    for(int i=0; i<MAX_MEDIC; i++){
        cout << "Enter Medic " << i + 1 << " name : ";
        getline(cin, name);
        if(name.empty()){
            cout << "Invalid name. Name cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Medic " << i + 1 << " IC number : ";
        getline(cin, ic);
        if(ic.size() != 12){
            cout << "Invalid IC. IC must be exactly 12 digits." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
        for(int i=0; i<ic.size(); i++){
            if(!isdigit(ic[i])){
                cout << "Invalid IC. IC must be exactly 12 digits." << endl;
                cout << "Program terminated." << endl;
                exit(1);
            }
        }

        cout << "Enter Medic " << i + 1 << " phone : ";     
        getline(cin, ph);
        if(ph.empty()){
            cout << "Invalid phone. Phone number cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Medic " << i + 1 << " license number : ";
        getline(cin, licNo);
        if(licNo.empty()){
            cout << "Invalid license number. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Medic " << i + 1 << " specialisation : ";
        getline(cin, spec);
        if(spec.empty()){
            cout << "Invalid specialisation. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        med[i].setPerson(name, ic, ph);
        med[i].setMedic(licNo, spec);
    }

    for(int i=0; i< MAX_PMF; i++){
        cout << "Enter Paramedic-FF name : ";
        getline(cin, name);
        if(name.empty()){
            cout << "Invalid name. Name cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Paramedic-FF IC number : ";
        getline(cin, ic);
        if(ic.size() != 12){
            cout << "Invalid IC. IC must be exactly 12 digits." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
        for(int i=0; i<ic.size(); i++){
            if(!isdigit(ic[i])){
                cout << "Invalid IC. IC must be exactly 12 digits." << endl;
                cout << "Program terminated." << endl;
                exit(1);
            }
        }

        cout << "Enter Paramedic-FF phone : ";     
        getline(cin, ph);
        if(ph.empty()){
            cout << "Invalid phone. Phone number cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Paramedic-FF station code : ";
        getline(cin, code);
        if(code.empty()){
            cout << "Invalid station code. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Paramedic-FF years active : ";
        cin >> years;
        cin.ignore();
        if(years < 0 || years > 40){
            cout << "Invalid years active. Must be between 0 and 40." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }
		
        cout << "Enter Paramedic-FF license number : ";
        getline(cin, licNo);
        if(licNo.empty()){
            cout << "Invalid license number. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Enter Paramedic-FF specialisation : ";
        getline(cin, spec);
        if(spec.empty()){
            cout << "Invalid specialisation. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout<<"Enter Paramedic-FF badge ID : ";
        getline(cin, badge);
        if(badge.empty()){
            cout << "Invalid badge ID. Cannot be empty." << endl;
            cout << "Program terminated." << endl;
            exit(1);
        }

        cout << "Deployed? (1=Yes, 0=No) : ";
        cin >> input;
        cin.ignore();

        if(input!=0 && input!=1){
            cout << "Invalid deployment status. Must be 1 or 0. " << endl;
            cout <<"Program terminated. " << endl;
            exit(1);
        }

        bool inputBool = false;
        if(input == 1) inputBool = true;

        pmf[i].setPerson(name, ic, ph);
        pmf[i].setFirefighter(code, years);
        pmf[i].setMedic(licNo, spec);
        pmf[i].setParamedic(badge, inputBool);
    }
    
	cout<<"\n=== Firefighter Records ===\n";
    for(int i=0; i<MAX_FF; i++){
        ff[i].displayInfo();
        cout << "----------------------------" << endl;
    }

    cout<<"\n=== Medic Records ===\n";
    for(int i=0; i<MAX_MEDIC; i++){
        med[i].displayInfo();
        cout << "----------------------------" << endl;
    }

    cout<<"\n=== Paramedic-Firefighter Record ===\n";
    for(int i=0; i<MAX_PMF; i++){
        pmf[i].displayInfo();
        cout << "----------------------------" << endl;
    }
    
    return 0;
}

// ============================================================
// REFLECTION
// ============================================================
// Q1 - Error encountered:
//
//   We encountered a small logical error bug when running the code which is after the part where Medic 1 license number is entered.
//   It shows that the program is terminated even after entering a valid license number input.
//   After taking some time to debug, we found out that we forgot to put getline() to read the license number input and also specialisation inside the Medic loop.
//   Same problem and solution also in the ParamedicFirefighter section.
//
// Q2 - Why Person is a virtual base class, and what happens without it:
//
//   Without virtual, ParamedicFirefighter would inherit Person twice, once through Firefighter and once through Medic.
//   This will cause confussion to the compiler if we want to call getName() or displayInfo() because our object would have two different name, icNumber and phone.
//   With virtual public Person, both objects share one copy of Person, so no duplicated data.
//
// Q3 - Most challenging part:
//	 Most challenging part is to construct the main function and also the mutator functions for each class.
//   This is because there are many input validations that are needed in these two sections, so we must be very careful when writing the code.
//   These challenges remind us that input validation is an important aspect in writing a program because it helps the program to run as expected.
//   If not, the program will break if user enters invalid inputs.
//
// ============================================================