import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String word = in.next();
		String newWord = "";
		for (int i =0; i<word.length(); i++) {
			switch (word.charAt(i)) {
			case 'a': case 'e': case 'i': case 'o': case 'u':
				newWord += word.charAt(i);
				break;
			case 'z':
				newWord += word.charAt(i);
				newWord += 'u';
				newWord += 'z';
				break;
			default:
				char closestAfter = 'a';
				char closestConsAfter = '0';
				char closestBefore = 'a';
				int closeAfter = 26;
				int closeBefore = 26;
				for (char n = 'a'; n<= 'z';n++) {
					if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u') {
						if (n > word.charAt(i) && n-word.charAt(i) < closeAfter) {
							closeAfter = n-word.charAt(i);
							closestAfter = n;
						}
						if (n < word.charAt(i) && word.charAt(i)-n < closeBefore) {
							closeBefore = word.charAt(i)-n;
							closestBefore = n;
						}	
					} else {
						if (n > word.charAt(i) && closestConsAfter == '0') {
							closestConsAfter = n;
						}
					}
				}
				newWord += word.charAt(i);
				if (closeAfter < closeBefore) {
					newWord += closestAfter;
				} else {
					newWord += closestBefore;
				}
				newWord += closestConsAfter ;
			}
		}
		System.out.println(newWord);
	}
}
