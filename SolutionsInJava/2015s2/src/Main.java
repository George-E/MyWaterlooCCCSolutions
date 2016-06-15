import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int jersey = in.nextInt();
		int players = in.nextInt();
		int[] jSizes = new int[jersey];
		boolean[] taken = new boolean[jersey];
		
		for (int i = 0; i< jersey; i++) {
			String size = in.next();
			switch (size) {
			case "S" :
				jSizes[i] = 0;break;
			case "M" :
				jSizes[i] = 1;break;
			case "L" :
				jSizes[i] = 2;break;
			}
		}
		for (int i = 0; i< players; i++) {
			String size = in.next();
			int sized = 0;
			switch (size) {
			case "S" :
				sized = 0;break;
			case "M" :
				sized  = 1;break;
			case "L" :
				sized  = 2;break;
			}
			int num = in.nextInt()-1;
			if (taken[num] == false && sized <= jSizes[num])
				taken[num] = true;
		}
		int counter = 0;
		for (int i =0; i<jersey;i++) {
			if (taken[i])
				counter++;
		}
		System.out.println(counter);
	}

}
