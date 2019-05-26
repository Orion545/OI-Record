#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ull unsigned long long
#define next DEEP_DARK_FANTASY
#define hash VAN_YOU_SEE
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct H{
	int first[1010],next[1010],siz[1010],cnt;
	ull val[1010];
	void clear(){
//		cout<<"clear\n";
		memset(first,-1,sizeof(first));cnt=0;
		memset(next,-1,sizeof(next));
	}
	void insert(ull w){
//		cout<<"insert "<<w<<' '<<w%1000<<'\n';
		int p=(w%1000ll),u;
		if(first[p]==-1){
			first[p]=++cnt;
			siz[cnt]=1;val[cnt]=w;
			return;
		}
		for(u=first[p];~u;u=next[u]){
			if(val[u]==w){
				siz[u]++;
				return;
			}
			if(next[u]==-1) break;
		}
		next[u]=++cnt;
		siz[cnt]=1;val[cnt]=w;
	}
	int query(ull w){
		int p=(w%1000ll);
//		cout<<"query "<<w<<'\n';
		for(int u=first[p];~u;u=next[u]){
//			cout<<"	get "<<u<<' '<<val[u]<<' '<<siz[u]<<'\n';
			if(val[u]==w) return siz[u];
		}
		return 0;
	}
}hash[310];
int n,a[100010],lis[100010],blk,tot;
int suf[100010],cur[1000010];
ull b[100010],s[100010],tag[100010];
int op(int num){return blk*(num-1)+1;}
int ed(int num){return min(n,blk*num);}
int id(int num){return num/blk+(num%blk!=0);}
void change(int now,int l,int r,ull val){
	int idl=id(l),idr=id(r),i;
//	cout<<"********change "<<l<<' '<<r<<' '<<idl<<' '<<idr<<' '<<val<<'\n';
	for(i=idl+1;i<=idr;i++) tag[i]^=val;

	if(l==op(idl)) tag[idl]^=val;
	else{
		hash[idl].clear();
		for(i=l;i<=ed(idl);i++) s[i]^=val;
		for(i=max(now,op(idl));i<=ed(idl);i++) hash[idl].insert(s[i]);
	}

}
int main(){
	srand(19260817);
	n=read();int i,j;ull ans=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		lis[++lis[0]]=a[i];
	}
	for(i=n;i>=1;i--){
		suf[i]=cur[a[i]];
		cur[a[i]]=i;
	}

	sort(lis+1,lis+lis[0]+1);
	lis[0]=unique(lis+1,lis+lis[0]+1)-lis-1;
	for(i=1;i<=lis[0];i++) b[i]=(ull)rand()*(ull)rand();
	for(i=1;i<=n;i++) a[i]=lower_bound(lis+1,lis+lis[0]+1,a[i])-lis;
	blk=sqrt(n);tot=n/blk+(n%blk!=0);
	for(i=1;i<=tot;i++) hash[i].clear();
	
//	cout<<"check pre\n";
//	for(i=1;i<=n;i++) cout<<i<<' '<<a[i]<<' '<<suf[i]<<' '<<b[a[i]]<<'\n';
//	cout<<"block siz "<<blk<<", tot block "<<tot<<'\n';
	
	for(i=n;i>=1;i--){
//		cout<<"****************begin do "<<i<<' '<<ans<<'\n';
		hash[id(i)].insert(s[i]);
		if(suf[i]) change(i,suf[i],n,b[a[i]]);
		for(j=1;j<=tot;j++) ans+=hash[j].query(tag[j]);
	}
	cout<<ans<<'\n';
}
