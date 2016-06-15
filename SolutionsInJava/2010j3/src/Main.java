import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = 0;
		int B = 0;
		String assign;
		String operand;
		int instruction = in.nextInt();
		while (instruction != 7) {
			switch (instruction) {
			case 1:
				if (in.next().equals("A"))
					A = in.nextInt();
				else
					B = in.nextInt();
				break;
			case 2:
				if (in.next().equals("A"))
					System.out.println(A);
				else
					System.out.println(B);
				break;
			case 3:
				assign = in.next();
				operand = in.next();
				if (assign.equals("A") && operand.equals("A"))
					A = A + A;
				else if (assign.equals("A") && operand.equals("B"))
					A = A + B;
				else if (assign.equals("B") && operand.equals("B"))
					B = B + B;
				else 
					B = B + A;
				break;
			case 4:
				assign = in.next();
				operand = in.next();
				if (assign.equals("A") && operand.equals("A"))
					A = A * A;
				else if (assign.equals("A") && operand.equals("B"))
					A = A * B;
				else if (assign.equals("B") && operand.equals("B"))
					B = B * B;
				else 
					B = B * A;
				break;
			case 5:
				assign = in.next();
				operand = in.next();
				if (assign.equals("A") && operand.equals("A"))
					A = A - A;
				else if (assign.equals("A") && operand.equals("B"))
					A = A - B;
				else if (assign.equals("B") && operand.equals("B"))
					B = B - B;
				else 
					B = B - A;
				break;
			case 6:
				assign = in.next();
				operand = in.next();
				if (assign.equals("A") && operand.equals("A"))
					A = A / A;
				else if (assign.equals("A") && operand.equals("B"))
					A = A / B;
				else if (assign.equals("B") && operand.equals("B"))
					B = B / B;
				else 
					B = B / A;
				break;
			}
			instruction = in.nextInt();
		}
	}

}
