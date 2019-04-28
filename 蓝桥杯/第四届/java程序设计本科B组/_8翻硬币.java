package 蓝桥杯4B;

import java.util.Scanner;

public class _8翻硬币 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String s1=s.next();//储存第一组数据
		String s2=s.next();//储存第一组数据
		int count=0;//记下翻动的次数
		char [] a=new char [s1.length()];//储存第一组数据
		char [] b=new char [s1.length()];//储存第一组数据
		for(int i=0;i<s1.length()-1;i++){
			a[i]=s1.charAt(i);
			b[i]=s2.charAt(i);
		}
		for(int i=0;i<s1.length()-1;i++){
			if(a[i]!=b[i]){
				if(a[i+1]=='*'){
					a[i+1]= 'o';
				}
				else a[i+1]='*';
				count++;
			}
		}
		System.out.println(count);
	}

}
