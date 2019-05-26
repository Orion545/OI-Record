#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
#define ll long long
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(f=='-') f=-f; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int N=1e5+5;
int n,d[N],mn[N<<2];
#define lson (rt<<1)
#define rson ((rt<<1)|1)
inline void up(int rt) { mn[rt]=(d[mn[lson]]<=d[mn[rson]])?mn[lson]:mn[rson]; } //��������������������0����Сֵ����������������������СֵС������Сֵ������������������䣬��֮������������������� 
inline void build(int l,int r,int rt) { 
	if(l==r) { mn[rt]=l; return; } //�����Ҷ�ӽڵ㣬ֱ�ӷ��� 
	int mid=(l+r)>>1;
	build(l,mid,lson); build(mid+1,r,rson); //ͳ��������������Сֵ���ڵ�λ�� 
	up(rt);
}
inline int ask(int L,int R,int l,int r,int rt) { //L..R�������Сֵ���±���ʲô 
	if(L<=l&&r<=R) return mn[rt];
	int res=2e9,mid=(l+r)>>1,now=0,ans=0;
	if(L<=mid) { now=ask(L,R,l,mid,lson);  if(d[now]<=res) { res=d[now]; ans=now; } }//����������Ĵ𰸱�resС����L..R����Сֵ������������ 
	if(R>mid) { now=ask(L,R,mid+1,r,rson); if(d[now]<=res) { res=d[now]; ans=now; } }//����������Ĵ𰸱�resС����L..R����Сֵ������������ 
	return ans; 
}
inline ll solve(int l,int r,long long tag) { //tagΪ����[l,r],Ӧ�ü�ȥ���٣����ǲ�ʵ���޸� 
	if(l>=r) return d[l]-tag; 
	int pos=ask(l,r,1,n,1);
	ll ans=0ll;
	if(l<=pos-1) ans+=solve(l,pos-1,d[pos]); //��[l,pos-1]���� 
	if(pos+1<=r) ans+=solve(pos+1,r,d[pos]); //��[pos+1,r]���� 
	return ans-tag+d[pos]; //�𰸼��ϵ�ǰ�������Сֵ��ȥ����ϵ�ֵ,���:�������䱻���˶���,����Ǳ�����û� 
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&d[i]);
	build(1,n,1);
	printf("%lld\n",solve(1,n,0ll));
}
