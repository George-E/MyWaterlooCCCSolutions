
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int time = in.nextInt();
		int chores = in.nextInt();
		int choreTime[] = new int[chores];
		for (int i = 0; i < chores; i++) {
			choreTime[i] = in.nextInt();
		}
		Arrays.sort(choreTime);
		for (int i = 0; i < chores; i++) {
			time -= choreTime[i];
			if (time < 0) {
				System.out.println(i);
				break;
			}
		}
	}

}
