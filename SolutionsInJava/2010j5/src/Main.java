import java.util.*;

public class Main {
	
	public static int x2 = 0;
	public static int y2 = 0;
	public static List<Integer> moves = new ArrayList<Integer>();
	public static List<String> pos = new ArrayList<String>();
	
	public static void move(int tempX, int tempY, int currentMoves) {
		if (tempX>0 && tempY >0 && tempX<9 && tempY<9) {
			boolean test = true;
			String newPos = tempX + " " + tempY;
			if (pos.contains(newPos)) {
				if (moves.get(pos.indexOf(newPos)) <= currentMoves + 1) {
					test = false;
				}
			}
			if (test) {
				moves.add(currentMoves + 1);
				pos.add(newPos);
			}
		}
	}
	
	public static void main(String[] args) {
		int least = -1;
		Scanner in = new Scanner(System.in);
		String starterPos = in.nextLine();
		x2 = in.nextInt();
		y2 = in.nextInt();
		
		
		moves.add(0);
		pos.add(starterPos);
		int min = 100;
		int checked = 0;
		
		while (checked < moves.size()) {
			
			String currentPos = pos.get(checked);
			int x = Character.getNumericValue(currentPos.charAt(0));
			int y = Character.getNumericValue(currentPos.charAt(2));
			int currentMoves = moves.get(checked);
			
			if (currentMoves  > min) {
				checked++;
				continue;
			}
			if (x == x2 && y == y2) {
				if (currentMoves  < min)
					min = currentMoves;
				checked++;
				continue;
			}
			
			int tempX = x-2;
			int tempY = y-1;
			move(tempX, tempY, currentMoves);
			tempX = x-2;
			tempY = y+1;
			move(tempX, tempY, currentMoves);
			tempX = x+2;
			tempY = y-1;
			move(tempX, tempY, currentMoves);
			tempX = x+2;
			tempY = y+1;
			move(tempX, tempY, currentMoves);
			tempX = x+1;
			tempY = y-2;
			move(tempX, tempY, currentMoves);
			tempX = x+1;
			tempY = y+2;
			move(tempX, tempY, currentMoves);
			tempX = x-1;
			tempY = y-2;
			move(tempX, tempY, currentMoves);
			tempX = x-1;
			tempY = y+2;
			move(tempX, tempY, currentMoves);
			
			checked++;
		}
		
		System.out.print(min);	
	}
}
