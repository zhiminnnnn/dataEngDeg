#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <string>
using namespace std;

//stores a customer's review for an order
class Feedback {
    private:
        int id;
        int rate;
        string msg;
    public:
        Feedback();
        Feedback(int);
        int getId() const;
        void input();
        void display() const;
};

#endif