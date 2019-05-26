
#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cctype>
#define cg c=getchar()
#define pc putchar
#define ic isdigit(c)
#define ll long long
#define tt(a) template<typename a>
using namespace std;

const int MAXN = 100000+10;
const int LOG  = 20;
int n,d[MAXN],f[MAXN][25],pos[MAXN][25];
ll ans;

tt(GD) void read(GD& x)
{
	x=0; bool f=0;char cg; 
	while(!ic) { if(c=='-')  f=1; cg;}
	while(ic) x=(x<<3)+(x<<1)+(c^48),cg;
	if(f) x=-x;
}

tt(GD) void write(GD x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+48);
}

void ST()
{
	for(int i=1;i<=LOG;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			if(f[j][i-1]<f[j+(1<<(i-1))][i-1])
			{
				f[j][i]=f[j][i-1];
				pos[j][i]=pos[j][i-1];
			}
			else
			{
				f[j][i]=f[j+(1<<(i-1))][i-1];
				pos[j][i]=pos[j+(1<<(i-1))][i-1];
			}
}

void work(int l,int r,int tmp)
{
	if(l==r) 
	{
		ans+=(f[l][0]-tmp);
		return;
	}
	int d=r-l+1;
//	cout<<"		d "<<d<<" l "<<l<<" r "<<r<<endl;
	int tlog=log2(d);
//	cout<<"		tlog"<<tlog<<endl;
	int minn=0,poss=0;
//	cout<<f[l][tlog]<<" "<<f[r-(1<<tlog)+1][tlog]<<endl;
	if(f[l][tlog]<f[r-(1<<tlog)+1][tlog])
	{
		minn=f[l][tlog];
		poss=pos[l][tlog];
	}
	else
	{
		minn=f[r-(1<<tlog)+1][tlog];
		poss=pos[r-(1<<tlog)+1][tlog];
	}
	ans+=(minn-tmp);
//	cout<<"    "<<minn<<"  "<<poss<<endl;
	if(l<=poss-1) work(l,poss-1,minn);
	if(poss+1<=r) work(poss+1,r,minn);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	read(n);
	for(int i=1;i<=n;i++) 
	{
		read(d[i]); f[i][0]=d[i]; pos[i][0]=i;
	}
	ST();  //ok!!!!!
	work(1,n,0);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
