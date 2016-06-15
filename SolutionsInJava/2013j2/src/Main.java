import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word = in.next();
		/*boolean test = true;
		for (int i = 0; i < word.length(); i++) 
			if (!(word.charAt(i) == 'I' || word.charAt(i) == 'O'
			|| word.charAt(i) == 'S' || word.charAt(i) == 'H'
			|| word.charAt(i) == 'Z' || word.charAt(i) == 'X' 
			|| word.charAt(i) == 'N')) {
				test = false;
				break;
			}*/
		System.out.println((word.matches("[IOSHZXN]*")) ? "YES" : "NO");

	}
}