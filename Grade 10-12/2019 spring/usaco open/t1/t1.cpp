#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#define MOD 1000000007
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
inline void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int n,m;ll r[300010][20],d[300010][20];
unordered_map<int,int>mp;int tot[2];
ll minn[2][400010];ll num[2][400010],st[2][400010];
int cur=0,pre=1;
inline void insert(int s,ll val,int cnt){
	if(!mp[s]){
		mp[s]=++tot[cur];
		minn[cur][tot[cur]]=1e16;
		st[cur][tot[cur]]=s;
	}
	int pos=mp[s];
//	cout<<"	insert "<<s<<' '<<pos<<' '<<val<<' '<<cnt<<'\n';
//	if(s==0) cout<<"											******\n";
	if(minn[cur][pos]>val) minn[cur][pos]=val,num[cur][pos]=cnt;
	else if(minn[cur][pos]==val) add(num[cur][pos],cnt);
}
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	n=read();m=read();int i,j,k,s,s1,s2,p,tmp,lim;
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++) r[i][j]=read();
	}
	for(i=1;i<=m;i++){
		for(j=1;j<n;j++) d[j][i]=read();
	}
	minn[cur][1]=0;num[cur][1]=1;
	mp[0]=1;tot[cur]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=tot[cur];j++) st[cur][j]<<=3;
		for(j=1;j<=m;j++){
			swap(pre,cur);
			tot[cur]=0;mp.clear();
//			cout<<"check tot "<<i<<' '<<j<<' '<<tot[pre]<<'\n';
			for(k=1;k<=tot[pre];k++){
				//current state evolves from st[pre][k]
				s=st[pre][k];
				s1=((s>>(3*j-3))&7);
				s2=((s>>(3*j))&7);
//				cout<<"available "<<i<<' '<<j<<' '<<k<<' '<<s<<' '<<minn[pre][k]<<' '<<num[pre][k]<<' '<<s1<<' '<<s2<<' '<<(s>>(3*j-3))<<' '<<(s>>(3*j))<<'\n';
				if(s1==0&&s2==0){
					tmp=0;
					for(p=0;p<=m;p++) tmp=max(tmp,(s>>(3*p))&7);
					tmp++;
					if(i<n&&j<m) insert(s|(tmp<<(3*j-3))|(tmp<<(3*j)),minn[pre][k],num[pre][k]);
					if(i<n) insert(s|(tmp<<(3*j-3)),minn[pre][k],num[pre][k]);
					if(j<m) insert(s|(tmp<<(3*j)),minn[pre][k],num[pre][k]);
				}
				if(s1==0&&s2!=0){
					if(i<n&&j<m) insert(s|(s2<<(3*j-3)),minn[pre][k]+d[i-1][j],num[pre][k]);
					if(i<n) insert((s^(s2<<(3*j)))|(s2<<(3*j-3)),minn[pre][k]+d[i-1][j],num[pre][k]);
					if(j<m) insert(s,minn[pre][k]+d[i-1][j],num[pre][k]);
					tmp=0;
					for(p=0;p<=m;p++){
						if(((s>>(3*p))&7)==s2) tmp++;
//						lim=max(lim,((s>>(3*p))&7));
					}
					if((i==n&&j==m)||tmp>1) insert(s^(s2<<(3*j)),minn[pre][k]+d[i-1][j],num[pre][k]);
				}
				if(s2==0&&s1!=0){
					if(i<n&&j<m) insert(s|(s1<<(3*j)),minn[pre][k]+r[i][j-1],num[pre][k]);
					if(i<n) insert(s,minn[pre][k]+r[i][j-1],num[pre][k]);
					if(j<m) insert((s^(s1<<(3*j-3)))|(s1<<(3*j)),minn[pre][k]+r[i][j-1],num[pre][k]);
					tmp=0;
					for(p=0;p<=m;p++){
						if(((s>>(3*p))&7)==s1) tmp++;
					}
					if((i==n&&j==m)||tmp>1) insert(s^(s1<<(3*j-3)),minn[pre][k]+r[i][j-1],num[pre][k]);
				}
				if(s1!=0&&s2!=0&&s1!=s2){
					tmp=max(s1,s2);
					for(p=0;p<=m;p++){
//						cout<<"			****reset combining type "<<s1<<' '<<s2<<' '<<tmp<<' '<<p<<' '<<((s>>(3*p))&7)<<'\n';
						if(((s>>(3*p))&7)==tmp){
							s^=(tmp<<(3*p));
							s|=((min(s1,s2))<<(3*p));
						}
						if(((s>>(3*p))&7)>tmp){
							s-=(1<<(3*p));
						}
					}
					tmp=min(s1,s2);
//					cout<<"			finish reset "<<s<<' '<<tmp<<'\n';
					if(i<n&&j<m) insert(s,minn[pre][k]+d[i-1][j]+r[i][j-1],num[pre][k]);
					if(i<n) insert(s^(tmp<<(3*j)),minn[pre][k]+d[i-1][j]+r[i][j-1],num[pre][k]);
					if(j<m) insert(s^(tmp<<(3*j-3)),minn[pre][k]+d[i-1][j]+r[i][j-1],num[pre][k]);
					lim=0;
					for(p=0;p<=m;p++){
						if(((s>>(3*p))&7)==tmp||((s>>(3*p))&7)==tmp) lim++;
					}
					if((i==n&&j==m)||lim>2) insert((s^(tmp<<(3*j)))^(tmp<<(3*j-3)),minn[pre][k]+d[i-1][j]+r[i][j-1],num[pre][k]);
				}
				if(s1!=0&&s2!=0&&s1==s2) continue;
			}
		}
	}
//	cout<<minn[cur][mp[0]]<<' '<<num[cur][mp[0]]<<'\n';
	cout<<num[cur][mp[0]]<<'\n';
}
