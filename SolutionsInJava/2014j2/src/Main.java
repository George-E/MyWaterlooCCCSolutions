
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int voteTotal = in.nextInt();
		String	votesFull = in.next();
		String votes = votesFull.replace("B", "");
		if (votes.length() > voteTotal-votes.length())
			System.out.print("A");
		else if (votes.length() < voteTotal-votes.length())
			System.out.print("B");
		else
			System.out.print("Tie");
		
	}

}