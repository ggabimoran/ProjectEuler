#include<iostream>
#include<cmath>
#include<cassert>

bool is_prime(long n){
  if (n <= 1) return false;
  long bound{std::lround(std::floor(sqrt(n)))};
  for (long i=2;i<bound+1;++i){
    if (n % i == 0) return false;
  }
  return true;
}

//compromise needs to be made, 2,3,5 might be best
int prime_by_rank(int rank){
  assert(rank >= 1);
  int curr_rank{1};
  long prime = 2;
  while (curr_rank < rank){
    ++curr_rank;
    do ++prime;
    while (!is_prime(prime));
  }
  return prime;
}

int main(){
  int rank{10001};
  std::cout << prime_by_rank(rank) << '\n';
  return 0;
}
