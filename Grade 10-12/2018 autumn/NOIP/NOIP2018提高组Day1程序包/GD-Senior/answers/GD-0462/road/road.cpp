#include <cstdio>
using namespace std;
#define ll long long
#define il inline
#define rg register
#define fileName "road"

il char gtc();
il int read();

int N,ans;
int D[100005],d[100005];

int main(){
	freopen(fileName".in","r",stdin),
	freopen(fileName".out","w",stdout),
	N=read();
	for(rg int i=1;i<=N;++i)
		D[i]=read(),
		d[i]=D[i]-D[i-1],
		(d[i]>0)?(ans+=d[i]):(0);
	printf("%d",ans);
	return 0;
}

char gtc(){
	static char buff[0xFFFF],*p1=buff,*p2=buff;
	return ((p1==p2)&&(p2=(p1=buff)+fread(buff,1,0xFFFF,stdin),p1==p2))?(EOF):(*p1++);
}
int read(){
	int t=0;
	char c=gtc();
	while((c<'0')||(c>'9'))
		c=gtc();
	while((c>='0')&&(c<='9'))
		t=t*10+c-'0',
		c=gtc();
	return t;
}
