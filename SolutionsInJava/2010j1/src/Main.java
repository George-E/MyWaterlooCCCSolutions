
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		switch (num) {
		case 1: case 9: case 10:
			System.out.println("1");
			break;
		case 2: case 3: case 7: case 8:
			System.out.println("2");
			break;
		case 4: case 5: case 6:
			System.out.println("3");
			break;
		}
	}

}
