#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>
using namespace std;

//handles all payment-related logic
class Payment {
    private:
        double amount;
        string method, details;
    public:
        Payment(double a);
        void selectPaymentMethod();
        bool process();
        string getMethod() const;
};

#endif