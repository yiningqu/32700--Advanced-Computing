#include <iostream>


class Order{
    std::string order_id;
    bool is_bid;
    double price;
    double quantity;
public:

    //constructor
    Order(std::string order_id_,
          bool is_bid_,
          uint64_t quantity_,
          double price_) :
            order_id(order_id_),
            is_bid(is_bid_),
            quantity(quantity_),
            price(price_)
    {
        std::cout << "call constructor for " + order_id << std::endl;
    }

    // destructor
    ~Order(){
        std::cout << "call destructor for " + order_id << std::endl;
    }


    // copy constructor
    Order(const Order &o){
        std::cout << "call copy destructor for " + order_id << std::endl;
        order_id = o.order_id + "_copy";
    }


    double get_price(){
        return price;
    }

    std::string get_order_id(){
        return order_id;
    }


};

void f1(){
    Order o("order1", true, 123, 1.2);  // instance of Order on the stack
}

void f2(){
    Order *o2 = new Order("order2", true, 123, 1.2); // instance of Order on the heap
}


int main() {
    Order o{"order1", true, 123, 1.2};
    Order* o1 = new Order{"order2", true, 123, 1.2};
    Order o2(o);   // o2 = o (copy constructor)

    std::cout << o.get_price() << std::endl;
    std::cout << (*o1).get_price() << std::endl;
    std::cout << o1->get_price() << std::endl;
    std::cout << o.get_order_id() << std::endl;
    delete o1;

    return 0;
}
