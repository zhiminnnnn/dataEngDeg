#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
#include <string>
using namespace std;

class CustomerInfo {
    private:
        string name, phone, address;
    public:
        CustomerInfo();
        void inputInfo();
        void display() const;
        string getName() const;
};

#endif