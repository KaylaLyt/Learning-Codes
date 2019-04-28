package À¶ÇÅ±­4A;

public class _4µßµ¹µÄ¼ÛÅÆ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int k = 0;
        int x = 0;
        int[] k2 = new int[24];
        int[] x2 = new int[12];
        int[] z = new int[24];
        int[] w = new int[12];
        for(int a=1;a<10;a++) {
            if(a==3||a==4||a==7)
                continue;
            int a1 = a;
            if(a == 6) {
                a1 = 9;
            } 
            if(a == 9){
                a1 = 6;
            }

            for(int b=0;b<10;b++) {
                if(b==3||b==4||b==7)
                    continue;
                int b1 = b;
                if(b == 6) {
                    b1 = 9;}
                if(b == 9){
                    b1 = 6;}
                for(int c=0;c<10;c++) {
                    if(c==3||c==4||c==7)
                        continue;
                    int c1 = c;
                    if(c == 6){
                        c1 = 9;}
                    if(c == 9){
                        c1 = 6;}
                    for(int d=1;d<10;d++) {
                        if(d==3||d==4||d==7)
                            continue;
                        int d1 = d;
                        if(d == 6){
                            d1 = 9;}
                        if(d == 9){
                            d1 = 6;}
                        int num = a*1000+b*100+c*10+d;
                        int num2 = d1*1000+c1*100+b1*10+a1;
                        if(num-num2>200 && num-num2<300) {
                            z[k] = num-num2;
                            k2[k] = num;
                            k++;
                        }
                        if (num2-num>800 && num2-num<900) {
                            w[x] = num2-num;
                            x2[x] = num;
                            x++;
                        }


                    }
                }
            }
        }
        for(int i=0;i<24;i++) {
            for(int j=0;j<12;j++) {
                if(w[j]-z[i]==558)
                    System.out.println(k2[i]+" "+x2[j]);
            }

        }
    }



}
