package À¶ÇÅ±­4B;

import java.util.HashSet;
import java.util.Set;

public class _9´ø·ÖÊý {
	
	private static Set<Integer> all = new HashSet<>();
    private static Set<Integer> temp1 = new HashSet<>();
    private static Set<Integer> temp2 = new HashSet<>();

	public static void main(String[] args) {
		int count=0;
		for(int i= 1; i<9876; i++) {
            all.clear();
            if(isDuplicate(i, temp1)) {
                continue;
            }
            for(int j = 2; j<100; j++) {
                if(!isDuplicate(j*i, temp1)) {
                    int y = 100-j;
                    if(!isDuplicate(y, temp2) && all.size()==9) {
                        System.out.println(100 + "=" + y + "+" + j*i + "/" + i);
                        count++;
                    }else {
                        all.removeAll(temp1);
                    }
                }
            }
        }
		System.out.println(count);
    }
     
    private static boolean isDuplicate(int n, Set<Integer> temp) {
        temp.clear();
        int i = 0;
        boolean flag = false;
        while(n>0) {
            int x = n % 10;
            temp.add(x);
            n = n/10;
            i++;
        }
        if(temp.contains(0) || temp.size()<i || temp.removeAll(all)) {
            flag = true;
        }else {
            all.addAll(temp);
        }
        return flag;
	}
}
