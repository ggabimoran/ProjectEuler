#include<iostream>
#include<cmath>
#include<list>
#include<string>

using namespace std;

// to find sum of self powers we use two properties :
// if a congru a' modulo N and b congru b' modulo N
// then 1 : a + b congru to a' + b' modulo N
// in other words since a % 10^n is the last n digits of a
// the l10d (last 10 digits) of a + b is l10d(l10d(a)+l10d(b))
// in other words finding l10d of sum equivalent to finding l10d for each term
// and 2 : a * b  congru to a' * b' modulo N
// in other words l10d(a * b) is l10(l10d(a)*l10d(b))
// We use this to find l10d(x^y) iteratively

//must use double : unsigned long int not long enough
unsigned long long int last10digits(unsigned long long int number){
  string s=to_string(number);
  if (s.length() > 10){
    s.erase(0,s.length()-10);
  }
  return stoull(s);
}

//in c++ pow uses exp and ln -> double therefore value is approximative
//and iterative power is more precise ex : 17^13
//but is limited by max length of unsigned long long int
unsigned long long int iterative_power(int x,int y){
  if (y<0){
    return (1/iterative_power(x,-y));
  }
  if (y==0){
    return 1;
  }
  else{
    unsigned long long int a=(double)x;
    int b=y;
    unsigned long long int res=1;
    //@loop invariant : se démontre récursivement que c'est a^b * res = x^y
    while (b>1){
      if (b%2==1){
	res = res * a;
      }
      a = a * a;
      b = b / 2;
    }
    res = res * a;
    return res;
  }
}

//9999999999*9999999999 is greater than unsigned long long int max
unsigned long long int l10d_mult10dnumbers(unsigned long long int a,unsigned long long int b){
  int first[10];
  int i;
  for (i=9;i>=0;i--){
    if (a!=0){
      first[i]=a%10;
      a=a/10;
    }
    else{
      first[i]=0;
    }
  }
  i=9;
  unsigned long long int prod=0;
  for (i=9;i>=0;i--){
    prod+=((first[i] * b) % (unsigned long long int)pow(10,i+1))*pow(10,9-i);
  }
  return last10digits(prod);
}

//function identical to iterative_power except we must truncate
//to l10d at each loop
//must change to double, unsigned long int not long enough
unsigned long long int last10digits_iterative_power(int x, int y){
  if (y<0){
    return (1/iterative_power(x,-y));
  }
  if (y==0){
    return 1;
  }
  else{
    unsigned long long int a=(unsigned long long int)x;
    int b=y;
    unsigned long long int res=1;
    while (b>1){
      if (b%2==1){
	res = l10d_mult10dnumbers(res,a);
      }
      a = l10d_mult10dnumbers(a,a);
      b = b / 2;
    }
    res = l10d_mult10dnumbers(res,a);
    return res;
  }
}

double euler48(int max){
  unsigned long long int s=0;
  int k;
  for (k=1;k<max+1;k++){
    s+=last10digits_iterative_power(k,k);
    s=last10digits(s);
  }
  return s;
}

int main(){
  clock_t begin=clock();
  cout.precision(25);
  cout<<euler48(1000)<<endl;
  clock_t end=clock();
  double time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
  cout<<"Execution time :"<<time_spent<<endl;
  return 0;
}

//Execution time :0.04452699999999999713740095
