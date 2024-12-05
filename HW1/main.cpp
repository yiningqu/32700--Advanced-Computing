
/*
 * Complete the 'pthFactor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER n
 *  2. LONG_INTEGER p
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using std::cout;
using std::endl;


long pthFactor(long n, long p) {
    std::vector<long int> factors;
    double sqrt_n = sqrt(n);

    for(int i = 1; i <= sqrt_n; ++i){
        if (n % i == 0){
            factors.push_back(i);
            long long quotient = n / i;
            if (i != quotient) { // Add the quotient only if it's different from the divisor
                factors.push_back(quotient);
            }
        }
    }
    std::sort(factors.begin(), factors.end());

    if (p <= factors.size()){
        return factors[p-1];
    }
    else{
        return 0;
    }

}


int isPrime(long n) {
    double sqrt_n = sqrt(n);
    int i = 2;
    while (i <= sqrt_n){
        if (n % i == 0){
            return i;
        }
        i += 1;
    }
    return 1;
}



int main() {
//    int result = pthFactor(22876792454961,28);
    int result = isPrime(4);
    cout << result << endl;
}
