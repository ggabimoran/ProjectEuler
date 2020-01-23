#include<iostream>
#include<cmath>
#include<cassert>

bool is_prime(long long n){
  if (n <= 1) return false;
  for (long long i=2;i<(std::llround(std::floor(std::sqrt(n)))+1);++i)
    if (n % i == 0) return false;
  return true;
}

long long largest_prime_factor(long long n){
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


  long long number{600851475143};
  std::cout << largest_prime_factor(number) << '\n';

  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout<<"Execution time :"<<time_spent<<'\n';
  return 0;
}
