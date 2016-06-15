import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		int[][] messages = new int[inputs][3];
		ArrayList<Integer> friends = new ArrayList<Integer>();
		for (int i = 0; i < inputs; i++) {
			String action = in.next();
			if (action.equals("R")) {
				messages[i][0] = 1;
				int friend = in.nextInt();
				messages[i][1] = friend;
				if (!(friends.contains(friend))) {
					friends.add(friend);
				}
			} else if (action.equals("S")) {
				messages[i][0] = 2;
				messages[i][1] = in.nextInt();
			} else {
				messages[i][0] = 3;
				messages[i][1] = in.nextInt();
			}
		}
		Collections.sort(friends);
		for (int buddy: friends) {
			int waits = 0;
			int waitTime  = 0;
			int comm = 0;
			int startIndex = 0, finishIndex = 0;
			boolean waiting = false;
			int numWaits = 0;
			for (int i = 0; i < inputs; i++) {
				messages[i][2] = 0;
				if (messages[i][1]== buddy) {
					if (messages[i][0] == 1)  {
						comm ++;
						if (startIndex == 0) {
							startIndex = i;
						}
					} else if (messages[i][0] == 2)  {
						comm ++;
						if (i > finishIndex) {
							finishIndex = i;
						}
					} 
				}
				}
				if (!(comm%2 == 0)) {
					System.out.println(buddy + " -1");
				} else {
					int others =0;
					for (int w = startIndex; w <= finishIndex; w++) {
						if (messages[w][0] == 1){
							if (messages[w][1] != buddy && waiting) {
								waitTime += 1;
							} else if (messages[w][1] == buddy) {
								waiting = true;
							}
						} else if (messages[w][0] == 2){
							if (messages[w][1] != buddy && waiting) {
								waitTime += 1;
							} else if (messages[w][1] == buddy) {
								waiting = false;
							}
						}
						else if (messages[w][0] == 3 && waiting) {
							waitTime += messages[w][1];
							numWaits++;
						}
					}
					waitTime += comm/2-1;
					waitTime-=numWaits-1;
					System.out.println(buddy + " " + (waitTime));
	
				}
			
		}
	}
}