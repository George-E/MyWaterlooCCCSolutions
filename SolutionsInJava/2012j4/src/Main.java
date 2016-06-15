import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int parameter = in.nextInt();
		char[] word = in.next().toCharArray();
		for (int i =0; i<word.length;i++) {
			word[i] -= 3*(i+1) + parameter;
			if (word[i] < 'A') {
				word[i] = (char) ('Z' - ( 'A' - word[i] ) +1 );
			}
		}
		System.out.println(word);
	}

}
