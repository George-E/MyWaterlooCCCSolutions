
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("How many antennas?");
		int a = in.nextInt();
		System.out.println("How many eyes?");
		int e = in.nextInt();
		if (a >= 3 && e<= 4) {
			System.out.println("TroyMartian");
		}
		if (a <= 6 && e>= 2) {
			System.out.println("VladSaturnian");
		}
		if (a <= 2 && e<= 3) {
			System.out.println("GraemeMercurian");
		}
	}
}
