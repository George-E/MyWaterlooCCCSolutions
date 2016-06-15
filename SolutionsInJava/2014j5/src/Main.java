import java.util.*;
public class Main {

	public static void main(String[] args) {
		boolean good = true;
		Scanner in = new Scanner(System.in);
		int people = in.nextInt();
		String[][] list = new String[people][2];
		for (int i = 0; i < people; i++) 
			list[i][0] = in.next();
		for (int i = 0; i < people; i++) 
			list[i][1] = in.next();
		for (int i = 0; i < people; i++) {
			if (list[i][0].equals(list[i][1]))
				good = false;
		}

		if (good) {
			for (int i = 0; i < people; i++) {
				String tempA = list[i][0];
				String tempB = list[i][1];
				for (int n = 0; n < people; n++) {
					if (list[n][0].equals(tempB)) {
						if (!(list[n][1].equals(tempA)))
							good = false;
					}
				}
			}
		}
		System.out.print((good) ? "good" : "bad" );

	}

}
