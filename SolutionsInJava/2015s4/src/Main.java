import java.util.Scanner;

public class Main {
	public static int smallestTime = -1;
	public static int[][] paths;

	public static void travel(int A, int B, int buff, int time) {
		if (buff <1 || (smallestTime != -1 && time >= smallestTime))
			return;
		if (A == B) {
			if (smallestTime == -1 || time < smallestTime)
				smallestTime = time;
			return;
		}
		for (int i = 0; i < paths.length; i++) {
			if (paths[i][0] == A) 
				travel(paths[i][1],B,buff-paths[i][3],time+paths[i][2]);
			else if (paths[i][1] == A) 
				travel(paths[i][0],B,buff-paths[i][3],time+paths[i][2]);
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int buffer = in.nextInt();
		int islands = in.nextInt();
		int pathNum = in.nextInt();
		paths = new int[pathNum][4];
		for (int i = 0; i < pathNum; i++) {
			paths[i][0] = in.nextInt();
			paths[i][1] = in.nextInt();
			paths[i][2] = in.nextInt();
			paths[i][3] = in.nextInt();
		}
		int A = in.nextInt();
		int B = in.nextInt();
		smallestTime = -1;
		travel(A, B, buffer, 0);
		System.out.println(smallestTime);
	}
}
