import java.util.*;
public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		int s = in.nextInt();
		int sessN = s/(a+b);
		int sessB = s/(c+d);
		int remN = s%(a+b);
		int remB = s%(c+d);
		int Nikky = (a-b)*sessN +remN;
		int Byron = (c-d)*sessB +remB;
		if (a < remN) 
			Nikky = Nikky - 2*remN +2*a;
		if (c < remB) 
			Byron = Byron - 2*remB + 2*c;
		if (Nikky > Byron)
			System.out.println("Nikky");
		else if (Nikky < Byron)
			System.out.println("Byron");
		else 
			System.out.println("Tied");
		System.out.println((int)2.7);
		System.out.println((int)2.5);
		System.out.println((int)2.2);
	}

}
