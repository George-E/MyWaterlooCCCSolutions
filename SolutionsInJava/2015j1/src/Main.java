import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] tokens = in.readLine().split(" ");
		int month = Integer.parseInt(tokens[0]);
		int day = Integer.parseInt(tokens[0]);
		if (month == 2 && day == 18) {
			System.out.println("Special");
		} else if (month < 2) {
			System.out.println("Before");
		} else if (month > 2) {
			System.out.println("After");
		} else if (day > 18) {
			System.out.println("After");
		} else {
			System.out.println("Before");
		}
			
	}

}
