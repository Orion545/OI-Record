#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define next nextt
#define N 50001
#define M 200001
#define inf 1000000007
using namespace std;
int n,m;
int to[M],next[M],ce[N],len[M],cnt=0;
int getfar(int v,int &fv,int last){
	int p,s,mx=v,dis;
	dis=0;
	for(p=ce[v];p;p=next[p]){
		if(to[p]==last) continue;
		s=getfar(to[p],fv,v)+len[p];
		if(s>dis){
			dis=s;
			mx=fv;
		}
	}
	fv=mx;
	return dis;
}
void link(int u,int v,int w){
	to[++cnt]=v;
	len[cnt]=w;
	next[cnt]=ce[u];
	ce[u]=cnt;
	to[++cnt]=u;
	len[cnt]=w;
	next[cnt]=ce[v];
	ce[v]=cnt;
}
//-----------------
int work1(){  //m=1
	int p,i,a,b,l;
	for(i=1;i<n;i++){
		cin>>a>>b>>l;
		link(a,b,l);
	}
	a=1;
	p=getfar(1,a,1);
	p=getfar(a,a,a);
	return p;
}
//----------------------
int pi[N],su[N];
int check2(int mid){
	int i,la=0,tot=0;
	for(i=1;i<=n;i++){
		if(su[i]-su[la]>=mid){
			la=i;
			tot++;
		}
	}
	if(tot>=m) return 1;
	else return 0;
}
int work2(){//bi=ai+1
	int i;
	su[0]=0;
	for(i=1;i<=n;i++) su[i]=su[i-1]+pi[i];
	int l=1,r=1e9,mid,res=1;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check2(mid)){
			l=mid;
			res=l;
		}else r=mid;
	}
	return res;
}
//---------------------
int val[N];
int check3(int mid){
	int i,j,tot=0;
	for(i=n-1;i;i--){
		if(val[i]>=mid){
			tot++;
		}
	}
	if(tot>=m) return 1;
	j=n-1-tot;
	i=1;
	while(i<j){
		while(val[i]+val[j]<mid) i++;
		tot++;
		i++;
		j--;
	}
	if(tot>=m) return 1;
	else return 0;
}
int work3(){
	sort(val+1,val+n);
	int l=1,r=1e9,mid,res=1;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check3(mid)){
			l=mid;
			res=l;
		}else r=mid;
	}
	return res;
}
//-----------------
int vis[N],qu[M],cq;
int dfs(int v,int &ml,int mid){
	if(vis[v]){
		ml=0;return 0;
	}
	vis[v]=1;
	int qs;
	qs=cq;
	int mx=0,ans=0,p;
	for(p=ce[v];p;p=next[p]){
		if(vis[to[p]]) continue;
		if(len[p]>=mid){
			ans++;
			ans+=dfs(to[p],ml,mid);
			continue;
		}	
		ans+=dfs(to[p],ml,mid);
		qu[++cq]=len[p]+ml;
		if(qu[cq]>=mid){
			ans++;
			cq--;
		}
	}
	sort(qu+qs+1,qu+cq+1);
	int i,j=cq;
	i=qs+1;
	while(i<j){
		while(qu[i]+qu[j]<mid){
			mx=max(mx,qu[i]);
			i++;
		}
		ans++;
		i++;j--;
	}
	if(i==j) mx=max(mx,qu[i]);
	ml=mx;
	cq=qs;
	return ans;
}
int check4(int mid){
	memset(vis,0,sizeof(vis));
	int le,tot=0,i;
	for(i=1;i<=n;i++){
		if(vis[i]==0) tot+=dfs(i,le,mid);
	}
	if(tot>=m) return 1;
	else return 0;
}
int work4(){
	int ans=1;
	int l=1,r=1e9,mid;
	while(l<r-1){
		mid=(l+r)>>1;
		if(check4(mid)){
			l=mid;
			ans=l;
		}else r=mid;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(ce,0,sizeof(ce));
	cin>>n>>m;
	int ans,flag=1,i,a,b,l,fl2=1;
	if(m==1) ans=work1();
	else{
		for(i=1;i<n;i++){
			cin>>a>>b>>l;
			link(a,b,l);
			val[i]=pi[i]=l;
			if(b!=a+1) flag=0;
			if(a!=1) fl2=0;
		}
		if(flag) ans=work2();
		else if(fl2) ans=work3();
		else ans=work4();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

