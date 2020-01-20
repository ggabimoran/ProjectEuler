#include<iostream>

using namespace std;

/*
La somme en question est égal à :
\sum_{k=1}^333 3k + \sum_{k=1}^199 5k - \sum_{k=1}^66 15k
(on retire les multiples de 15 qui sont comptés 2 fois à gauche)
Puis on applique la formule \sum_{k=1}^N = N(N+1)/2
 */

int main(){
  clock_t begin = clock();
  int s = 3*333*334/2 + 5*199*200/2 - 15*66*67/2;
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  cout<<s<<endl;
  cout<<"Execution time :"<<time_spent<<endl;
  return 0;
}

/*Execution time :3e-06
 */
