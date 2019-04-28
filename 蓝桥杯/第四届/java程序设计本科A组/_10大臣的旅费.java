package À¶ÇÅ±­4A;

import java.util.Scanner;
import java.util.ArrayList;
public class _10´ó³¼µÄÂÃ·Ñ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		QiDian[] qiDians = new QiDian[n];
		
		for(int i=0;i<n;i++){
			qiDians[i]=new QiDian(i+1);
		}
		
		for(int i=0;i<n-1;i++){
			int temp1=scanner.nextInt();
			int temp2=scanner.nextInt();
			int quanZhong=scanner.nextInt();
			
			qiDians[temp1-1].arrayList.add(new ZhongDian(quanZhong, qiDians[temp2-1]));
			qiDians[temp2-1].arrayList.add(new ZhongDian(quanZhong, qiDians[temp1-1]));
		}

		
		JuLiLujing juLiLujing=searchLuJing(qiDians[0], null);		
		String[] aa=juLiLujing.luJing.split(" ");
		JuLiLujing juLiLujing2=searchLuJing(qiDians[Integer.parseInt(aa[aa.length-1])-1], null);
		
		int sum=0;
		for(int i=1;i<=juLiLujing2.juLi;i++){
			sum+=i+10;
		}
		System.out.print(sum);
	}

	
	public static JuLiLujing searchLuJing(QiDian qiDian, QiDian upQiDian) {

		JuLiLujing juLiLujing=new JuLiLujing(0,qiDian.qiDian+"");
		for (int i = 0; i < qiDian.arrayList.size(); i++) {
			if (qiDian.arrayList.get(i).qiDian.equals(upQiDian) == false) {
				
				JuLiLujing temp=searchLuJing(qiDian.arrayList.get(i).qiDian, qiDian);
				
				int juLiTemp=qiDian.arrayList.get(i).quanZhong+temp.juLi;
				
				if ( juLiTemp>juLiLujing.juLi) {
					juLiLujing.juLi = juLiTemp;
					juLiLujing.luJing=qiDian.qiDian+" "+temp.luJing;
				}
			}
		}
		return juLiLujing;
	}
}

class QiDian {
	int qiDian;
	ArrayList<ZhongDian> arrayList=new ArrayList<ZhongDian>();

	public QiDian(int bianHao) {
		this.qiDian = bianHao;
	}
}

class ZhongDian {
	int quanZhong;
	QiDian qiDian;

	public ZhongDian(int quanZhong, QiDian qiDian) {
		this.quanZhong = quanZhong;
		this.qiDian = qiDian;
	}
}

class JuLiLujing{
	int juLi;
	String luJing;
	public JuLiLujing(int juLi,String luJing) {
		// TODO Auto-generated constructor stub
		this.luJing=luJing;
		this.juLi=juLi;
	}

}
