package À¶ÇÅ±­4B;

public class _3ÕñĞËÖĞ»ª {

	public static void main(String[] args) {
		/*int[][] a= {
				{0,1,2,3,4},
				{1,2,3,4,5},
				{2,3,4,5,6},
				{3,4,5,6,7}
		};*/
		int[][] a=new int[4][5];
		for(int i=0;i<4;i++)
		{
			a[i][0]=1;
		}
		for(int i=0;i<5;i++)
		{
			a[0][i]=1;
		}
		for(int i=1;i<4;i++)
		{
			for(int j=1;j<5;j++)
			{
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
		System.out.print(a[3][4]);
	}
}
