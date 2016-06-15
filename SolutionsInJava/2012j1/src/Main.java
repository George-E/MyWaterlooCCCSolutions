import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the speed limit: ");
		int limit = in.nextInt();
		System.out.print("Enter the recorded speed of the car: ");
		int speed = in.nextInt();
		if (speed <= limit) {
			System.out.print("Congratulations, you are within the speed limit!");
		}
		else if (speed-limit <= 20) {
			System.out.print("You are speeding and your fine is $100.");
		}
		else if (speed-limit <= 30) {
			System.out.print("You are speeding and your fine is $270.");
		}
		else {
			System.out.print("You are speeding and your fine is $500.");
		}
	}

}
