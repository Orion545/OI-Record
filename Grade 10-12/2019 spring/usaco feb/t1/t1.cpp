#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n;long double p[2000010],pre[2000010];
int main(){
	freopen("cowdate.in","r",stdin);
	freopen("cowdate.out","w",stdout); 
	n=read();int i,j;long double tmp,cur,ans=-1.0;int st=1;
	if(n<=4000){
	pre[0]=1;
	for(i=1;i<=n;i++){
		tmp=read();
		tmp/=1000000.0f;
		p[i]=tmp;
		ans=max(ans,p[i]);
		pre[i]=pre[i-1]*(1.0f-p[i]);
	}
	if(ans>0.5){
		cout<<floor(ans*1000000.0f)<<'\n';
		return 0;
	}
	for(i=1;i<=n;i++){
		cur=p[i];
//		cout<<"begin "<<i<<' '<<st<<' '<<cur<<'\n';
		for(j=i+1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<p[j]<<' '<<cur<<' '<<pre[j-1]/pre[i-1]<<' '<<cur*(1.0-p[j])<<' '<<p[j]*(pre[j-1]/pre[i-1])<<'\n';
			cur=cur*(1.0f-p[j])+p[j]*(pre[j-1]/pre[i-1]);
			ans=max(ans,cur);
		}
	}
	cout<<floor(ans*1000000.0f)<<'\n';
	}
	if(n>4000){
	pre[0]=1;
	for(i=1;i<=n;i++){
		tmp=read();
		tmp/=1000000.0f;
		p[i]=tmp;
		ans=max(ans,p[i]);
		pre[i]=pre[i-1]*(1.0f-p[i]);
	}
	if(ans>0.5){
		cout<<floor(ans*1000000.0f)<<'\n';
		return 0;
	}
	for(i=1;i<=n;i++){
		if(st<=i) cur=p[i],st=i;
		else cur=(cur-p[i-1]*(pre[st]/pre[i-1]))/(1-p[i-1]);
//		cout<<"begin "<<i<<' '<<st<<' '<<cur<<'\n';
		for(j=st+1;j<=n;j++){
			if(cur>(pre[j-1]/pre[i-1])){
				st=j-1;break;
			}
			if(1e-5>(pre[j-1]/pre[i-1])){
				break;
			}
//			cout<<i<<' '<<j<<' '<<p[j]<<' '<<cur<<' '<<pre[j-1]/pre[i-1]<<' '<<cur*(1.0-p[j])<<' '<<p[j]*(pre[j-1]/pre[i-1])<<'\n';
			cur=cur*(1.0f-p[j])+p[j]*(pre[j-1]/pre[i-1]);
			ans=max(ans,cur);
		}
	}
	cout<<floor(ans*1000000.0f)<<'\n';
	}
}
