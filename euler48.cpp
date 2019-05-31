#include<iostream>
#include<cmath>

using namespace std;

int main(){
  clock_t begin=clock();
  long int number=0;
  int i;
  for (i=1;i<11;i++){
    number+=pow(i,i);
  }
  clock_t end=clock();
  double time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
  cout<<number<<endl;
  cout<<"Execution time :"<<time_spent<<endl;
  return 0;
}
