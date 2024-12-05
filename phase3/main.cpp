enum ordertype {LIMIT, MARKET};

enum side {BUY, SELL};


class Order{

public:
    // Constructor
    Order(long timestamp_, side Side_, unsigned int id_, unsigned int price_, unsigned int quantity_,
          const char *venue_, const char *symbol_, ordertype type_) : timestamp(timestamp_), Side(Side_), id(id_),
                                                                      price(price_), quantity(quantity_), type(type_) {
        strncpy(venue, venue_, sizeof(venue) - 1);
        strncpy(symbol, symbol_, sizeof(symbol) - 1);
        venue[sizeof(venue) - 1] = '\0';
        symbol[sizeof(symbol) - 1] = '\0';
    }

    // Getters and Setters
    char* getVenue() { return venue; }
    char* getSymbol() { return symbol; }
    unsigned int getID() { return id; }
    ordertype getOrderType() { return type; }
    unsigned int getQuantity() { return quantity; }
    unsigned int getPrice() { return price; }
    void setVenue(const char *venue_) { strncpy(venue, venue_, sizeof(venue) - 1); venue[sizeof(venue) - 1] = '\0'; }
    void setQuantity(unsigned int quantity_) { quantity = quantity_; }

    // Validation
    bool is_valid() {
        return price >= 0 && quantity >= 0 && venue[0] != '\0';
    }

private:
    long timestamp;
    side Side;
    unsigned int id;
    unsigned int price;
    unsigned int quantity;
    char venue[20];
    char symbol[20];
    ordertype type;

};

class OrderBook{

private:
    Order* order_bids[20] = {nullptr};
    Order* order_offers[20] = {nullptr};
    int number_of_bids = 0;
    int number_of_offers = 0;

public:
    OrderBook() {}

    ~OrderBook() {
        clearBooks();
    }

    bool add_order(long timestamp_, side side_, unsigned int id_, unsigned int price_,
                   unsigned int quantity_, const char* venue_, const char* symbol_, ordertype type_) {
        Order *newOrder = new Order(timestamp_, side_, id_, price_, quantity_, venue_, symbol_, type_);
        if (side_ == BUY) {
            if (order_bids[id_] == nullptr && id_ < 20) {
                order_bids[id_] = newOrder;
                number_of_bids++;
                return true;
            }
        } else {
            if (order_offers[id_] == nullptr && id_ < 20) {
                order_offers[id_] = newOrder;
                number_of_offers++;
                return true;
            }
        }
        delete newOrder; // Clean up if not added
        return false;
    }

    bool modify_order(side side_, unsigned int id_, unsigned int quantity_) {
        Order* order = (side_ == BUY) ? order_bids[id_] : order_offers[id_];
        if (order != nullptr && id_ < 20) {
            order->setQuantity(quantity_);
            return true;
        }
        return false;
    }

    bool remove_order(side side_, unsigned int id_) {
        Order** orderArray = (side_ == BUY) ? order_bids : order_offers;
        if (orderArray[id_] != nullptr && id_ < 20) {
            delete orderArray[id_];
            orderArray[id_] = nullptr;
            return true;
        }
        return false;
    }

    void clearBooks() {
        for (int k = 0; k < 20; k++) {
            if (order_bids[k] != NULL) {
                delete order_bids[k];
                order_bids[k] = NULL;
                number_of_bids--;
            }
            if (order_offers[k] != NULL) {
                delete order_offers[k];
                order_offers[k] = NULL;
                number_of_offers--;
            }
        }
    }

    Order* getOrderBids(int a) {
        return (a < 20) ? order_bids[a] : nullptr;
    }

    Order* getOrderOffers(int a) {
        return (a < 20) ? order_offers[a] : nullptr;
    }

    int getNumberOfBids() {
        return number_of_bids;
    }

    int getNumberOfOffers() {
        return number_of_offers;
    }
};