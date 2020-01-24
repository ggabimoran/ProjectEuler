#include<iostream>

//sum of squares of first n natural numbers
long sum_of_squares(int n){return (n * (n +1 ) * (2 * n + 1) / 6);}

long square_of_sum(int n){
  long sum{n * (n+1) / 2};
  return sum * sum;
}

int main(){
  long ssq{sum_of_squares(100)};
  long sqs{square_of_sum(100)};
  std::cout << (sqs - ssq) << '\n';
  return 0;
}
