/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int nextPrime = n + 1;
  while (!isPrime(nextPrime)) {
    ++nextPrime;
  }

  int nextNextPrime = nextPrime + 1;
  while (!isPrime(nextNextPrime)) {
    ++nextNextPrime;
  }

  std::cout << "The next two prime numbers greater than " << n << " are: " << nextPrime << " and " << nextNextPrime << std::endl;

  return 0;
}
