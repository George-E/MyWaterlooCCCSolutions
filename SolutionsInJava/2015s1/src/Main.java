
import java.util.*;

public class Main {

	public static void main(String[] args) {
		List<Integer> numbers = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		int commands = in.nextInt();
		int input;
		for (int i = 0; i< commands; i++) {
			input = in.nextInt();
			if (input != 0) {
				numbers.add(input);
			} else {
				numbers.remove(numbers.size() -1);
			}
		}
		int sum = 0;
		for (Integer operand : numbers) {
			sum += operand;
		}
		System.out.println(sum);
	}

}
