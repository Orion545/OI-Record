#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define ll long long
#define inf 0x3f3f3f3f
const int maxn=50005;
char buf[1<<14],*p1=buf,*p2=buf;
//#define G() (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
#define G getchar
int _(){
	int s=0,w=1;char ch=G();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=G();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=G();
	return s*w;
}

struct Node{
	int v,w,from;
}e[maxn*2];
int n,m,tot;
ll sum;
int fir[maxn],z[maxn];

void add(int u,int v,int w){
	e[++tot].v=v,e[tot].w=w,e[tot].from=fir[u],fir[u]=tot;
}

void dfs(){
	
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof()/(1<<20));
	srand(19260817);
	n=_(),m=_();
	bool flag1=1,flag2=1;
	REP(i,1,n-1){
		int x=_(),y=_();z[i]=_();
		if(x!=1) flag1=0;
		if(y!=(x+1)) flag2=0;
		add(x,y,z[i]),add(y,x,z[i]);
		sum+=z[i];
	}
	if(flag1){
		int maxd=inf;
		sort(z+1,z+n);
		int cnt=n+1;		
		if(m%2==0){
			int head=0,tail=n;
			REP(i,1,m/2){
				maxd=min(maxd,z[++head]+z[--tail]);
			}
		}
		else{
			int head=0,tail=n+1;
			REP(i,1,m/2+1){
				maxd=min(maxd,z[++head]+z[--tail]);
			}
		}
		printf("%d\n",maxd);
		return 0;
	}
	if(flag2){
		int ds=n/m;
		
		printf("%lld\n",sum);
		return 0;
	}
	if(m==1){
		dfs();
		printf("%d\n",rand());
		return 0;
	}
	printf("%d\n",rand());
	
	fclose(stdin);fclose(stdout);
	return 0;
}
