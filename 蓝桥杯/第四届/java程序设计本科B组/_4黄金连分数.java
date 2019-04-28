package 蓝桥杯4B;

import java.math.BigDecimal;

public class _4黄金连分数 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigDecimal bd = new BigDecimal(1);  
        for (int i = 0; i < 1000; i++) {  
            bd = bd.add(BigDecimal.ONE);  
            bd = BigDecimal.ONE.divide(bd, 100, BigDecimal.ROUND_HALF_DOWN);  
        }  
        System.out.println(bd.toString());  
	}

}
