/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>

int eulerTotientFunction(int p, int q) {
    return (p - 1) * (q - 1);
}

int main() {
    int p, q;

    std::cout << "Enter the first prime number (p): ";
    std::cin >> p;

    std::cout << "Enter the second prime number (q): ";
    std::cin >> q;

    int result = eulerTotientFunction(p, q);
    std::cout << "Euler's totient function of n is: " << result << std::endl;

    return 0;
}
