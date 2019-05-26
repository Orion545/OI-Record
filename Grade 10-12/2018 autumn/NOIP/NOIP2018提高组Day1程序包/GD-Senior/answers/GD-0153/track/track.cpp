#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define in(a) a=read()
#define out(a) printf("%d\n",a)
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(a,x) memset(a,x,sizeof(a))
int read(){
	int f=1,x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
#define maxn 50010
int L,nxt[maxn*2],head[maxn],to[maxn*2],v[maxn*2];
void add(int x,int y,int z){L++;nxt[L]=head[x];head[x]=L;to[L]=y;v[L]=z;}
int bfs[maxn],d[maxn];
int n,m;
void baoli1(){
	int l=1,r=2;
	bfs[l]=1;
	while(l<r){
		int x=bfs[l++];
		FORL(i,x){
			int c=to[i];
			if(!d[c]&&c!=1){
				d[c]=d[x]+v[i];
				bfs[r++]=c;
			}
		}
	}
	int X=0,mx=0;
	FOR(i,1,n){
		if(d[i]>mx){
			mx=d[i];
			X=i;
		}
		d[i]=0;
	}
	l=1,r=2;
	bfs[l]=X;
	while(l<r){
		int x=bfs[l++];
		FORL(i,x){
			int c=to[i];
			if(!d[c]&&c!=X){
				d[c]=d[x]+v[i];
				bfs[r++]=c;
			}
		}
	}
	mx=0;
	FOR(i,1,n)mx=max(mx,d[i]);
	out(mx);
}
int a[maxn];
bool check(int x){
	int s=0,ans=0;
	FOR(i,2,n){
		s+=a[i];
		if(s>=x){
			s=0;
			ans++;
		}
	}
	return ans>=m;
}
void baoli2(){
	int l=v[1],r=1;
	for(int i=1;i<=L;i+=2){
		r+=v[i],l=min(l,v[i]);
		a[to[i]]=v[i];
	}
	l--;
//	cout<<l<<' '<<r<<endl;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		 else r=mid;
	}	
	out(l);
}
void baoli3(){
	for(int i=1;i<=L;i+=2)a[i/2+1]=v[i];
	sort(a+1,a+n);
	int ans=maxn;
	if(m<=n/2){
		FOR(i,1,m)ans=min(ans,a[n-i]+a[n-m-i]);
	}	
	 else {
	 	int c=n-1-m;
	 	FOR(i,1,c)ans=min(ans,a[i]+a[c+c-i+1]);
	 	FOR(i,c*2+1,n-1)ans=min(ans,a[i]);
	 }
	out(ans);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	in(n);in(m);
	bool f1=1,f2=1;
	int mn=maxn,mx=0;
	FOR(i,1,n-1){
		int x,y,z;
		in(x);in(y);in(z);
		add(x,y,z);
		add(y,x,z);
		mn=min(mn,z);
		mx=max(mx,z);
		f1&=(y==x+1);
		f2&=(x==1);
	}
	if(m==1)baoli1();
	 else if(m==n-1)out(mn);
	  else if(f1)baoli2();
	   else if(f2)baoli3();
	    else out(mx);
	fclose(stdin);fclose(stdout);
	return 0;
}
