#include <stdio.h>
int dp[100][100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
    {
	    for(int j=i+1;j<=n;j++)
	    {
			scanf("%d",&dp[i][j]);
		}
	}

	for(int k=2;k<n;k++)
	{
		for(int i=1;i<=n-k;i++)
		{
			int j=i+k;
			for(int z=i+1;z<=j;z++)
			{
				int temp=dp[i][z]+dp[z][j];
				if(dp[i][j]>temp)
					dp[i][j]=temp;
			}
		}
	}

	printf("%d\n",dp[1][n]);
	return 0;
}
