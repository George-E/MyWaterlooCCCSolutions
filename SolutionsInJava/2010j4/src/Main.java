import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int trial = in.nextInt();
		while (trial != 0) {
			int difs[] = new int[trial - 1];
			int last = in.nextInt();
			int current;
			for (int i = 1; i < trial; i++) {
				current = in.nextInt();
				difs[i - 1] = current - last;
				last = current;
			}
			int pattern = difs.length;
			for (int i = 1; i < difs.length; i++)
				if (difs[i] == difs[0]) {
					int n = 1;
					boolean test = true;
					while ((i + n) < difs.length) {
						if (difs[i + n] != difs[n])
							test = false;
						n++;
					}
					if (test) {
						pattern = i;
						break;
					}
				}
			System.out.println(pattern);
			trial = in.nextInt();
		}
	}

}
