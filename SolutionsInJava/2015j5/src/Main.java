import java.util.Scanner;



public class Main {
	public static int ways = 0;
	public static void possible(int pie, int person, int[] config) {
		if (config.length-person == 1) {
				ways++;
		} else if (person ==0) {
			for (int i =1; i <= pie/config.length; i++) {
				config[person] = i;
				possible(pie-i,person+1,config);
			}
		} else {
			for (int i =config[person-1]; i <= pie/(config.length-person); i++) {
				config[person] = i;
				possible(pie-i,person+1,config);
			}	
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int pie = in.nextInt();
		int people = in.nextInt();
		int[] config = new int[people];
		possible(pie,0,config);
		System.out.println(ways);
	}
}
