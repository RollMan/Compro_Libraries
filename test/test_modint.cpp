#include "modint.hpp"

#include <iostream>
using ll = long long;
const ll MOD = 1000000007;
const ll SIZE = 1000000;
using mint = modint::Modint<ll, MOD, SIZE>;
int main(void){
  mint::initialize();
  mint a(6);
  mint b(2);
  mint c = a + b;
  // std::cout << (a + b).value << std::endl;
  return 0;
}
