import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int year = in.nextInt();
		Loop:
		while (true){
			year++;
			String yearStr = ""+year;
			for (int i =0; i<yearStr.length()-1;i++)
			{
				if (yearStr.lastIndexOf(yearStr.charAt(i))!=i)
				{
					continue Loop;				
				}
			}
			break;
		}
		System.out.println(year);
	}

}
