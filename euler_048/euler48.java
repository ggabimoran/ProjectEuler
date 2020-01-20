public class euler48{
    public static long last10digits(long number){
	String str = Long.toString(number);
	int len = str.length();
	if (len>10){
	    str = str.substring(len-10);
	}
	return Long.parseLong(str);
    }
    public static long l10d_mult10dnum(long n1,long n2){
	long first[]=new long[10];
	for (int i=9;i>=0;i--){
	    first[i]=n1 % 10;
	    n1=n1/10;
	}
	long prod=0;
	for (int j=9;j>=0;j--){
	    prod+=(first[j]*n2 % Math.pow(10,j+1))*Math.pow(10,9-j);
	}
	return last10digits(prod);
    }
    public static long last10digits_iterative_power(long x,int y){
	long res = 1;
	long a=x;
	int b=y;
	while (b>1){
	    if (b%2==1){
		res = l10d_mult10dnum(res,a);
	    }
	    a = l10d_mult10dnum(a,a);
	    b = b / 2;
	}
	res = l10d_mult10dnum(res,a);
	return res;
    }
    public static long euler48(int max){
	long sum=0;
	for (int k=1;k<max+1;k++){
	    sum+=last10digits_iterative_power(k,k);
	    sum=last10digits(sum);
	}
	return sum;
    }
    public static void main(String args[]){
	long startTime = System.currentTimeMillis();
	System.out.println(euler48(1000));
	long endTime = System.currentTimeMillis();
	long elapsedTime = endTime - startTime;
	System.out.println("Execution time : " + elapsedTime + " ms");
    }
}
/*Execution time : 44 ms*/
