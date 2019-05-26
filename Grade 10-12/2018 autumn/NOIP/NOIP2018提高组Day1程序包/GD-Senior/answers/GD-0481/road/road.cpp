#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define ll long long
const int maxn=100005;
char buf[1<<14],*p1=buf,*p2=buf;
//#define G() (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
#define G getchar
int _(){
	int s=0,w=1;char ch=G();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=G();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=G();
	return s*w;
}

int n,mind;
ll cnt;
int h[maxn],f[maxn];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof()/(1<<20));
	
	n=_();
	mind=0x3f3f3f3f;
	REP(i,1,n){
		h[i]=_();
		mind=min(mind,h[i]);
	}
	cnt=mind;
	REP(i,1,n){
		h[i]-=cnt;
	}
	f[1]=h[1];
	REP(i,2,n){
		if(h[i-1]>=h[i]) f[i]=f[i-1];
		else f[i]=h[i]-h[i-1],cnt+=f[i-1];
		if(i==n) cnt+=f[i];
	}
	printf("%lld\n",cnt);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
