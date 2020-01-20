#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n){
  int i;
  if (n <= 1){
    return 0;
  }
  for (i=2;i<(int)sqrt(n)+1;i++){
    if (n % i == 0){
      return 0;
    }
  }
  return 1;
}

int largest_prime_factor(unsigned long long int n){
  int i=2;
  while (!is_prime(n)){
    while(n%i != 0 || !is_prime(i)){
      i++;
    }
    n = n/i;
  }
  return n;
}

int main(){
  cout<<largest_prime_factor(600851475143)<<endl;
  return 0;
}
