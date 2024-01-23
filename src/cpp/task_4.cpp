/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;

    int lastDigit = b.back();
    b.pop_back();

    int part1 = modPow(a, lastDigit);
    int part2 = modPow(superPow(a, b), 10);

    return (part1 * part2) % 1337;
}

int modPow(int base, int exponent) {
    base %= 1337;
    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result = (result * base) % 1337;
    }

    return result;
}

int main() {
    int a1 = 2;
    vector<int> b1 = {3};

    int a2 = 2;
    vector<int> b2 = {1, 0};

    int a3 = 1;
    vector<int> b3 = {4, 3, 3, 8, 5, 2};

    int result1 = superPow(a1, b1);
    int result2 = superPow(a2, b2);
    int result3 = superPow(a3, b3);

    cout << result1 << endl;  
    cout << result2 << endl;  
    cout << result3 << endl; 

    return 0;
}
