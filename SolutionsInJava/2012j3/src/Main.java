import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		for (int i =0; i<k;i++) {
			for (int n =0; n<k;n++)
				System.out.print("*");
			for (int n =0; n<k;n++)
				System.out.print("x");
			for (int n =0; n<k;n++)
				System.out.print("*");
			System.out.println();
		}
		for (int i =0; i<k;i++) {
			for (int n =0; n<k;n++)
				System.out.print(" ");
			for (int n =0; n<k;n++)
				System.out.print("x");
			for (int n =0; n<k;n++)
				System.out.print("x");
			System.out.println();
		}
		for (int i =0; i<k;i++) {
			for (int n =0; n<k;n++)
				System.out.print("*");
			for (int n =0; n<k;n++)
				System.out.print(" ");
			for (int n =0; n<k;n++)
				System.out.print("*");
			System.out.println();
		}
		
	}

}
