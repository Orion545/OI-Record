#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define mp make_pair
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int siz[10000010],ch[10000010][2],root[300010],cnt;
void insert(int num,int pre,int k){
	int i,cur;root[k]=cur=++cnt;
	for(i=30;i>=0;i--){
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];siz[cur]=siz[pre]+1;
//		cout<<"insert "<<num<<' '<<cur<<' '<<pre<<' '<<i<<' '<<((num&(1<<i))>0)<<'\n';
		if(num&(1<<i)) ch[cur][1]=++cnt,cur=ch[cur][1],pre=ch[pre][1];
		else ch[cur][0]=++cnt,cur=ch[cur][0],pre=ch[pre][0];
	}
	siz[cur]=siz[pre]+1;
}
pair<int,int>q[1010];int x[1010];
void solve(int l,int r,int u,int v,int k){
	int i,j,ans=0,t0,t1;
	for(i=u;i<=v;i++) q[i]=mp(root[l-1],root[r]);
	for(j=30;j>=0;j--){
		t0=t1=0;
		for(i=u;i<=v;i++){
			if(x[i]&(1<<j)){
				t0+=siz[ch[q[i].second][1]]-siz[ch[q[i].first][1]];
				t1+=siz[ch[q[i].second][0]]-siz[ch[q[i].first][0]];
			}
			else{
				t1+=siz[ch[q[i].second][1]]-siz[ch[q[i].first][1]];
				t0+=siz[ch[q[i].second][0]]-siz[ch[q[i].first][0]];
			}
		}
//		cout<<"solve "<<k<<' '<<t0<<' '<<t1<<'\n';
		if(t1>=k){
			for(i=u;i<=v;i++){
				if(x[i]&(1<<j)) q[i]=mp(ch[q[i].first][0],ch[q[i].second][0]);
				else q[i]=mp(ch[q[i].first][1],ch[q[i].second][1]);
			}
			ans|=(1<<j);
		}
		else{
			for(i=u;i<=v;i++){
				if(x[i]&(1<<j)) q[i]=mp(ch[q[i].first][1],ch[q[i].second][1]);
				else q[i]=mp(ch[q[i].first][0],ch[q[i].second][0]);
			}
			k-=t1;
		}
	}
	printf("%d\n",ans);
}
int n,m,Q;
int main(){
	freopen("9.in","r",stdin);
	freopen("my.out","w",stdout);
	n=read();m=read();int i,t1,l,r,u,v,k;
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<=m;i++) t1=read(),insert(t1,root[i-1],i);
	Q=read();
	while(Q--){
		u=read();v=read();l=read();r=read();k=read();
		solve(l,r,u,v,k);
	}
}

