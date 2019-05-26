#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#define ll long long
#define maxn 50010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
struct edge{
	int to,nxt,d;
}e[2*maxn];
int fir[maxn],use[maxn];
ll len[maxn],a[maxn];
int n,m,tot;
void add_edge(int x,int y,int z){e[tot].to=y; e[tot].d=z; e[tot].nxt=fir[x]; fir[x]=tot++;}
int calc(int sz,int mid,int t)
{
	for(int i=1;i<=sz;i++)use[i]=0; use[t]=1;
	int k=1,cnt=0;
	for(int i=sz;i;i--){
		if(use[i])continue;
		if(a[i]>=mid)++cnt,use[i]=1;
		else{
			while(k<i&&(a[i]+a[k]<mid||use[k]))++k;
			if(k<i&&a[i]+a[k]>=mid&&!use[k]){
				++cnt; use[i]=use[k++]=1;
			}
		}
	}
	return cnt;
}
int dfs(int now,ll mid,int fa)
{
	int sz=0,tot=0;
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa)tot+=dfs(e[i].to,mid,now);
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa){
			a[++sz]=len[e[i].to]+e[i].d;
		}
	std::sort(a+1,a+sz+1);
	for(int i=1;i<=sz;i++)use[i]=0;
	int k=1,cnt=0;
	for(int i=sz;i;i--){
		if(use[i])continue;
		if(a[i]>=mid)++cnt,use[i]=1;
		else{
			while(k<i&&a[i]+a[k]<mid)++k;
			if(k<i&&a[i]+a[k]>=mid){
				++cnt; use[i]=use[k++]=1;
			}
		}
	}
	int l=0,r=sz;
	while(l<r){
		int Mid=(l+r+1)>>1;
		if(calc(sz,mid,Mid)==cnt)l=Mid;
		else r=Mid-1;
	}
	if(l)len[now]=a[l];
	else len[now]=0;
//	printf("%d %d %d %d %I64d\n",now,tot,cnt,l,len[now]);
//	for(int i=1;i<=sz;i++)
//		printf("%d %I64d\n",i,a[i]);
	return tot+cnt;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	memset(fir,255,sizeof(fir)); tot=0;
	ll sum=0;
	for(int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z); add_edge(y,x,z);
		sum+=z;
	}
	ll l=0,r=sum;
	while(l<r){
		ll mid=(l+r+1)>>1;
//		printf("*********** %I64d %I64d %I64d\n",l,r,mid);
		int k=dfs(1,mid,-1);
		if(k>=m)l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	fclose(stdin); fclose(stdout);
	return 0;
}
