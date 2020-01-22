#include<iostream>
#include<cmath>
#include<cassert>

/*
Posons F_1 = 1, F_2 = 2 et pour tout n F_{n+2} = F_{n+1} + F_n
Il est facile de montrer que les termes à valeur pair sont les F_{3n+2} pour tout n. 
On peut par ailleurs vérifier par récurrence que pour tout n F_{3n+2} = F_{3n-1} + F_{3n-4}, donc F_{3n+2} est 
une suite récurrente linéaire homogène d'ordre 2 à coefficients constants. 
On trouve son expression grâce à l'équation caractéristique. En notant r_1 = 2 + sqrt(5) et r_2 = 2 - sqrt(5), on a : 
F_{3n+2} = (1 + 2/sqrt(5))*pow(r_1,n)+(1-2/sqrt(5))*pow(r_2,n)
On déduit donc la somme des termes à val pairs jusqu'à un certain N : 
\sum_{n=0}^N F_{3n+2} = (1 + 2/sqrt(5)) * (1-pow(r_1,N+1))/(1-r_1) + (1-2/sqrt(5)) * (1-pow(r_2,N+1))/(1-r_2)
Il ne reste plus qu'à déterminer la valeur de ce N.
Pour n grand F_{3n+2} est équivalent au terme de gauche dans son expression.
Ainsi, le terme F_{3n+2} dépasse alpha lorsque n > log(alpha/(1+2/sqrt(5)))/log(2+sqrt(5))
On applique avec alpha = 4 million et on trouve N.
 */

int sum_even_fibo_terms(int nmax){
  assert(nmax >= 0);
  double r_1 = 2 + sqrt(5);
  double r_2 = 2 - sqrt(5);
  double A = (1+2/sqrt(5));
  double B = (1-2/sqrt(5));
  double res = A * (1-std::pow(r_1,nmax+1))/(1-r_1) + B * (1-std::pow(r_2,nmax+1))/(1-r_2);
  return res;
}

int sum_even_fibo_under(int alpha){
  assert(alpha>0);
  double r_1 = 2 + sqrt(5);
  double A = (1+2/sqrt(5));
  int nmax=std::floor(std::log(alpha/A)/std::log(r_1));
  return sum_even_fibo_terms(nmax);
}

int main(){
  clock_t begin = clock();

  
  int res = sum_even_fibo_under(4000000);
  std::cout << res << '\n';

  
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  std::cout<<"Execution time :"<<time_spent<< '\n';
  return 0;
}

/*Execution time :6.2e-05
 */
