#include<cstdio>
#include<algorithm>
#define N 50010
#define INF 2147483647
using namespace std;
int n,d[N],mx,ans,l,r,num,h[N],p,q,o,m,flag1,flag2,a[N],sum,mn,tmp,c[N],f[N],s[N];
struct Edge{
	int p,q,o,n;
}e[N*2];
struct Line{
	int p,q,o;
}b[N];
int Fa(int x){
	if(x==f[x])return x;
	f[x]=Fa(f[x]);
	return f[x];
}
bool cmp(int p,int q){
	return p>q;
}
bool cmp2(Line p,Line q){
	return p.o>q.o;
}
void ljb(int p,int q,int o){
	e[++num].n=h[p];
	e[num].p=p;
	e[num].q=q;
	e[num].o=o;
	h[p]=num;
}
void dfs(int x,int fa){
	for(int i=h[x];i!=0;i=e[i].n){
		if(e[i].q==fa)continue;
		d[e[i].q]=d[x]+e[i].o;
		dfs(e[i].q,x);
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	flag1=1;
	flag2=1;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&p,&q,&o);
		b[i].p=p;
		b[i].q=q;
		b[i].o=o;
		a[q]=o;
		sum+=o;
		if(p!=1)flag1=0;
		if(q!=p+1)flag2=0;
		ljb(p,q,o);
		ljb(q,p,o);
	}
	if(flag1){
		sort(a+2,a+n+1,cmp);
		printf("%d\n",a[m+1]);
		return 0;
	}
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
//	printf("\n");
	if(flag2){
		tmp=0;
		mn=INF;
		for(int i=2;i<=n;i++){
			tmp=tmp+a[i];
			if(tmp>=sum/3){
				mn=min(mn,tmp);
				tmp=0;
			}
		}
		printf("%d\n",mn);
		return 0;
	}
	if(m==1){
		dfs(1,0);
		mx=0;
		for(int i=1;i<=n;i++){
			if(d[i]>mx){
				mx=d[i];
				l=i;
			}
		}
		d[l]=0;
		dfs(l,0);
		ans=0;
		for(int i=1;i<=n;i++){
			if(d[i]>ans){
				ans=d[i];
				r=i;
			}
		}
//		printf("%d %d\n",l,r);
		printf("%d\n",ans);
		return 0;
	}
	sort(b+1,b+n,cmp2);
	for(int i=1;i<n;i++){
		if(c[b[i].q]<2&&c[b[i].p]<2){
			p=Fa(b[i].p);
			q=Fa(b[i].q);
			s[f[b[i].p]]+=s[f[b[i].q]]+b[i].o;
			s[f[b[i].q]]=0;
			f[f[b[i].q]]=f[b[i].p];
			c[b[i].q]++;
			c[b[i].p]++;
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);
//	printf("\n");
	ans=INF;
	for(int i=1;i<=n;i++)if(s[i]!=0)ans=min(ans,s[i]);
	sort(s+1,s+n+1,cmp);
	if(s[m]==0)printf("%d\n",ans);
	else printf("%d\n",s[m]);
}
