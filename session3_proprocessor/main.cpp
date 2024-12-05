#include <iostream>
using namespace std;

//Preprocessors
//  - runs before the compiler starts
//  - eg. define & inputs are preprocessors

//template T can accept any type:
// compilation time increases, but runtime decreases
template<typename T1, typename T2>
T1 add(T1 x, T2 y){
    return x+y;
}

template <typename T>
class my_vector{
private:
    T* elements;
    int num_elements;
    int size;
public:
    my_vector(int size){
        this->size = size;
        num_elements = 0;
        elements = new T[size];
    }

    void push_back(T element){
        if (num_elements < size){
            elements[num_elements] = element;
            num_elements++;
            return;
        }

        if (size == 0){
            size = 1;
            T* new_elements = new T[1];
            new_elements[0] = element;
            elements = new_elements;
            return;
        }

        T* new_elements = new T[size*2];
        for (int i=0;i<size;i++){
            new_elements[i] = elements[i];
        }

        delete elements;
        elements = new_elements;
        size = size * 2;
        elements[num_elements] = element;
        num_elements++;
    }
};



int main() {
    string a = "seb";
    string b = "don";
    int aa = 1;
    int bb = 2;
    cout << add(a,b) << endl;
    // don't need to use add<string> or add<int>
    cout << add(aa,bb) << endl; // output is int
    cout << add<float, int>(aa,bb) << endl; // output is float

//    my_vector<int> tab;
//    my_vector<int *> tab2;
//    my_vector<char> tab3;
}
