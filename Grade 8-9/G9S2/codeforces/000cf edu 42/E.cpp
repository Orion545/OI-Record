#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 2000000007
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
int n,x[200010],p[200010],b[200010],r[200010],a[200010];
int main(){
	int i,j,cntp=0,cntb=0,cntr=0,ans=0;char s[10];
	n=read();
	for(i=1;i<=n;i++){
		scanf("%d",&x[i]);scanf("%s",s);
//		cout<<x[i]<<ends<<s[0]<<endl;
		if(s[0]=='P') p[++cntp]=i,a[i]=0;
		if(s[0]=='B') b[++cntb]=i,a[i]=1;
		if(s[0]=='R') r[++cntr]=i,a[i]=-1;
	}
	if(!cntp){
		for(i=1;i<cntb;i++) ans+=x[b[i+1]]-x[b[i]];
		for(i=1;i<cntr;i++) ans+=x[r[i+1]]-x[r[i]];
		cout<<ans<<endl;return 0;
	}
	if(!cntb||!cntr){
		cout<<x[n]-x[1]<<endl;return 0;
	}
	if(cntb&&b[1]<p[1]) ans+=(x[p[1]]-x[b[1]]);
	if(cntr&&r[1]<p[1]) ans+=(x[p[1]]-x[r[1]]);
//	cout<<"before "<<ans<<endl;
	for(i=1;i<cntp;i++){
		j=i+1;int fb=0,fr=0,tbl=inf,tbr=inf,trl=inf,trr=inf,tb=0,tr=0,mb=inf,mr=inf;
		for(;j<p[i+1];j++){
			if(a[j]==1) 
				fb=1,tbl=min(tbl,x[j]-x[p[i]]),tbr=min(tbr,x[p[i+1]]-x[j]);
			if(a[j]==-1)
				fr=1,trl=min(trl,x[j]-x[p[i]]),tbr=min(trr,x[p[i+1]]-x[j]);
		}
		for(j=i+1;j<=p[i+1];j++){
			if(a[j]==1){
				if(!tb) tb=j;
				else{
					mb=min(mb,x[j]-x[tb]);tb=j;
				}
			}
			if(a[j]==-1){
				if(!tr) tr=j;
				else{
					mr=min(mr,x[j]-x[tr]);tr=j;
				}
			}
		}
		if(mb==inf) mb=0;
		if(mr==inf);mr=0;
		if(fb&&fr) ans+=2*(x[p[i+1]]-x[p[i]]);
		if(fb&&!fr) ans+=2*(x[p[i+1]]-x[p[i]])-max(tbl,max(tbr,mb));
		if(!fb&&fr) ans+=2*(x[p[i+1]]-x[p[i]])-max(trl,max(trr,mr));
		if(!fb&&!fr) ans+=(x[p[i+1]]-x[p[i]]);
	}
	if(cntb&&b[cntb]>p[cntp]) ans+=(x[b[cntb]]-x[p[cntp]]);
	if(cntr&&r[cntr]>p[cntp]) ans+=(x[r[cntr]]-x[p[cntp]]);
	cout<<ans;
	return 0;
}
