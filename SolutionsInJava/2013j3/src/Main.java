import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int year = in.nextInt() + 1;
		String word = Integer.toString(year);
		boolean test = true;

		while (test) {
			test = false;
			for (int i = 0; i < word.length(); i++) {
				if (!(word.lastIndexOf(word.charAt(i)) == i)) {
					test = true;
					break;
				}
			}
			year++;
			word = Integer.toString(year);
		}
		System.out.println(year - 1);
	}
}