import java.util.*;

public class OldMain {
	public static void main(String[] args) {
		int least = -1;
		Scanner in = new Scanner(System.in);
		int x1 = in.nextInt();
		int y1 = in.nextInt();
		int x2 = in.nextInt();
		int y2 = in.nextInt();
		int hdif = x2 - x1;
		int vdif = y2 - y1; 
		int hrestl = (x1 < x2) ? (x1-1) : (x2-1);
		int hrestr = (x1 < x2) ? 8-x2 : 8-x1;
		int vrestd = (y1 < y2) ? (y1-1) : (y2-1);
		int vrestu = (y1 < y2) ? 8-y2 : 8-y1;

		//System.out.println(hrestl + " " + hrestr + " " + vrestd + " " + vrestu);
		for (int a = -3; a <= 3; a ++) {
			for (int b = -3; b <= 3; b ++) {
				for (int c = -3; c <= 3; c ++) {
					for (int d = -3; d <= 3; d ++) {
						if (((a*2 + b*2 + c - d) == vdif) && ((a - b + c*2 + d*2) == hdif)) {
							int moves = Math.abs(a) + Math.abs(b) + Math.abs(c) + Math.abs(d);
							if ( (least == -1) || (least > moves) ) {
								int left = 0,right = 0,down = 0,up = 0;
								if (a>0) {
									up += a*2;
									right += a;
								} else  {
									down += a*-2;
									left += a*-1;
								}
								if (b>0) {
									up += b*2;
									left += b;
								} else  {
									down += b*-2;
									right += b*-1;
								}
								if (c>0) {
									right += c*2;
									up += c;
								} else  {
									left += c*-2;
									down += c*-1;
								}
								if (d>0) {
									right += d*2;
									down += d;
								} else  {
									left += d*-2;
									up += d*-1;
								}
								if (!(left > hrestl || right > hrestr || down > vrestd || up > vrestu))
									least = moves;
							}

						}
					}
				}
			}
		}
		System.out.print(least);	
	}
}
