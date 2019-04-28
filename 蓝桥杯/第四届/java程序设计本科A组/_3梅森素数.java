package À¶ÇÅ±­4A;

import java.math.BigInteger;

public class _3Ã·É­ËØÊı {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger n = new BigInteger("2");
		String string;

		for (int i = 1; i < 11213; i++) {

			n = n.shiftLeft(1);
		}

		n = n.subtract(BigInteger.valueOf(1));
		string = n.toString();

		string = string.substring(string.length() - 100);

		System.out.println(string);

	}

}
