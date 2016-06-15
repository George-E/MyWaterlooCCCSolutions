
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int length = 2;
		int a = in.nextInt();
		int b = in.nextInt();
		int x = 0 ;
		while (a>=b) {
			length++;
			a -= b;
			x = b;
			b = a;
			a = x;
		}
		System.out.println(length);
	}

}
