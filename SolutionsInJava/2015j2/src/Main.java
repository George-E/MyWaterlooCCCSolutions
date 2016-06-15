import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		int happy = 0, sad = 0;
		for (int i =0; i < line.length()-2; i++) {
			if (line.charAt(i) == ':') {
				if (line.charAt(i+1) == '-' && line.charAt(i+2) == ')') {
					happy++;
				}
				if (line.charAt(i+1) == '-' && line.charAt(i+2) == '(') {
					sad++;
				}
			}
		}
		if (happy + sad == 0)
			System.out.println("none");
		else if (happy == sad)
			System.out.println("unsure");
		else if (happy > sad)
			System.out.println("happy");
		else if (happy < sad)
			System.out.println("sad");
	}

}
