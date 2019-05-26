#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 2147483647
using namespace std;
struct node{int x,xj,y,yj,num;}q[100010];
int n,c[100010],m;
long long f[100010][2],f1[100010][2],ans[100010];
bool _cmp(node a,node b)
{
	if (a.x==b.x)
	 return a.y>b.y;
	  else return a.x>b.x;
}
void workA()
{
	for (int i=1;i<=n;i++)
	 scanf("%d",&c[i]);
	int a,b;
	for (int i=1;i<=n-1;i++)
	 scanf("%d%d",&a,&b);
	for (int i=1;i<=m;i++)
	 {
	 	scanf("%d%d%d%d",&q[i].x,&q[i].xj,&q[i].y,&q[i].yj),q[i].num=i;
	 	if (q[i].x>q[i].y) {swap(q[i].x,q[i].y); swap(q[i].xj,q[i].yj);}
	 }
	  
	sort(q+1,q+m+1,_cmp);

	for (int i=1;i<=n;i++)
	 {
	 	f[i][0]=f[i-1][1];
	 	f[i][1]=f[i-1][0]+c[i];
	 }
	for (int i=1;i<=m;i++)
	 {
	 	int x=q[i].x,y=q[i].y,xj=q[i].xj,yj=q[i].yj,num=q[i].num;
	 	if (xj)
	 	 f1[x][xj]=f1[x-1][0]+c[x],f1[x][0]=-1;
	 	  else f1[x][xj]=f1[x-1][1],f1[x][1]=-1;
	 
		for (int j=x+1;j<=n;j++)
		 if (y==j)
		  {
		  	if (yj)
		  	 {
		  	 	if (f1[y-1][0]!=-1)
		  	 	 f1[y][yj]=f1[y-1][0]+c[y],f1[y][0]=-1;
		  	 	  else f1[y][1]=-1,f1[y][0]=-1;
		  	 }
	 	 	  
	 	  	   else f1[y][yj]=f1[y-1][1],f1[y][1]=-1;
		  }
		  else
		   {
		   	 if (f1[j-1][0]==-1)
		   	  f1[j][1]=-1;
		   	   else f1[j][1]=f1[j-1][0]+c[j];
		   	 if (f1[j-1][1]==-1)
		   	  f1[j][0]=-1;
		   	   else f1[j][0]=f1[j-1][1];
		   }
		ans[num]=min(f1[n][1],f1[n][0]);
		if (f1[n][0]==-1)
		 ans[num]=f1[n][1];
		if (f1[n][1]==-1)
		 ans[num]=f1[n][0];
	 }	
	
	for (int i=1;i<=m;i++)
	 printf("%lld\n",ans[i]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	char ch;int ft;
	cin>>ch;
	cin>>ft;
	if (ch=='A')
	 	workA();
	return 0;
}

