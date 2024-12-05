#include <iostream>
using namespace std;

class Order {
public:
    int order_id;
    Order(int oid) : order_id(oid) {
        cout << "Constructor called for Order " << oid << endl;
    }
    ~Order() {
        cout << "Destructor called for Order " << order_id << endl;
    }
};

template <class T>
class shared_smart_ptr {
    T* ptr;  // Pointer to the managed object
    int* ref_count;  // Reference count

public:
    // Constructor
    explicit shared_smart_ptr(T* o = nullptr) : ptr(o), ref_count(new int(1)) {
        if (!ptr) *ref_count = 0;
    }

    // Copy constructor
    shared_smart_ptr(const shared_smart_ptr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ptr) (*ref_count)++;
    }

    // Destructor
    ~shared_smart_ptr() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    // Copy assignment operator
    shared_smart_ptr& operator=(const shared_smart_ptr& other) {
        if (this != &other) {
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    // Accessor for the underlying pointer
    T* get() const { return ptr; }
};

int main() {
    {
        shared_smart_ptr<Order> p1(new Order(1));
        {
            shared_smart_ptr<Order> p2 = p1;
            shared_smart_ptr<Order> p3(p2);
            cout << "Order ID from p3: " << p3.get()->order_id << endl;
        }
    }
    cout << "End of my code" << endl;
    return 0;
}