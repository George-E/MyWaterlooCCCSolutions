
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int teamNum = in.nextInt()-1;
		int gamesThusFar = in.nextInt();
		int[] scores = new int[4];
		boolean[][] games = new boolean[4][4];
		games[0][1] = true;
		games[0][2] = true;
		games[0][3] = true;
		games[1][2] = true;
		games[1][3] = true;
		games[2][3] = true;
		int x, y, xs, ys;
		for (int i =0; i<gamesThusFar ; i++) {
			x = in.nextInt()-1;
			y = in.nextInt()-1;
			games[x][y] = false;
			xs = in.nextInt();
			ys = in.nextInt();
			if (xs > ys) {
				scores[x] += 3;
			}
			else if (xs < ys) {
				scores[y] += 3;
			}
			else {
				scores[x] += 1;
				scores[y] += 1;
			}
		}
		int[][] gamesLeft = new int[6-gamesThusFar][2];
		int[][] scoresNew = new int[(int) Math.pow(3, 6-gamesThusFar)][4];
		for (int u = 0; u < scoresNew.length; u++) {
			scoresNew[u] = scores;
		}
		int i = 0;
		for (int p = 0; p < 4; p++) {
			for (int t = 0; t < 4; t++) {
				if (games[p][t] == true) {
					gamesLeft[i][0] = p;
					gamesLeft[i][1] = t;
					i++;
				}
			}
		}
		int left = 6-gamesThusFar;
		int currentGame = 1;
		while (left > 0) {
			for (int p = 0; p < Math.pow(3, currentGame); p++) {
				for (int t = 0; t < scoresNew.length / Math.pow(3, currentGame); t++) {
					scoresNew[(int) ((p)*Math.pow(3, currentGame))][gamesLeft[currentGame-1][0]] += 3;
				}
				for (int t = 0; t < scoresNew.length / Math.pow(3, currentGame); t++) {
					scoresNew[(int) ((p)*Math.pow(3, currentGame))][gamesLeft[currentGame-1][1]] += 3;
				}
				for (int t = 0; t < scoresNew.length / Math.pow(3, currentGame); t++) {
					scoresNew[(int) ((p)*Math.pow(3, currentGame))][gamesLeft[currentGame-1][0]] += 3;
				}
			}

		}
	}

}
