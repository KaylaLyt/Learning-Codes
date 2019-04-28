package À¶ÇÅ±­4A;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class _8´ø·ÖÊı {

    static int n, count;
    static int arr[] = {1,2,3,4,5,6,7,8,9};
    static boolean flag[] = new boolean[10];
    
    static int dev(int s, int e)
    {
        int ans = 0;
        for(int i = s; i <= e; i++)
        {
            ans += arr[i];
            ans *= 10;
        }
        return ans/10;
    }
    
    static void fun2()
    {
        for(int i = 0; i < 7; ++i)
        {
            int a = dev(0,i);
            if(a >= n)
            {
                continue;
            }
            for(int j = i+1; j < 8; ++j)
            {
                int b = dev(i+1,j);
                int c = dev(j+1,arr.length-1);
                if(a+1.0*b/c==n)
                {
                    count++;
                    //System.out.println(a+" + "+b+" / "+c+" = "+n);
                }
            }
        }
    }
    
    static void fun(int cnt)
    {
        if(cnt == arr.length)
        {
            fun2();
            return;
        }
        for(int i = cnt; i < arr.length; ++i)
        {
            {int t = arr[cnt];arr[cnt] = arr[i];arr[i] = t;}
            fun(cnt+1);
            {int t = arr[cnt];arr[cnt] = arr[i];arr[i] = t;}
        }
        
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        fun(0);
        System.out.println(count);
    }

}
