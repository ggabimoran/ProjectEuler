#include<iostream>
#include<cmath>
#include<vector>
#include<cassert>

//linear search for element index
int vector_search_idx(std::vector<int>& vect,int length, int x){
  for (int k=0;k<length;++k){
    if (vect[k]==x) return k;
  }
  assert(false);
}

void update_prime_factors(int n,std::vector<int>& pr_fact,std::vector<int>& pr_fact_mult){
  assert(n>=2);
  int length=pr_fact.size();
  int prime{2};
  int mult{};
  int prime_idx{};
  while (n>1){
    if (n % prime == 0){
      if (length == 0 || pr_fact[length-1] != prime){
	pr_fact.push_back(prime);
	pr_fact_mult.push_back(0);
	++length;
      }
      mult=0;
      while (n % prime == 0) {
	n/=prime;
	++mult;
      }
      prime_idx=vector_search_idx(pr_fact,length,prime);
      pr_fact_mult[prime_idx]=std::max(mult,pr_fact_mult[prime_idx]);
    }
    ++prime;
  }
}

//smallest evenly divisible number by all numbers from 2 to max
long smallest_evenly_divisible(int max){
  assert(max>=2);
  std::vector<int> prime_factors;
  std::vector<int> prime_factors_mult;
  for (int i=2;i<max+1;++i){
    update_prime_factors(i,prime_factors,prime_factors_mult);
  }
  int length=prime_factors.size();
  int prod{1};
  for (int i=0;i<length;++i) prod *= std::pow(prime_factors[i],prime_factors_mult[i]);
  return prod;
}

int main(){
  clock_t begin = clock();

  
  long answer = smallest_evenly_divisible(20);
  std::cout << answer << '\n';
  
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout<<"Execution time :"<<time_spent<<'\n';
  return 0;
}
