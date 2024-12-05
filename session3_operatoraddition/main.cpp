#include <iostream>
#include <string>

class Trader{
public:
    std::string name;
    Trader(std::string name_): name(name_) {}
    // Copy constructor for Trader to handle deep copy.
    Trader(const Trader& other): name(other.name) {}
};


class PrivateOrder{
public:
    PrivateOrder(int a_, int b_): a(a_), b(b_){};
    int b;
    int a;
};


class Order{
public:
    Trader* trader;
    int quantity;
    // Constructor initializes members and allocates a new Trader.
    Order(Trader* trader_, int quantity_): trader(new Trader(*trader_)), quantity(quantity_) {}
    // Copy constructor for deep copy.
    Order(const Order& o): trader(new Trader(*o.trader)), quantity(o.quantity) {}
    // Destructor to handle dynamic memory cleanup.
    virtual ~Order() { delete trader; }
    // Assignment operator for deep copy and self-assignment guard.
    Order& operator=(const Order& o){
        if (this != &o) { // Self-assignment check
            *trader = *o.trader; // Assuming Trader has an assignment operator.
            quantity = o.quantity;
        }
        return *this;
    }
    // Addition operator
    Order operator+(const Order& o) const {
        return Order(trader, quantity + o.quantity);
    }
    // Prefix increment
    Order& operator++(){
        quantity++;
        return *this;
    }   // ++o1 this one is faster 因为不需要copy constructor

    // Postfix increment
    Order operator++(int){
        Order temp = *this;
        ++(*this);
        return temp;
    }

    // Virtual display function for polymorphism.
    virtual void display() const {
        std::cout << "Order(" << quantity << ")" << std::endl;
    }
};

class GTCOrder : public Order{
public:
    int date;
    GTCOrder(Trader* trader_, int quantity_, int date_): Order(trader_, quantity_), date(date_) {}
    // Overriding display function.
    void display() const {
        std::cout << "GTCOrder(" << quantity << ", " << date << ")" << std::endl;
    }
};

class IcebergOrder : public Order {
public:
    int att1;
    int additional_quantity;
    IcebergOrder(Trader* trader_, int quantity_, int att1_, int aq) :
            Order(trader_, quantity_), att1(att1_), additional_quantity(aq) {}

    void display() {
        std::cout << "IcebergOrder(" << quantity << " " << att1
                  << " " << additional_quantity
                  << ")" << std::endl;
    }
};


int main() {
//    //    Trader t1("seb");
//    //    Order o1(&t1,100);
//    //    Order o2(o1);
//    //    Order o3=o1; // <==> Order o3(o1);
//    //    o3 = o1 = o2; // <==> o3.operator=(o1.operator=(o2));
//    //    o2.trader->name="nic";
//    //    printf("address of the trader:%p\n", o1.trader);
//    //    printf("address of the trader:%p\n", o2.trader);
//    //    std::cout  << "name of o1 trader:" << o1.trader->name << std::endl;
//    //    std::cout  << "name of o2 trader:" << o2.trader->name << std::endl;
//    Trader t1("Seb");
//    GTCOrder gtc1(&t1, 100, 1);
//    gtc1.display();
//    Order *o1 = &gtc1;
//    o1->display(); // This will now properly call GTCOrder's display thanks to polymorphism.
//
//
//    // Static cast: used with inheritance
//    //  - excute cast at compile time
//    //  - eg. convert double to int (faster, less safe)
//    GTCOrder* objDer = static_cast<GTCOrder*>(o1);
//    objDer->display();
//    IcebergOrder* io1 = static_cast<IcebergOrder*>(o1);
//    io1->display();
//
//    Trader* objDer2 = reinterpret_cast<Trader *>(o1);
//    // <===> Trader* objDer2 = (Trader *)o1;
//
//    //Dynamic Cast:
//    //  - opposite of static casting
//    //  - execute cast at runtime
//    if(dynamic_cast<GTCOrder*>(o1))
//        GTCOrder* o1 = dynamic_cast<GTCOrder*>(o1);
//        std::cout << "this is GRCOrder" << std::endl;
//        o1->display();
//    if(dynamic_cast<IcebergOrder*>(o1))
//        std::cout << "this is IcebergOrder" << std::endl;


    //Use cast to access PrivateOrder variables a and b
    PrivateOrder po1(1,2);
    po1.a;
    po1.b;
    int* temppointer = reinterpret_cast<int *>(&po1);
    *temppointer = 66;
    *(temppointer + 1) = 67;
    printf("a%d, b:%d\n", po1.a, po1.b);

}