import java.util.*;

public class NewMain {
	//this is even worst than 1st.................try reduce cloning
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int pie = in.nextInt();
		int people = in.nextInt();
		int[] config = new int[people];
		int ways = 0;
		
		List<Integer> peoples =  new ArrayList<Integer>();
		List<Integer> pies =  new ArrayList<Integer>();
		List<int[]> configs =  new ArrayList<int[]>();


		for (int i =1; i <= pie/config.length; i++) {
			config[0] = i;
			peoples.add(1);
			pies.add(pie-i);
			configs.add(config.clone());
		}
		
		while (peoples.size() >0) {
			int person = peoples.get(0);
			pie = pies.get(0);
			config = configs.get(0).clone();
			peoples.remove(0);
			pies.remove(0);
			configs.remove(0);
			if (config.length-person==1) {
					ways++;
					continue;
			} else {
				for (int i =config[person-1]; i <= pie/(config.length-person); i++) {
					config[person] = i;
					peoples.add(person+1);
					pies.add(pie-i);
					configs.add(config.clone());
				}	
			}
		}
		
		System.out.println(ways);
	}
}
