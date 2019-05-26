#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ull unsigned long long
using namespace std;
inline long long read(){
	long long re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,k,ch[10];
ull ans;
namespace A{
	ull a[64];
	void insert(ull x){
		for(int i=63;i>=0;i--){
			if(x&(1ull<<i)){
				if(a[i]) x=x^a[i];
				else{
					m=max(m,i);
					a[i]=x;break;
				}
			}
		}
	}
}
namespace B{
	int a[64],ans;
	void clear(){
		ans=1;
		memset(a,0,sizeof(a));
	}
	void insert(int x){
		for(int i=k-1;i>=0;i--){
			if(x&(1<<i)){
				if(a[i]) x=x^a[i];
				else{
					ans--;
					a[i]=x;break;
				}
			}
		}
	}
}
void dfs(int x){
	if(x==k){
		int cnt,i,j;B::clear();
		for(i=0;i<=m;i++){
			if(A::a[i]){
				cnt=0;
				for(j=0;j<k;j++)
					cnt|=((A::a[i]&(1ull<<ch[j]))>0)<<j;
				B::insert(cnt);
			}
		}
		cnt=(1<<k)-1;
		for(i=0;i<k;i++) B::ans+=ch[i];
		for(i=k-1;i>=0;i--) if(cnt&(1<<i)) cnt^=B::a[i];
		if(!cnt) ans+=(1ull<<B::ans);
		return;
	}
	for(int i=0;i<=m;i++) ch[x]=i,dfs(x+1);
}
int main(){
	n=read();k=read();int i;long long tmp;
	for(i=1;i<=n;i++){
		tmp=read();
		A::insert(tmp);		
	} 
	dfs(0);
	cout<<(ans>>1);
	if(ans&1) puts(".5");
}
