
import java.util.*;

public class Main {
	public static boolean[][] spaces = new boolean[401][201];
	public static int[] path(char dir,int length,int x,int y) {
		int x2=x, y2=y, test = 0;
		switch (dir) {
		case 'u':
			y2 = y + length;
			for (int i =1; i<= length; i++)
				if (spaces[x+200][y+i+200] == false)
					spaces[x+200][y+i+200] = true;
				else
					test = 1;
			break;
		case 'd':
			y2 = y - length;
			for (int i =1; i<= length; i++)
				if (spaces[x+200][y-i+200] == false)
					spaces[x+200][y-i+200] = true;
				else
					test = 1;
			break;
		case 'l':
			x2 = x-length;
			for (int i =1; i<= length; i++)
				if (spaces[x-i+200][y+200] == false)
					spaces[x-i+200][y+200] = true;
				else
					test = 1;
			break;
		case 'r':
			x2 = x + length;
			for (int i =1; i<= length; i++)
				if (spaces[x+i+200][y+200] == false) {
					spaces[x+i+200][y+200] = true;
				} else {
					test = 1;
				}
			break;
		}
		int[] end ={x2,y2, test};
		return end;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] pos = {-1,-5,0};
		path('d',2,0,-1);
		path('r',3,0,-3);
		path('d',2,3,-3);
		path('r',2,3,-5);
		path('u',2,5,-5);
		path('r',2,5,-3);
		path('d',4,7,-3);
		path('l',8,7,-7);
		path('u',2,-1,-7);
		boolean safe = true;
		char dir = in.next().charAt(0);
		int length = in.nextInt();
		while (dir != 'q') {
			pos = path(dir, length, pos[0], pos[1]);
			System.out.print(pos[0] + " ");
			System.out.print(pos[1] + " ");
			if (pos[2] == 0)
				System.out.println("safe");
			else {
				System.out.println("DANGER");
				break;
			}	
			dir = in.next().charAt(0);
			length = in.nextInt();
		}
	}

}
