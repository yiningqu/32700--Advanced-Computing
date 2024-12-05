class WagonR: public Car{
public:
    int mileage;
    WagonR(int mileage_): Car(false, "4"), mileage(mileage_){};

    string getMileage(){
        return to_string(mileage) + " kmpl";
    }

};

/**
*   HondaCity class
**/
class HondaCity: public Car{
public:
    int mileage;
    HondaCity(int mileage_): Car(true, "4"), mileage(mileage_){};

    string getMileage(){
        return to_string(mileage) + " kmpl";
    }

};
/**
*   InnovaCrysta class
**/
class InnovaCrysta: public Car{
public:
    int mileage;
    InnovaCrysta(int mileage_): Car(false, "6"), mileage(mileage_){};

    string getMileage(){
        return to_string(mileage) + " kmpl";
    }

};
