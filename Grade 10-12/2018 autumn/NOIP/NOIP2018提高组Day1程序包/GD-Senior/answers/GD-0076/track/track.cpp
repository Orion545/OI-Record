#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
int n,m,k1,k2,k3,l,r;
int head[N],to[N<<1],nxt[N<<1],val[N<<1],tot;
int deep[N],dis[N],fa[N][19],ye[N],cnt,ans;
inline int read()
{
	int rt=0,f=1;	char ch=getchar();
	while(ch<'0'||ch>'9'){	if(ch=='-')	f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-48;ch=getchar();}
	return f*rt;
}
int max(int a,int b)
{
	return a>b?a:b;
}
void add(int u,int v,int w)
{
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
void jianshu(int x)
{
	bool flag=0;
	for(int i=head[x];i;i=nxt[i]){
		int son=to[i];
		if(son==fa[x][0])	continue;
		flag=1;
		deep[son]=deep[x]+1;
		dis[son]=dis[x]+val[i];
		fa[son][0]=x;
		jianshu(son);
	}
	if(flag==0){
		ye[++cnt]=x;
	}
}
int lca(int x,int y)
{
	if(x==y)	return x;
	if(deep[x]<deep[y])	{x=x^y;	y=x^y;	x=x^y;}
	for(int i=18;i>=0;i--){
		if(deep[fa[x][i]]>=deep[y])	
			x=fa[x][i];
	}
	if(x==y)	return x;
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}	
	}
	return fa[x][0];
}
void lcachushi()
{
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
int suan(int x,int y)
{
	int rt=0;
	rt+=dis[x]-dis[lca(x,y)];
	rt+=dis[y];
	return rt;
}
void zuichanglu()
{
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			ans=max(ans,suan(i,j));
}
bool cmp(int a,int b)
{
	return a<b;
}
bool check1(int x)
{

	int tou=1,wei=n-1,ok=0;
	while(tou<=wei){
		if(val[wei]>=x){
			wei--;
			ok++;
			continue;
		}
		if(val[wei]+val[tou]>=x){
			wei--;
			tou++;
			ok++;
			continue;
		}
		tou++;
	}
	if(ok>=m)	return 1;
	return 0;
}
bool check2(int x)
{
	int now=1,ok=0,sum=0;
	while(now!=n){
		for(int i=head[now];i;i=nxt[i]){
			int son=to[i];
			if(son!=now+1)	continue;
			sum+=val[i];
			if(sum>=x){
				ok++;
				sum=0;
			}
		}
		now++;
	}
	if(ok>=m)	return 1;
	return 0;	
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();	m=read();
	k1=1;	k2=1;	k3=1;
	if(m!=1)	k1=0;
	for(int i=1;i<n;i++){
		int aa,bb,cc;
		aa=read();	bb=read();	cc=read();
		if(aa!=1)	k2=0;
		if(bb!=aa+1)	k3=0;
		add(aa,bb,cc);	add(bb,aa,cc);
		r+=cc;
	}
	if(n==2){
		printf("%d",val[1]);
		return 0;
	}	
	deep[1]=1;
	jianshu(1);
	lcachushi();
	if(k1==1){//m=1
		zuichanglu();
		printf("%d",ans);
		return 0;
	}
	if(k2==1)
	{
		sort(val+1,val+n,cmp);
		while(l<=r){
			int mid=(l+r)>>1;
			if(check1(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k3==1){//“ªÃı¡¥ 
		while(l<=r){
			int mid=(l+r)>>1;
			if(check2(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",ans);
		return 0;
	}
	int u;
	printf("%d",u);
	return 0;
}
