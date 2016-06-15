//(if 0 wasnt included in the number of commands)

import java.util.*;

public class test {

	public static void main(String[] args) {
		List<Integer> numbers = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		int commands = in.nextInt();
		int input;
		int i = 0;
		while (i< commands) {
			input = in.nextInt();
			if (input != 0) {
				numbers.add(input);
				i++;
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
