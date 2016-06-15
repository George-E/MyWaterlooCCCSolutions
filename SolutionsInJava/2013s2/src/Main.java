import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int limit = in.nextInt();
		int cars = in.nextInt();
		int[] weights = new int[cars];
		Loop:
		for (int i = 0; i<cars;i++)
		{
			weights[i] = in.nextInt();
			switch (i){
			case 0:
				if (weights[i]>limit)
				{
					cars = i;
					break Loop;
				}
				continue Loop;
			case 1:
				if (weights[i]+weights[i-1]>limit)
				{
					cars = i;
					break Loop;
				}
				continue Loop;
			case 2:
				if (weights[i]+weights[i-1]+weights[i-2]>limit)
				{
					cars = i;
					break Loop;
				}
				continue Loop;
			}
			if (weights[i]+weights[i-1]+weights[i-2]+weights[i-3]>limit)
			{
				cars = i;
				break Loop;
			}
		}
		System.out.println(cars);
	}

}
