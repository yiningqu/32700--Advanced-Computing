#include <iostream>
using namespace std;


///OVERRIDE FINAL
//struct Base final()

///Move: transfer to another one without copy constructor

///Static_assert, const_expr

///Difference between Thread and Process:
//Thread: it is created by process, it can access same memory as process
//eg. Chrome is a process, windows opened is thread

//Static Polymorphism
template <typename Derived>
class Order {
protected:
    int q;

public:
    Order(int n) : q(n) {}

    // can use without virtual function
    // reference to derived function
    void display() {
        static_cast<Derived*>(this)->display();
    }
};

class FOK : public Order<FOK> {
public:
    FOK(int n) : Order<FOK>(n) {}

    void display() {
        std::cout << "FOK:" << q << std::endl;
    }
};

class GTC : public Order<GTC> {
public:
    GTC(int n) : Order<GTC>(n) {}

    void display() {
        std::cout << "GTC:" << q << std::endl;
    }
};

int main() {
    FOK fok_order(10);
    GTC gtc_order(20);

    fok_order.display(); // Outputs "FOK:10"
    gtc_order.display(); // Outputs "GTC:20"



    int c = 8;
    auto f1 = [&c] (int a, int b) {c =  a + b; return c;};
    cout << f1(1,2) << endl;

    return 0;
}



///[]: captures the used variables per copy or per reference
///(): is required for parameters
///->: is required for sophisticated lambda functions
///{}: may include expressions and statements
