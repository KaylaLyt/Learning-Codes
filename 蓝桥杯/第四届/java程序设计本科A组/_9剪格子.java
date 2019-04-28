package À¶ÇÅ±­4A;

import java.util.Scanner;

public class _9¼ô¸ñ×Ó {
	private static int n;
	private static int m;
	private static int min = 100;
	private static int gezi[][];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		m = cin.nextInt();
		n = cin.nextInt();
		gezi = new int[n][m];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				gezi[i][j] = cin.nextInt();
				sum += gezi[i][j];
			}
		}
		cal(0, 0, sum / 2, 0, new int[n][m]);
		System.out.println(min);
	}

	private static Boolean cal(int nn, int mm, int s, int c, int ed[][]) {	
		if (s == 0) {
			if (c < min)
				min = c;
			return true;
		}
		if (s < 0)
			return false;
		if (mm < m && nn < n && mm >= 0 && nn >= 0) {
			if (ed[nn][mm] == 0) {
				s -= gezi[nn][mm];
				ed[nn][mm] = 1;
				c++;
				cal(nn + 1, mm, s, c, ed);
				cal(nn - 1, mm, s, c, ed);
				cal(nn, mm + 1, s, c, ed);
				cal(nn, mm - 1, s, c, ed);
				ed[nn][mm] = 0;
			}
		}
		return false;
	}

}
