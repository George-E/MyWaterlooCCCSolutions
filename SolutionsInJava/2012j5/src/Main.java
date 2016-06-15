import java.util.*;

public class Main {

	public static ArrayList<Integer> steps = new ArrayList<Integer>();
	public static void moves(int[][] spots, int stepsTaken) {
		for (int n =0; n< spots.length;n++) {
			for (int k =0; k< spots[n].length;k++) {
				if (spots[n][k] != 0) {
					int num = spots[n][k];
					boolean test = true;
					if (n < spots.length-1) {
						spots[n][k] = 0;
						for (int i = 0; i< spots[n+1].length;i++) {
							if (spots[n+1][i] == 0) {
								spots[n+1][i] = num;
								test = true;
								for (int o = 0; o< spots.length; o++) {
									if (spots[o][0] != o+1) {
										test = false;
										break;
									}	
								}
								if (test) {
									steps.add(stepsTaken);
								} else {
									moves(spots, stepsTaken+1);
								}
								break;
							}
						}
					}
					if (n > 0) {
						spots[n][k] = 0;
						for (int i = 0; i< spots[n-1].length;i++) {
							if (spots[n-1][i] == 0) {
								spots[n-1][i] = num;
								test = true;
								for (int o = 0; o< spots.length; o++) {
									if (spots[o][0] != o+1) {
										test = false;
										break;
									}	
								}
								if (test) {
									steps.add(stepsTaken);
								} else {
									moves(spots, stepsTaken+1);
								}
								break;
							}
						}
					}	
				}
			}

		}

	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int coins = in.nextInt();
		while (coins != 0) {
			steps.clear();
			steps.add(-1);
			int[][] positions = new int[coins][coins];
			for (int i = 0; i< coins;i++) {
				positions[i][0] = in.nextInt();
			}
			boolean test = true;
			for (int o = 0; o< positions.length; o++) {
				if (positions[o][0] != o+1) {
					test = false;
					break;
				}	
			}
			if (test) {
				System.out.println("0");
			} else {
				moves(positions,1);
				if (steps.size() == 1) {
					System.out.println("IMPOSSIBLE");
				} else {
					Collections.sort(steps);
					System.out.println(steps.get(1));
				}
			}
			coins = in.nextInt();
		}
	}
}
