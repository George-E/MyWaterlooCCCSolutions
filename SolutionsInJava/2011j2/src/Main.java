
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h = in.nextInt();
		int max = in.nextInt();
		int alt = 0, t = 0;
		while (true) {
			t++;
			if (t > max) {
				System.out.println("The balloon does not touch ground in the given time.");
				break;
			}
			alt = (int) (-6*Math.pow(t, 4) + h*Math.pow(t, 3) + 2*Math.pow(t,2) + t);	
			if (alt <= 0) {
				System.out.println("The balloon first touches ground at hour:\n" + t);
				break;
			}
			
		}

	}

}
