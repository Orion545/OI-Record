#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
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
bool vis[10000010];int pri[1000010],cntp,db[2000010];
int tmpcnt;
void init(){
	int i,j,k,len=10000000;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(!vis[i]) db[++tmpcnt]=k;
			if(i%pri[j]==0) break;
		}
	}
}
int n,a[100010];
int f[100010];
vector<int>s;
int find(int x){return ((f[x]<0)?x:f[x]=find(f[x]));}
int main(){
	init();
	int T=read();
	while(T--){
		n=read();int i,j,k,maxn=0,ans=1e9;
		for(i=1;i<=n;i++) a[i]=read(),maxn=max(maxn,a[i]);
		for(j=1;j<=n;j++){
			for(i=1;i<=n;i++) f[i]=-1;
			for(k=1;k<=tmpcnt;k++){
				if(db[k]>maxn) continue;
				s.clear();
				for(i=1;i<=n;i++){
					if(i==j) continue;
					if(a[i]%db[k]==0) s.push_back(i);
				}
//				cout<<"	solve "<<j<<' '<<db[k]<<' '<<s.size()<<'\n';
				for(i=1;i<s.size();i++){
					if(find(s[0])!=find(s[i])){
						f[find(s[0])]+=f[find(s[i])];
						f[find(s[i])]=find(s[0]);
					}
				}
			}
			int tans=0;
			for(i=1;i<=n;i++){
				if(i==j) continue;
				if(f[i]<0) tans=max(tans,-f[i]);
			}
//			cout<<"do "<<j<<' '<<tans<<'\n';
			ans=min(ans,tans);
		}
		cout<<ans<<'\n';
	}
}
