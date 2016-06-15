import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(),
			b = in.nextInt(),
			c = in.nextInt();
		if (a+b+c != 180)
			System.out.print("Error");
		else if (a == 60 & b ==60)
			System.out.print("Equilateral");
		else if (a == b | a ==c | b==c)
			System.out.print("Isosceles");
		else 
			System.out.print("Scalene");
	}

}
