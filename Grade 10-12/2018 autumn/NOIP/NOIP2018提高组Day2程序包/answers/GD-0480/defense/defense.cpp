#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;

char RR[1000000],*RS=RR,*RT=RR;

#define mygetc() (RS==RT&&(\
RT=(RS=RR)+fread(RR,1,1000000,stdin)\
,RS==RT)?EOF:*RS++)

inline int reint()
{
	register int x=0;
	
	register char ch=mygetc();
	
	while (!isdigit(ch))
	ch=mygetc();
	
	while (isdigit(ch))
	x=x*10+ch-'0',ch=mygetc();
	
	return x;
}

int n,m,M=1,x,y,xx,yy,ans,p[200000],P,t[200000],inneed[200000];

int cur,head[200000],ex[200000],ey[200000];

struct EDGE{
	int nex,t;
	
	EDGE(int nex=0,int t=0)
	{this->nex=nex,this->t=t;}
}edge[1000000];

inline void addedge(int x,int y)
{
	edge[++cur]=EDGE(head[x],y),head[x]=cur,
	edge[++cur]=EDGE(head[y],x),head[y]=cur;
}

int main()
{
	freopen("defense.in","r",stdin),
	freopen("defense.out","w",stdout);
	
	n=reint(),
	m=reint(),
	RS+=3;
	
	for (register int i=1;i<=n;++i)
	M+=p[i]=reint();
	
	for (register int i=1;i<n;++i)
	addedge(ex[i]=reint(),ey[i]=reint());
	
	while (m--)
	{
		x=reint(),xx=reint(),
		y=reint(),yy=reint(),
		ans=M;
		
		for (register int s=0;s<(1ll<<n);++s)
		{
			if ((s>>(x-1)&1)!=xx||(s>>(y-1)&1)!=yy)continue;
			
			P=0;
			
			for (register int i=1;i<=n;++i)
			P+=p[i]*(t[i]=((s>>(i-1))&1));
			
			for (register int i=1;i<n;++i)
			if (!t[ex[i]]&&!t[ey[i]]){P=M;break;}
			
			ans=min(ans,P);
		}
		
		ans==M?printf("-1"):printf("%d",ans);
		
		printf("\n");
	}
	
	return 0;
}
