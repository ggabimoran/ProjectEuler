#include<iostream>
#include<cassert>

using namespace std;

/*
La somme en question est égal à :
\sum_{k=1}^333 3k + \sum_{k=1}^199 5k - \sum_{k=1}^66 15k
(on retire les multiples de 15 qui sont comptés 2 fois à gauche)
Puis on applique la formule \sum_{k=1}^N = N(N+1)/2
 */

int sum_mult_under(int multiple,int bound){
  assert(multiple!=0);
  int quotient=bound/multiple;
  int n_terms=(bound % multiple == 0) ? (quotient - 1) : quotient;
  return (multiple * n_terms * (n_terms + 1) / 2);
}

int main(){
  clock_t begin = clock();

  
  int bound=1000;
  int res = sum_mult_under(3,bound) + sum_mult_under(5,bound) - sum_mult_under(15,bound);
  cout<< res <<endl;

  
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  cout<<"Execution time :"<<time_spent<<endl;
  return 0;
}

/*Execution time :3e-06
 */
