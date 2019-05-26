#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

namespace mine
{
	typedef long long ll;
	
	const int MAX_N=110000;
	
	struct Data
	{
		int mi,pos;
	};
	struct Seg
	{
		Data s[MAX_N*4];
		int fg[MAX_N*4];
		#define lc 2*x
		#define rc 2*x+1
		void build(int x,int l,int r)
		{
			s[x].mi=0;s[x].pos=l;
			if(l<r)
			{
				int mid=(l+r)>>1;
				build(lc,l,mid);
				build(rc,mid+1,r);
			}
		}
		void update(int x)
		{
			s[lc].mi+=fg[x];fg[lc]+=fg[x];
			s[rc].mi+=fg[x];fg[rc]+=fg[x];
			fg[x]=0;
		}
		Data merg(Data a,Data b)
		{
			Data tmp;
			tmp.mi=min(a.mi,b.mi);
			if(a.mi==tmp.mi) tmp.pos=a.pos;
			else tmp.pos=b.pos;
			return tmp;
		}
		void change(int x,int l,int r,int fl,int fr,int c)
		{
			if(l==fl and r==fr)
			{
				s[x].mi+=c;fg[x]+=c;
				return;
			}
			if(fg[x]!=0) update(x);
			
			int mid=(l+r)>>1;
			if(fr<=mid) change(lc,l,mid,fl,fr,c);
			else if(fl>mid) change(rc,mid+1,r,fl,fr,c);
			else change(lc,l,mid,fl,mid,c),change(rc,mid+1,r,mid+1,fr,c);
			
			s[x]=merg(s[lc],s[rc]);
		}
		Data ask(int x,int l,int r,int fl,int fr)
		{
			if(l==fl and r==fr) return s[x];
			if(fg[x]!=0) update(x);
			int mid=(l+r)>>1;
			if(fr<=mid) return ask(lc,l,mid,fl,fr);
			else if(fl>mid) return ask(rc,mid+1,r,fl,fr);
			else return merg( ask(lc,l,mid,fl,mid),ask(rc,mid+1,r,mid+1,fr) );
		}
	}sgt;
	
	ll ans=0;
	
	int n;
	void solve(int l,int r)
	{
		if(l>r) return;
		
		Data dd=sgt.ask(1,1,n,l,r);
		ans+=dd.mi;
		sgt.change(1,1,n,l,r,-dd.mi);
		
		int lst=l;
		while(lst<=r)
		{
			Data t=sgt.ask(1,1,n,lst,r);
			if(t.mi!=0) break;
			solve(lst,t.pos-1);
			lst=t.pos+1;
		}
		if(lst<=r) solve(lst,r);
	}
	/*
	其实st表就好了…… 
	*/
	void main()
	{
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		
		scanf("%d",&n);
		sgt.build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			int d;scanf("%d",&d);
			sgt.change(1,1,n,i,i,d);
		}
		solve(1,n);
		cout<<ans;
	}
}
int main()
{
	srand(time(0));
	mine::main();
}
