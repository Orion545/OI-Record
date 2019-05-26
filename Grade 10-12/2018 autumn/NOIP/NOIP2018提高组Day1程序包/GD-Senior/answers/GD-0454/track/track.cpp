#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int f[N],len[N],next[N],h[N],v[N],g[N],a[N],b[N];
int n,m,x,y,z,l,r,mid,top,now,ex,tot,sum;
void add(int x,int y,int z)
{
	f[++tot]=y;
	len[tot]=z;
	next[tot]=h[x];
	h[x]=tot;
}
void dfs(int t,int fat)
{
	v[t]=0;
	g[t]=0;
	int p=h[t];
	while(p){
		if(f[p]!=fat)dfs(f[p],t);
		p=next[p];
	}
	p=h[t];
	top=0;
	while(p){
		if(f[p]!=fat){
			g[t]+=g[f[p]];
			a[++top]=v[f[p]]+len[p];	
		}
		p=next[p];
	}
	sort(a+1,a+top+1);
	if(a[1]>=mid)g[t]+=top;
	else{
		fd(i,top,1){
			if(a[i]>=mid)g[t]++;
			else{
				top=i;
				break;
			}
		}
		now=top;
		ex=0;
		fo(i,1,top)if(a[i]){
			while(a[now]+a[i]>=mid&&now>i){
				b[++ex]=now;
				now--;
			}
			while(b[ex]<=i&&ex)ex--;
			if(ex){
				g[t]++;
				a[b[ex]]=a[i]=0;
				ex--;
			}
		}
		fd(i,top,1)if(a[i]){
			v[t]=a[i];
			break;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		sum+=z;
	}
	l=1;
	r=sum;
	while(l<r){
		mid=(l+r)/2;
		if(l==mid)mid++;
		dfs(1,0);
		if(g[1]>=m)l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
