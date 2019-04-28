#include<stdio.h>

void main()
{
	int max,min;
	int a[10];
	int i,n;
	scanf("%d", &n);
	for( i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
		max=a[0];
	min=a[0];
	for(i=1;i<n;i++){
			if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	
	
	printf("max=%d ,min=%d", max, min);
}

/*#include<stdio.h> 
int main() 
{ 
float a[10],min,max; 
int i; 
printf("please enter 10 num\n"); 
int n;
scanf("%d",&n);
for(i=0;i<n;i++) 
{ 
scanf("%f",&a[i]); 
}//输入 
min=max=a[0]; 
//假设第一个数是最小的数，且是最大数 
for(i=1;i<n;i++) 
{ 
//依次与其它各数比较 
if(a[i]>max) 
{ 
max=a[i]; 
} 
else if(a[i]<min) 
{ 
min=a[i]; 
} 
} 
printf("\nmax is %f min is %f\n",max,min); 
} */
