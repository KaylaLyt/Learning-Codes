#include<stdio.h>
struct point{
	int s,e,v;
};
struct point map[10005];
int vis[10005];
int n,j;
int mx=0;
void dfs(int cur,int dist)
{
	if(dist>mx)
	{mx=dist;j=cur;}
	for(int i=0;i<n-1;i++)
	if(cur==map[i].s&&!vis[map[i].e])
	{
		vis[map[i].e]=1;
		dfs(map[i].e,dist+map[i].v);
		vis[map[i].e]=0;
	}
	else if(cur==map[i].e&&!vis[map[i].s])
	{
		vis[map[i].s]=1;
		dfs(map[i].s,dist+map[i].v);
		vis[map[i].s]=0;
	}


}
//一个结论- -
//先以第一个顶点为根，进行一次dfs，
//找出从第一个点出发的最长的一个直径，然后再以直径的另外一个端点a,
//为根进行一次dfs，又可以找出另外一个端点b，可以证明(a,b)即为树的直径（树上任意俩点最远的距离）
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	scanf("%d%d%d",&map[i].s,&map[i].e,&map[i].v);
	vis[1]=1;
	dfs(1,0);
	vis[1]=0;
	vis[j]=1;
	dfs(j,0);
	vis[j]=0;
	printf("%d",(mx+1)*mx/2+10*mx);
	return 0;
}
