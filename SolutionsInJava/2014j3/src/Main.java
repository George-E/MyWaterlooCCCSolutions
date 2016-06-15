import java.util.*;
public class Main {

	public static void main(String[] args) {
		int Antonia = 100;
		int David = 100;
		Scanner in = new Scanner(System.in);
		int rounds = in.nextInt();
		for (int i = 0; i<rounds;i++) {
			int a = in.nextInt();
			int d = in.nextInt();
			if (a > d)
				David -= a;
			else if (a < d)
				Antonia -= d;
		}
		System.out.println(Antonia);
		System.out.print(David);
	}

}
