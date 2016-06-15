import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int gates = in.nextInt();
		int planes = in.nextInt();
		boolean[] full = new boolean[gates];
		int counter = 0;
		Loop:
		for (int i =0; i<planes;i++) {
			int request = in.nextInt()-1;
			for (int n = request; n >= 0; n-- ) {
				if (full[n] == false) {
					full[n] = true;
					counter++;
					continue Loop;
				}
			}
			break Loop;
		}
		System.out.println(counter);
	}
}
