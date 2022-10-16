#include <iostream>
#include <map>
#include <vector>

bool Eratosfen[10000000];

void fact(long long a) {
  std::map<int, int> mult;
  std::vector<long long> primes;
  for (int i = 2; i < 1000000; i++) {
    if (!Eratosfen[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= 1000000; j += i) {
        Eratosfen[j] = true;
      }
    }
  }
  for (size_t i = 0; i < primes.size(); ++i) {
    while (a % primes[i] == 0) {
      ++mult[primes[i]];
      a /= primes[i];
    }
  }
  for (auto it = mult.begin(); it!= mult.end(); ++it) {
    if (it != mult.begin()) std::cout << " * ";
    std::cout << (*it).first << '^' << (*it).second;
  }
  std::cout << std::endl;
}