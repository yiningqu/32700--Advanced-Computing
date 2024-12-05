#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
using std::cin;

using namespace std;


vector<int> generatePowers(int maxVal) {
    vector<int> powers;
    for (int i = 2; i * i <= maxVal; ++i) {
        int power = i * i;
        while (power <= maxVal) {
            powers.push_back(power);
            power *= i;
        }
    }
    powers.push_back(0);
    powers.push_back(1);
    sort(powers.begin(), powers.end());
    return powers;
}

int countPowerNumbers(int l, int r) {
    vector<int> powers = generatePowers(r);
    set<int> powerNumbers;

    for (int p1 : powers) {
        for (int p2 : powers) {
            int sum = p1 + p2;
            if (sum >= l && sum <= r) {
                powerNumbers.insert(sum);
            }
        }
    }

    return powerNumbers.size();
}



int main()
{
    int count = countPowerNumbers(25,30);
    cout << count << endl;
}
