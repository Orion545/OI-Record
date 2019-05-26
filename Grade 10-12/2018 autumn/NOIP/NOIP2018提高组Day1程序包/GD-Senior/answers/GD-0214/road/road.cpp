#include<cstdio>
#include<iostream>
#include<algorithm>
#define ls (x<<1)
#define rs (x<<1|1)
#define M ((l+r)>>1)
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int N=100003;
int n,a[N],pos,ans;
int s[N*4],id[N*4],opl,opr,ops;
void build(int x,int l,int r)
{
	if(l==r)
	{
		s[x]=a[id[x]=l];
		return;
	}
	int m=M;
	build(ls,l,m);
	build(rs,m+1,r);
	if(s[ls]<s[rs])s[x]=s[ls],id[x]=id[ls];
		else s[x]=s[rs],id[x]=id[rs];
}
void find(int x,int l,int r)
{
	if(opl<=l && r<=opr)
	{
		if(s[x]<ops)pos=id[x],ops=s[x];
		return;
	}
	int m=M;
	if(opl<=m)find(ls,l,m);
	if(m<opr)find(rs,m+1,r);
}
void solve(int v,int l,int r)
{
	opl=l;opr=r;ops=N;
	find(1,1,n);
	ans=ans+ops-v;v=ops;
	if(l<pos)solve(v,l,pos-1);
	if(pos<r)solve(v,pos+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	solve(0,1,n);
	printf("%d",ans);
	return 0;
}
