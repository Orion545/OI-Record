#include<iostream>
#include<cstdio>
#include<fstream>
	using namespace std;
struct shujv {int u,v,w;} s[400005];
	int n=0,ans=0,x[100005];
void jian(int p,int l,int r)
{
	s[p].w=0;
	if(l==r) {s[p].u=x[l],s[p].v=l;return;}
	int mid=(l+r)>>1;
	jian(p<<1,l,mid);
	jian(p<<1|1,mid+1,r);
	if(s[p<<1].u<s[p<<1|1].u) s[p].u=s[p<<1].u,s[p].v=s[p<<1].v;
					 	 else s[p].u=s[p<<1|1].u,s[p].v=s[p<<1|1].v;
}
void jia(int p,int k) {s[p].u+=k,s[p].w+=k;}
void xia(int p)
{
	jia(p<<1,s[p].w);
	jia(p<<1|1,s[p].w);
	s[p].w=0;
}
void j_ia(int p,int l,int r,int x,int y,int k)
{
	if(l==x&&r==y) {jia(p,k);return;}
	xia(p);
	int mid=(l+r)>>1;
	if(y<=mid) j_ia(p<<1,l,mid,x,y,k);
	else if(x>mid) j_ia(p<<1|1,mid+1,r,x,y,k);
	else j_ia(p<<1,l,mid,x,mid,k),j_ia(p<<1|1,mid+1,r,mid+1,y,k);
	if(s[p<<1].u<s[p<<1|1].u) s[p].u=s[p<<1].u,s[p].v=s[p<<1].v;
					 	 else s[p].u=s[p<<1|1].u,s[p].v=s[p<<1|1].v;
}
shujv wen(int p,int l,int r,int x,int y)
{
	if(l==x&&r==y) return s[p];
	xia(p);
	int mid=(l+r)>>1;
	if(y<=mid) return wen(p<<1,l,mid,x,y);
	if(x>mid) return wen(p<<1|1,mid+1,r,x,y);
	shujv a=wen(p<<1,l,mid,x,mid);
	shujv b=wen(p<<1|1,mid+1,r,mid+1,y);
	if(a.u<b.u) return a;
	return b;
}
void gao(int l,int r)
{
	if(l>r) return;
	shujv t=wen(1,1,n,l,r);
	ans+=t.u;
	j_ia(1,1,n,l,r,-t.u);
	gao(l,t.v-1);
	gao(t.v+1,r);
}	
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	jian(1,1,n);
	gao(1,n);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
