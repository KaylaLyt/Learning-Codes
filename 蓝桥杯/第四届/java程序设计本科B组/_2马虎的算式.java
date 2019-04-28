package À¶ÇÅ±­4B;

public class _2Âí»¢µÄËãÊ½ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int m,n,i,j;
		int count=0;
		for(int a=1;a<10;a++)
		{
			for(int b=1;b<10;b++)
			{
				for(int c=1;c<10;c++)
				{
					for(int d=1;d<10;d++)
					{
						for(int e=1;e<10;e++)
						{
							if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
							{
								m=a*10+b;
								n=c*100+d*10+e;
								i=a*100+d*10+b;
								j=c*10+e;
								if(m*n==i*j) count++;
							}
						}
					}
				}
			}
		}
		System.out.print(count);
	}

}
