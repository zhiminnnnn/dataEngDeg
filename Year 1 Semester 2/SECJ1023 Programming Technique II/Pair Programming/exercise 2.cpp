// ============================================================
// SECJ1023 - Programming Technique II
// Exercise 2: Association, Aggregation & Composition
// Semester 2, 2025/2026
// ============================================================
// Pair Information:
// Member 1 (Name) : CHENG ZHI MIN
// Member 1 (Matric No.) : A25CS0050
// Member 2 (Name) : NG XUAN YEE
// Member 2 (Matric No.) : A25CS0291
// ------------------------------------------------------------
// Role Declaration:
// Task 1 - Driver: CHENG ZHI MIN   Navigator: NG XUAN YEE
// Task 2 - Driver: NG XUAN YEE     Navigator: CHENG ZHI MIN
// Task 3 - Driver: CHENG ZHI MIN   Navigator: NG XUAN YEE
// Task 4 - Driver: NG XUAN YEE     Navigator: CHENG ZHI MIN
// Task 5 - Driver: CHENG ZHI MIN   Navigator: NG XUAN YEE
// ------------------------------------------------------------
// Both members confirm: the above information is accurate
// and reflects our actual pair programming session.
// ============================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_PETS = 3;

class Vaccine{
    private:
        string vaccineName;
        int doseNumber;
        double costPerDose;
    public:
        bool setVaccine(string, int, double);
        string getVaccineName() const;
        int getDoseNumber() const;
        double getCostPerDose() const;
        double totalDoseCost() const;
};

class PetRecord{
    private:
        string petNames[MAX_PETS];
        string ownerNames[MAX_PETS];
        double weights[MAX_PETS];
        Vaccine vaccines[MAX_PETS];
    public:
        bool setDetails(int, string, string, double);
        string getPetName(int) const;
        string getOwnerName(int) const;
        double getWeight(int) const;
        bool needsBooster(int) const;
        double totalCost() const;
        void displayRecord() const;
        Vaccine& getVaccine(int index);
};

bool Vaccine::setVaccine(string vName, int dose, double cost){
    if(dose < 1 || dose > 3){
        cout << "Invalid dose. Dose number must be 1, 2, or 3." << endl;
        return false;
    }
    if(cost <= 0){
        cout << "Invalid cost. Cost must be greater than RM0.00." << endl;
        return false;
    }
    vaccineName = vName;
    doseNumber = dose;
    costPerDose = cost;
    return true;
}

bool PetRecord::setDetails(int index, string pet, string owner, double weight){
    if(weight <= 0){
        cout << "Invalid weight. Weight must be greater than 0." << endl;
        return false;
    }
    petNames[index] = pet;
    ownerNames[index] = owner;
    weights[index] = weight;
    return true;
}

string Vaccine::getVaccineName() const{
    return vaccineName;
}

int Vaccine::getDoseNumber() const{
    return doseNumber;
}

double Vaccine::getCostPerDose() const{
    return costPerDose;
}

double Vaccine::totalDoseCost() const{
    return costPerDose * doseNumber;
}

string PetRecord::getPetName(int index) const{
    return petNames[index];
}

string PetRecord::getOwnerName(int index) const{
    return ownerNames[index];
}

double PetRecord::getWeight(int index) const{
    return weights[index];
}

bool PetRecord::needsBooster(int index) const{
    return (vaccines[index].getDoseNumber()<3);
}

double PetRecord::totalCost() const{
    double total = 0.0;
    for(int i = 0; i < MAX_PETS; i++){
        total += vaccines[i].totalDoseCost();
    }
    return total;
}

void PetRecord::displayRecord() const{
    cout << "============= Pet Clinic Report =============" << endl;
    cout << left
         << setw(10) << "Pet"
         << setw(15) << "Owner"
         << setw(8) << "Wt(kg)"
         << setw(12) << "Vaccine"
         << setw(6) << "Dose"
         << setw(12) << "Cost/Dose"
         << setw(10) << "Total"
         << "Status" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);
    
    for(int i=0; i<MAX_PETS; i++){
        string status;
        if(needsBooster(i)) status = "Booster needed";
        else status = "Vaccination complete";
        cout << left
             << setw(10) << petNames[i]
             << setw(15) << ownerNames[i]
             << setw(8) << weights[i]
             << setw(12) << vaccines[i].getVaccineName()
             << setw(6) << vaccines[i].getDoseNumber()
             << "RM " << left << setw(8) << vaccines[i].getCostPerDose()
             << "RM " << left << setw(8) << vaccines[i].totalDoseCost()
             << status << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Total vaccination cost for all pets: RM " << totalCost() << endl;
    cout << "===========================================" << endl;
}

Vaccine& PetRecord::getVaccine(int index){
    return vaccines[index];
}

int main(){
    PetRecord clinic;

    for(int i=0; i<MAX_PETS; i++){
        string pName, owner, vName;
        double weight, cost;
        int doseNum;

        cout << "Enter pet " << i+1 << " name: ";
        getline(cin, pName);

        cout << "Enter pet " << i+1 << " owner name: ";
        getline(cin, owner);
        
        cout << "Enter pet " << i+1 << " weight (kg): ";
        cin >> weight;
        cin.ignore();

        if(!clinic.setDetails(i, pName, owner, weight)) return 0;

        cout << "Enter vaccine name: ";
        getline(cin, vName);

        cout << "Enter dose number (1-3): ";
        cin >> doseNum;
        cin.ignore();

        cout << "Enter cost per dose (RM): ";
        cin >> cost;
        cin.ignore();

        if(!clinic.getVaccine(i).setVaccine(vName, doseNum, cost)) return 0;
        
        cout << endl;
    }
    
    clinic.displayRecord();

    return 0;
}

// ============================================================
// REFLECTION
// ============================================================
// Q1 - Error encountered:
/*
	While implementing the main() function, we faced an issue to find the correct placement for cin.ignore()
	to prevent string prompts being skipped. Unfortunately, after testing it on almost every single line, 
	the program still could not compile successfully in VS code (It stated "Compilation failed"). Both of us
	agreed that the compilation behavior was highly inconsistent because it would compile successfully for a
	while and randomly fail to compile moments later without changing any code. Out of options, we copy our code and paste 
	into Dev-C++ and compile the code. Surprisingly, the program compiled successfully without any errors!

*/
// Q2 - Relationship between the two classes:
/*
	The relationship between the 2 classes is composition. It is because PetRecord class contains an array
	of Vaccine objects as a private data member (as shown in Line 48 -- Vaccine vaccines[MAX_PETS]). Thus,
	Vaccine object cannot exist independently outside of PetRecord class. If PetRecord is destroyed,
	Vaccine will also delete automatically.

*/
// Q3 - Most challenging part:
/*
	The most challenging part was the Part 5 iii) which required to call the setVaccine() function directly
	inside the main() function. Since vaccines is a private member inside the PetRecord class, we cannot
	call it directly from main() function. Thus, we worked through this by creating a public accessor function
	as shown in Line 57 (Vaccine& getVaccine(int index)). This function will return a reference to the 
	Vaccine object. As a result, this allow us to call the mutator function in the main() function.
*/
// ============================================================