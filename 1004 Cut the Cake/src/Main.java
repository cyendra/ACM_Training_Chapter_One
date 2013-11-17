import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger fz,fm,m,t;
		int n;
		int T;
		Scanner cin=new Scanner(System.in);
		T=cin.nextInt();
		for (int lp=0;lp<T;lp++){
			m=cin.nextBigInteger();
			n=cin.nextInt();
			fm=BigInteger.valueOf(1);
			for (int i=0;i<n-1;i++){
				fm=fm.multiply(m);
			}
			fz=BigInteger.valueOf(n);
			t=fz.gcd(fm);
			fz=fz.divide(t);
			fm=fm.divide(t);
			System.out.println(fz+"/"+fm);
		}
	}

}
