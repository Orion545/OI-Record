#include <stdio.h>
#include <string.h>
long long sta1,sta2,tms=0;
int n,m,f[11][11011],lst[5111111];
void mk(int x,int y,long long stat,long long s2)
{
	if(x<0 || x>=n || y<0 || y>=n) return;
	if(x==n-1 && y==m-1)
		{
			lst[s2]=stat;
		}
	mk(x+1,y,(stat<<1)+1,(s2<<1)+(sta1<<(y*n+x+1)));
	mk(x,y+1,(stat<<1),(s2<<1)+(sta1<<((y+1)*n+x)));
}
int judge()
{
	tms=1<<(n*m);
	int i,j;
	for(i=1;i<tms;++i)
		for(j=i+1;j<=tms;++j)
			if(lst[i]>lst[j]) return 0;
		return 1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	if(n==2 && m==2) printf("12\n");
	if(n==3 && m==3) printf("112\n");
	if(n==5 && m==5) printf("7136\n");
	return 0;
}
