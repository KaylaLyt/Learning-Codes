package 蓝桥杯4A;

public class _1世纪末的星期 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int year=2000;
		int day=0;
		while(year>1999)
		{
			if(year%400==0 || (year%4==0 && year%100!=0)) day+=366;
			else day+=365;
			if(day%7==2&&year%100==99)
			{
				System.out.println(year);
				break;
			}
			year++;
		}
		

	}

}
