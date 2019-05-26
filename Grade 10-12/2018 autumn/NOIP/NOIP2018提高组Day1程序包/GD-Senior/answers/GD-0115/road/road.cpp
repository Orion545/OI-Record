#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int N = 5e5+7;
struct tre{ int l,r,ls,rs,w; }s[N];
int n,len,ans,a[N];
void build(int fa,int l,int r)
{
	++len; s[len].l = l; s[len].r = r;
	if(s[fa].ls) s[fa].rs = len; else s[fa].ls = len;
	if(l==r){ s[len].w = l; return; } 
	int wz = len,mid = (l+r)>>1;
	build(wz,l,mid); build(wz,mid+1,r);
	int ls = s[wz].ls,rs = s[wz].rs;
	if(a[s[ls].w]<=a[s[rs].w]) s[wz].w = s[ls].w;
		else s[wz].w = s[rs].w;
}
int qur(int dq,int l,int r)
{
	if(l==s[dq].l&&r==s[dq].r) return s[dq].w;
	int mid = (s[dq].l+s[dq].r)>>1;
	if(r<=mid) return qur(s[dq].ls,l,r);
	if(l>mid) return qur(s[dq].rs,l,r);
	int ls = qur(s[dq].ls,l,mid);
	int rs = qur(s[dq].rs,mid+1,r);
	if(a[ls]<=a[rs]) return ls; else return rs;
}
void calc(int l,int r,int sl)
{
	if(l>r) return;
	int dt = qur(1,l,r);
	ans = ans+a[dt]-sl;
	calc(l,dt-1,a[dt]); 
	calc(dt+1,r,a[dt]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n); ans = len = 0;
	fup(i,1,n) scanf("%d",&a[i]);
	build(0,1,n); calc(1,n,0);
	printf("%d",ans);
	return 0;
}

