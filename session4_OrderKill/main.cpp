#include <iostream>

using namespace std;

class Order {
    int order_id;
public:
    Order(int oid) : order_id(oid) {
        cout << "Constructor called for Order " << oid << endl;
    }
    ~Order() {
        cout << "Destructor called for Order " << order_id << endl;
    }
};


class OrderKiller {
    Order *ptr;
public:
    // Constructor
    OrderKiller(Order *o) : ptr(o) {}

    // Destructor
    ~OrderKiller() {
        delete ptr;
        ptr = nullptr;  // Avoid dangling pointer
    }

    // Delete copy constructor and copy assignment operator
    OrderKiller(const OrderKiller&) = delete;
    OrderKiller& operator=(const OrderKiller&) = delete;
};

int main() {
    {
        Order *o1 = new Order(1);
        OrderKiller ok1(o1); // OrderKiller will manage the Order's lifetime
    } // `ok1` goes out of scope here, `Order` is destroyed

    cout << "End of my code" << endl;
    return 0;
}