package 蓝桥杯4B;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class _10连号区间数 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		
		Scanner input = new Scanner(System.in);


		int num = input.nextInt();


		int[] arr = new int[num];
		int	  ans = 0;


		for(int i = 0;i<num;i++)
			arr[i] = input.nextInt();


		for(int i = 0;i<num;i++)
		{
			
			int max = arr[i];
			int min = arr[i];


			for(int j = i;j<num;j++)
			{
				max = Math.max(max,arr[j]);
				min = Math.min(min,arr[j]);


				if(max - min == j - i)
				ans++;
			}
		}
		sop1(ans);
		


	}


	public static void sop(int[] arr)
	{
		for(int i = 0;i<arr.length;i++)
			System.out.print(arr[i] + " ");
		sop1("");
	}
	public static void sop1(Object obj)
	{
		System.out.println(obj);
	}
	

}
