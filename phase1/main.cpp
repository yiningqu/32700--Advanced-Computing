#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long int my_factorial(int number){
    if (number < 0) return 0;
    long long int result = 1;
    for (int i = 1; i <= number; ++i){
        result *= i;
    }
    return result;
}

long long int my_addition(long long int number1, long long int number2){
    return number1 + number2;
}


long int my_power(float number1, float number2){
    long int result = 1;
    for(int i = 1; i <= number2; ++i){
        result *= number1;
    }
    return result;
}

double my_average(double* array_numbers, int array_size){
    double result = 0;
    for(int i = 0; i < array_size; ++i){
        result += array_numbers[i];
    }
    return result/array_size;
}

int my_max(int* array_numbers, int array_size){
    int max = 0;
    for(int i = 0; i < array_size; ++i){
        if(max < array_numbers[i]){
            max = array_numbers[i];
        }
    }
    return max;
}

int* my_sort(int* array_numbers, int array_size){
    sort(array_numbers, array_numbers + array_size);
    return array_numbers;
}


int main() {
    int testIndex;
    cin >> testIndex;
    switch(testIndex){
        case 0:{
            int number;
            long long int expected0;
            cin >> number;
            cin >> expected0;
            long long int result0 = my_factorial(number);
            if (result0 == expected0) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            break;  // This break is necessary to prevent fall-through.
        }
        case 1:{
            long long int number1;
            long long int number2;
            long long int expected1;
            cin >> number1;
            cin >> number2;
            cin >> expected1;
            long long int result1 = my_addition(number1, number2);
            if (result1 == expected1) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            break;
        }

        case 2:{
            float a;
            float b;
            long int expected2;
            cin >> a;
            cin >> b;
            cin >> expected2;
            long int result2 = my_power(a,b);
            if (result2 == expected2) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            break;
        }

        case 3:{
            int size;
            cin >> size;
            double* array_numbers = new double[size];
            for (int i = 0; i < size; ++i){
                cin >> array_numbers[i];
            }
            double expected3;
            cin >> expected3;
            double result3 = my_average(array_numbers, size);
            if (result3 == expected3) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            break;
        }

        case 4:{
            int arr_size;
            cin >> arr_size;
            int* arr = new int[arr_size];
            for (int i = 0; i < arr_size; ++i){
                cin >> arr[i];
            }
            int expected4;
            cin >> expected4;
            int result4 = my_max(arr, arr_size);
            if (result4 == expected4) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
            break;
        }

        case 5:{
            int array_size;
            cin >> array_size;
            int* unsort_arr = new int[array_size];

            for (int i = 0; i < array_size; ++i) {
                cin >> unsort_arr[i];
            }

            int* sort_arr = new int[array_size];
            for (int j = 0; j < array_size; ++j) {
                cin >> sort_arr[j];
            }

            int* result5 = my_sort(unsort_arr, array_size);
            bool isPass = true;
            for (int z = 0; z < array_size; ++z) {
                if (result5[z] != sort_arr[z]) {
                    isPass = false;
                    break;
                }
            }

            if (isPass) {
                cout << "PASS" << endl;
            }
            break;
        }


    }
}