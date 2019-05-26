#include <cstdio>
#include <utility>
#define MP make_pair
#define FR first
#define SE second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=100010;
int n;
int a[N];
void readData(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
namespace SEG{
	const int S=N*2;
	int rt,sz;
	int ch[S][2];
	PII info[S];
	int tag[S];
	inline void pushup(int u){
		if(info[ch[u][0]].FR<info[ch[u][1]].FR)
			info[u]=info[ch[u][0]];
		else 
			info[u]=info[ch[u][1]];
	}
	inline void makeTag(int u,int x){
		tag[u]+=x;
		info[u].FR+=x;
	}
	inline void pushdown(int u){
		if(tag[u]){
			makeTag(ch[u][0],tag[u]);
			makeTag(ch[u][1],tag[u]);
			tag[u]=0;
		}
	}
	void build(int &u,int l,int r){
		u=++sz;
		if(l==r){
			info[u]=MP(a[l],l);
			return;
		}
		int mid=(l+r)>>1;
		build(ch[u][0],l,mid);
		build(ch[u][1],mid+1,r);
		pushup(u);
	}
	PII queryMin(int u,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)
			return info[u];
		pushdown(u);
		int mid=(l+r)>>1;
		PII res;
		if(qr<=mid)
			res=queryMin(ch[u][0],l,mid,ql,qr);
		else if(mid<ql)
			res=queryMin(ch[u][1],mid+1,r,ql,qr);
		else{
			PII sl,sr;
			sl=queryMin(ch[u][0],l,mid,ql,mid);
			sr=queryMin(ch[u][1],mid+1,r,mid+1,qr);
			res=sl.FR<sr.FR?sl:sr;
		}
		pushup(u);
		return res;
	}
	void segAdd(int u,int l,int r,int ml,int mr,int x){
		if(ml<=l&&r<=mr){
			makeTag(u,x);
			return;
		}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mr<=mid)
			segAdd(ch[u][0],l,mid,ml,mr,x);
		else if(mid<ml)
			segAdd(ch[u][1],mid+1,r,ml,mr,x);
		else{
			segAdd(ch[u][0],l,mid,ml,mid,x);
			segAdd(ch[u][1],mid+1,r,mid+1,mr,x);
		}
		pushup(u);
	}
}
struct Node{
	int l,r;
	int nex;
}s[N];
int scnt;
void solve(){
	LL ans=0;
	s[scnt=1]=(Node){1,n,0};
	int cur=1;
	while(cur){
		if(s[cur].l>s[cur].r){
			cur=s[cur].nex;
			continue;
		}
		PII p=SEG::queryMin(SEG::rt,1,n,s[cur].l,s[cur].r);
		ans+=p.FR;
		SEG::segAdd(SEG::rt,1,n,s[cur].l,s[cur].r,-p.FR);
		int x=p.SE;
		if(s[cur].l==s[cur].r)
			cur=s[cur].nex;
		else if(s[cur].l+1==s[cur].r){
			if(x==s[cur].l)
				s[cur].l=s[cur].r;
			else
				s[cur].r=s[cur].l;
		}
		else{
			scnt++;
			s[scnt].l=s[cur].l;
			s[scnt].r=x-1;
			s[cur].l=x+1;
			s[scnt].nex=cur;
			cur=scnt;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	readData();
	SEG::build(SEG::rt,1,n);
	solve();
	return 0;
}
