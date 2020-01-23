#include<iostream>

int main(){
  clock_t begin = clock();

  
  std::int_fast64_t answer = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
  std::cout << answer << '\n';

  
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout<<"Execution time :"<<time_spent<<'\n';
  return 0;
}
