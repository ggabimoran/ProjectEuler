#include<iostream>
#include<string>
#include<cmath>
#include<cassert>

bool is_palindrome(long n){
  std::string str{std::to_string(n)};
  int length = str.length();
  //if string length is odd no need to check middle char for palindrome property
  int halfway = (length % 2 == 0) ? length / 2 : (length -1)/2; 
  std::string::const_iterator it_front;
  std::string::const_reverse_iterator it_back;
  it_front = str.begin();
  it_back = str.rbegin();
  for (int i=0;i<halfway;++i){
    if ((*it_front) != (*it_back)) return false;
    ++it_front;
    ++it_back;
  }
  return true;
}
//largest palindrome made from the product of two ndigits-digit numbers
long largest_palindrome_prod(int ndigits){
  assert(ndigits >=2 && ndigits <= 3);
  long largest_palindrome{};
  long current_prod{};
  int lower_bound = static_cast<int>(std::pow(10,ndigits-1));
  int upper_bound = static_cast<int>(std::pow(10,ndigits));
  for (int i=lower_bound;i<upper_bound;++i){
    //a * b = b * a thus no need to check same product twice
    for (int j=i;j<upper_bound;++j){
      current_prod = i * j;
      if (is_palindrome(current_prod) && current_prod > largest_palindrome) largest_palindrome = current_prod;
    }
  }
  return largest_palindrome;
}

int main(){
  clock_t begin = clock();


  //product operands' number of digits
  int ndigits{3};
  std::cout << largest_palindrome_prod(ndigits) << '\n';
  
  
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout << "Execution time: " << time_spent << '\n';
  return 0;
}
