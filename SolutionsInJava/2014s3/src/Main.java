import java.util.*;

public class Main {

	public static int aGoodIndexOf(int[] array, int val)
	{
		for(int i = 0; i < array.length; i++)
		{
			if(array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		mainLoop:
		for (int n = 0; n < tests; n++) {
			int ingredients = in.nextInt();
			int [] order = new int[ingredients];
			for (int i = 0; i < ingredients; i++)
				order[i] = in.nextInt();
			int x = 1;
			while (x<ingredients) {
				int a = aGoodIndexOf(order, x);
				int b = aGoodIndexOf(order, x+1);
				if (b>(a+1)) {
					for (int r = a+1; r < b; r++) {
						if (order[r] > order[a]) {
							System.out.println("N");
							continue mainLoop;
						}	
					}
				}
				x++;
			}
			System.out.println("Y");
		}
	}
}
