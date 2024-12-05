//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//
//long pthFactor(long n, long p) {
//    std::vector<long int> factors;
//    double sqrt_n = sqrt(n);
//
//    for(int i = 1; i <= sqrt_n; ++i){
//        if (n % i == 0){
//            factors.push_back(i);
//            long long quotient = n / i;
//            if (i != quotient) {
//                factors.push_back(quotient);
//            }
//        }
//    }
//    std::sort(factors.begin(), factors.end());
//
//    if (p <= factors.size()){
//        return factors[p-1];
//    }
//    else{
//        return 0;
//    }
//
//}