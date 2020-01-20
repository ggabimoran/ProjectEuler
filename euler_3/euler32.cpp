#include<iostream>
#include<string>
#include<list>
#include<cmath>

using namespace std;

/*
It is easy to show that there are necessarily 5 digits on the product side (and 4 on the right-hand side). Therefore, for all permutations of the 9 digits, check if 2 x 3 = 5 or if 1 x 4 = 5
Permutation algorithm could be improved
 */

int is_pandigital_prod(char expr[]){
  char leftmult[3]={expr[0],expr[1],'\0'};
  char rightmult[4]={expr[2],expr[3],expr[4],'\0'};
  char result[5]={expr[5],expr[6],expr[7],expr[8],'\0'};
  char leftmultbis[2]={expr[0],'\0'};
  char rightmultbis[5]={expr[1],expr[2],expr[3],expr[4],'\0'};
  if (stoi(string(leftmult))*stoi(string(rightmult)) == stoi(string(result))){
    return 1;
  }
  if (stoi(string(leftmultbis))*stoi(string(rightmultbis)) == stoi(string(result))){
    return 1;
  }
  return 0;
}

void sloppy_permutations(){
  int i1,i2,i3,i4,i5,i6,i7,i8,i9;
  list<int> mylist;
  list<int>::iterator it;
  list<int>::iterator it2;
  it = mylist.begin();
  char digits[10]={'1','2','3','4','5','6','7','8','9','\0'};
  char expression[10]={'1','2','3','4','5','6','7','8','9','\0'};
  char answer[5]={'0','0','0','0','\0'};
  for (i1=0;i1<9;i1++){
    for (i2=0;i2<9;i2++){
      for (i3=0;i3<9;i3++){
	for (i4=0;i4<9;i4++){
	  for (i5=0;i5<9;i5++){
	    for (i6=0;i6<9;i6++){
	      for (i7=0;i7<9;i7++){
		for (i8=0;i8<9;i8++){
		  for (i9=0;i9<9;i9++){
		    if (i1 != i2 && i1 != i3 && i1 != i4 && i1 != i5 && i1 != i6 && i1 != i7 && i1 != i8 && i1 != i9 && i2 != i3 && i2 != i4 && i2 != i5 && i2 != i6 && i2 != i7 && i2 != i8 && i2 != i9 && i3 != i4 && i3 != i5 && i3 != i6 && i3 != i7 && i3 != i8 && i3 != i9 && i4 != i5 && i4 != i6 && i4 != i7 && i4 != i8 && i4 != i9 && i5 != i6 && i5 != i7 && i5 != i8 && i5 != i9 && i6 != i7 && i6 != i8 && i6 != i9 && i7 != i8 && i7 != i9 && i8 != i9){
		      expression[0]=digits[i1];
		      expression[1]=digits[i2];
		      expression[2]=digits[i3];
		      expression[3]=digits[i4];
		      expression[4]=digits[i5];
		      expression[5]=digits[i6];
		      expression[6]=digits[i7];
		      expression[7]=digits[i8];
		      expression[8]=digits[i9];
		      if (is_pandigital_prod(expression)){
			answer[0]=expression[5];
			answer[1]=expression[6];
			answer[2]=expression[7];
			answer[3]=expression[8];
			mylist.insert(it,stoi(string(answer)));
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  int sum=0;
  for (it=mylist.begin() ; it != mylist.end() ; it ++){
    for (it2=it ; it2 != mylist.end() ; it2++){
      if (it != it2 && *it == *it2){
	sum -= *it;
      }
    }
  }
  for (it=mylist.begin() ; it != mylist.end() ; it++){
    cout<<*it<<endl;
    sum+=*it;
  }
  cout<<"Sum of pandigital products :"<<sum<<endl;
}

	
int main(){
  clock_t begin = clock();
  sloppy_permutations();
  clock_t end = clock();
  double time_spent = (double) (end-begin)/CLOCKS_PER_SEC;
  cout<<"Execution time :"<<time_spent<<endl;
  return 0;
}


/*Execution time :1.94467
 */
