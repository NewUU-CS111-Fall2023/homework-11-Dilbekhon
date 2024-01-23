/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>

int gcd(int a, int b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

int phi(int n) {
  if (n == 1) return 0;
  int result = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result = result / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) result = result / n * (n - 1);
  return result;
}

int modinv(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m;
    a = t;
    t = x;
    x = y - q * x;
    y = t;
  }
  if (x < 0) x += m0;
  return x;
}

int main() {
  int p, q;
  std::cout << "Enter two distinct prime numbers: ";
  std::cin >> p >> q;

  int n = p * q;
  int phi_n = phi(n);

  std::cout << "Euler's totient function of " << n << " is: " << phi_n << std::endl;

  int e = 2;
  while (gcd(e, phi_n) != 1) ++e;

  int d = modinv(e, phi_n);

  std::cout << "Public key (e): " << e << std::endl;
  std::cout << "Private key (d): " << d << std::endl;

  return 0;
}
