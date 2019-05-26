#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5010;
int n,m,nn,tot,top,cut,len,a[N],b[N],s[N],first[N],e[N<<1][2],cir[N];
bool v[N];
struct edge{int x,y,z;} E[N<<1];
bool operator < (edge i,edge j) {
	return i.x>j.x||(i.x==j.x&&i.y>j.y);
}
inline int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
inline void ins_ed(int z,int x,int y) {
	//printf("add %d %d\n",x,y);
	e[z][1]=y;
	e[z][0]=first[x];
	first[x]=z;
}
void dfs(int x) {
	v[x]=1; a[++nn]=x;
	for (int i=first[x];i;i=e[i][0]) {
		if ((i>>1)==cut) continue;
		int y=e[i][1]; if (!v[y]) dfs(y);
	}
}
void find_circle(int x,int ed) {
	//printf("dfs %d %d\n",x,ed);
	if (v[x]) {
		//printf("QAQ %d %d %d\n",x,ed,top);
		for (int i=top;i>0&&(s[i]==ed||e[s[i]][1]!=x);i--) cir[++len]=(s[i]>>1);
		return;
	}
	v[x]=1;
	for (int i=first[x];i;i=e[i][0]) {
		if ((i>>1)==(ed>>1)) continue;
		s[++top]=i; find_circle(e[i][1],i);
		if (len) return; top--;
	}
}
bool sma() {
	for (int i=1;i<=n;i++) {
		if (b[i]<a[i]) return 0;
		if (b[i]>a[i]) return 1;
	}
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=m;i++) {
		E[i+m].y=E[i].x=read(); E[i+m].x=E[i].y=read(); E[i+m].z=E[i].z=i*2; E[i].z++;
	}
	m<<=1;
	tot=1; sort(E+1,E+m+1);
	for (int i=1;i<=m;i++) ins_ed(E[i].z,E[i].x,E[i].y);
	if ((m>>1)==n-1) {
		dfs(1);
		for (int i=1;i<=n;i++) printf("%d ",a[i]); printf("\n");
		return 0;
	}
	find_circle(1,0);
	//for (int i=1;i<=len;i++) printf("%d ",cir[i]); printf("\n");
	for (int i=1;i<=len;i++) {
		cut=cir[i]; memset(v,0,sizeof(v)); nn=0; dfs(1);
		if (i==1||sma()) for (int j=1;j<=n;j++) b[j]=a[j];
	}
	for (int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
	return 0;
}
