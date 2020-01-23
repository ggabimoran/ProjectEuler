#include<iostream>
#include<cmath>
#include<cassert>

bool is_prime(std::int_fast64_t n){
  if (n <= 1) return false;
  for (int i=2;i<(std::floor(std::sqrt(n))+1);++i)
    if (n % i == 0) return false;
  return true;
}

std::int_fast64_t largest_prime_factor(std::int_fast64_t n){
  assert(n>=2);
  int i=2;
  while (!is_prime(n)){
    //prime factor decomposition ensures i will be prime whenever
    //following statement evaluates to true.
    //second condition ensures while loop termination
    while(n%i == 0 && n!=i) n/=i;
    ++i;
  }
  return n;
}

int main(){
  clock_t begin = clock();

  
  std::cout << largest_prime_factor(600851475143) << '\n';

  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout<<"Execution time :"<<time_spent<<'\n';
  return 0;
}
